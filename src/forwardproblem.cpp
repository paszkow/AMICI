#include "amici/cblas.h"
#include "amici/model.h"
#include "amici/forwardproblem.h"
#include "amici/solver.h"
#include "amici/exception.h"
#include "amici/edata.h"
#include "amici/rdata.h"
#include "amici/steadystateproblem.h"

#include <cvodes/cvodes.h> // return/option codes

#include <cmath>
#include <cstring>

namespace amici {

// Ensure AMICI options are in sync with Sundials options
static_assert(InternalSensitivityMethod::SIMULTANEOUS == CV_SIMULTANEOUS, "");
static_assert(InternalSensitivityMethod::STAGGERED == CV_STAGGERED, "");
static_assert(InternalSensitivityMethod::STAGGERED1 == CV_STAGGERED1, "");

static_assert(InterpolationType::HERMITE == CV_HERMITE, "");
static_assert(InterpolationType::POLYNOMIAL == CV_POLYNOMIAL, "");

static_assert(LinearMultistepMethod::ADAMS == CV_ADAMS, "");
static_assert(LinearMultistepMethod::BDF == CV_BDF, "");

static_assert(AMICI_ROOT_RETURN == CV_ROOT_RETURN, "");
    
static_assert(NonlinearSolverIteration::FUNCTIONAL == CV_FUNCTIONAL, "");
static_assert(NonlinearSolverIteration::NEWTON == CV_NEWTON, "");

extern msgIdAndTxtFp warnMsgIdAndTxt;

/**
  * Constructor
  * @param rdata pointer to ReturnData instance
  * @param edata pointer to ExpData instance
  * @param model pointer to Model instance
  * @param solver pointer to Solver instance
  */
ForwardProblem::ForwardProblem(ReturnData *rdata, const ExpData *edata,
                               Model *model, Solver *solver)
    : model(model),
      rdata(rdata),
      solver(solver),
      edata(edata),
      rootidx(static_cast<decltype (rootidx)::size_type>(model->ne * model->ne * rdata->nmaxevent), 0),
      nroots(static_cast<decltype (nroots)::size_type>(model->ne), 0),
      rootvals(static_cast<decltype (rootvals)::size_type>(model->ne), 0.0),
      rvaltmp(static_cast<decltype (rvaltmp)::size_type>(model->ne), 0.0),
      discs(static_cast<decltype (discs)::size_type>(rdata->nmaxevent * model->ne), 0.0),
      irdiscs(rdata->nmaxevent * model->ne, 0.0),
      x_disc(model->nx,model->nMaxEvent()*model->ne),
      xdot_disc(model->nx,model->nMaxEvent()*model->ne),
      xdot_old_disc(model->nx,model->nMaxEvent()*model->ne),
      dJydx(model->nJ * model->nx * model->nt(), 0.0),
      dJzdx(model->nJ * model->nx * model->nMaxEvent(), 0.0),
      t(model->t0()),
      rootsfound(model->ne, 0),
      Jtmp(NewDenseMat(model->nx,model->nx)),
      x(model->nx),
      x_old(model->nx),
      dx(model->nx),
      dx_old(model->nx),
      xdot(model->nx),
      xdot_old(model->nx),
      sx(model->nx,model->nplist()),
      sdx(model->nx,model->nplist())
{
}

/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */

void ForwardProblem::workForwardProblem() {
    /**
     * workForwardProblem solves the forward problem. if forward sensitivities
     * are enabled this will also compute sensitivies
     */

    try {
        solver->setupAMI(this, model);
    } catch (std::exception& ex) {
        throw AmiException("AMICI setup failed:\n(%s)",ex.what());
    } catch (...) {
        throw AmiException("AMICI setup failed due to an unknown error");
    }

    if(edata){
        rdata->initializeObjectiveFunction();
    }
    
    /* if preequilibration is necessary, start Newton solver */
    if (solver->getNewtonPreequilibration() || (edata && !edata->fixedParametersPreequilibration.empty())) {
        handlePreequilibration();
    } else {
        rdata->x0 = x.getVector();
        if (rdata->sensi_meth == AMICI_SENSI_FSA &&
                rdata->sensi >= AMICI_SENSI_ORDER_FIRST) {
            for (int ix = 0; ix < model->nx; ix++) {
                for (int ip = 0; ip < model->nplist(); ip++)
                    rdata->sx0[ip*model->nx + ix] = sx.at(ix,ip);
            }
        }
    }

    int ncheck = 0; /* the number of (internal) checkpoints stored so far */

    /* loop over timepoints */
    for (int it = 0; it < rdata->nt; it++) {
        auto nextTimepoint = rdata->ts[it];

        if (rdata->sensi_meth == AMICI_SENSI_FSA &&
            rdata->sensi >= AMICI_SENSI_ORDER_FIRST) {
            solver->AMISetStopTime(nextTimepoint);
        }

        if (nextTimepoint > model->t0()) {
            while (t < nextTimepoint) {
                if (model->nx == 0) {
                    t = nextTimepoint;
                    continue;
                }

                if (std::isinf(nextTimepoint)) {
                    SteadystateProblem sstate = SteadystateProblem(&t,&x,&sx);
                    sstate.workSteadyStateProblem(rdata, solver, model, it);
                } else {
                    int status;
                    if (rdata->sensi_meth == AMICI_SENSI_ASA &&
                            rdata->sensi >= AMICI_SENSI_ORDER_FIRST) {
                        status = solver->AMISolveF(RCONST(nextTimepoint), &x, &dx,
                                                   &(t), AMICI_NORMAL, &ncheck);
                    } else {
                        status = solver->AMISolve(RCONST(nextTimepoint), &x, &dx,
                                                  &(t), AMICI_NORMAL);
                    }

                    if (status == AMICI_ILL_INPUT) {
                        /* clustering of roots => turn off rootfinding */
                        solver->turnOffRootFinding();
                    } else if (status == AMICI_ROOT_RETURN) {
                        handleEvent(&tlastroot, false);
                    }
                }
            }
        }
        handleDataPoint(it);
    }

    /* fill events */
    if (model->nz > 0) {
        getEventOutput();
    }

    // set likelihood
    if (!edata) {
        rdata->invalidateLLH();
    }

    storeJacobianAndDerivativeInReturnData();
}

void ForwardProblem::handlePreequilibration()
{
    // Are there dedicated condition preequilibration parameters provided?
    bool overrideFixedParameters = edata && !edata->fixedParametersPreequilibration.empty();

    std::vector<realtype> originalFixedParameters; // to restore after pre-equilibration

    if(overrideFixedParameters) {
        if(edata->fixedParametersPreequilibration.size() != (unsigned) model->nk())
            throw AmiException("Number of fixed parameters (%d) in model does not match preequilibration parameters in ExpData (%zd).",
                               model->nk(), edata->fixedParametersPreequilibration.size());
        originalFixedParameters = model->getFixedParameters();
        model->setFixedParameters(edata->fixedParametersPreequilibration);
    }

    // pre-equilibrate
    SteadystateProblem sstate = SteadystateProblem(&t,&x,&sx);
    sstate.workSteadyStateProblem(rdata, solver, model, -1);

    if(overrideFixedParameters) { // Restore
        model->setFixedParameters(originalFixedParameters);
    }
}

/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */

void ForwardProblem::handleEvent(realtype *tlastroot, const bool seflag) {
    /**
     * handleEvent executes everything necessary for the handling of events
     *
     * @param[out] tlastroot pointer to the timepoint of the last event 
     */

    /* store heaviside information at event occurence */
    model->froot(t, &x, &dx, rootvals.data());
    
    if (!seflag) {
        solver->AMIGetRootInfo(rootsfound.data());
    }

    if (iroot < rdata->nmaxevent * model->ne) {
        std::copy(rootsfound.begin(), rootsfound.end(), &rootidx[iroot * model->ne]);
    }

    rvaltmp = rootvals;

    if (!seflag) {
        /* only extract in the first event fired */
        if (rdata->sensi >= AMICI_SENSI_ORDER_FIRST &&
            rdata->sensi_meth == AMICI_SENSI_FSA) {
            solver->AMIGetSens(&(t), &sx);
        }

        /* only check this in the first event fired, otherwise this will always
         * be true */
        if (t == *tlastroot) {
            throw AmiException("AMICI is stuck in an event, as the initial"
                               "step-size after the event is too small. To fix "
                               "this, increase absolute and relative tolerances!");
        }
        *tlastroot = t;
    }
    
    if(model->nz>0)
        getEventOutput();

    /* if we need to do forward sensitivities later on we need to store the old
     * x and the old xdot */
    if (rdata->sensi >= AMICI_SENSI_ORDER_FIRST) {
        /* store x and xdot to compute jump in sensitivities */
        x_old = x;
        if (rdata->sensi_meth == AMICI_SENSI_FSA) {
            model->fxdot(t, &x, &dx, &xdot);
            xdot_old = xdot;
            dx_old = dx;

            /* compute event-time derivative only for primary events, we get
             * into trouble with multiple simultaneously firing events here (but
             * is this really well defined then?), in that case just use the
             * last ie and hope for the best. */
            if (!seflag) {
                for (int ie = 0; ie < model->ne; ie++) {
                    if (rootsfound.at(ie) == 1) {
                        /* only consider transitions false -> true */
                        model->fstau(t, ie, &x, &sx);
                    }
                }
            }
        } else if (rdata->sensi_meth == AMICI_SENSI_ASA) {
            /* store x to compute jump in discontinuity */
            if (iroot < rdata->nmaxevent * model->ne) {
                x_disc[iroot] = x;
                xdot_disc[iroot] = xdot;
                xdot_old_disc[iroot] = xdot_old;
            }
        }
    }

    model->updateHeaviside(rootsfound);

    applyEventBolus();

    if (iroot < rdata->nmaxevent * model->ne) {
        discs[iroot] = t;
        ++iroot;
    } else {
        warnMsgIdAndTxt("AMICI:mex:TOO_MUCH_EVENT",
                        "Event was recorded but not reported as the number of "
                        "occured events exceeded (nmaxevents)*(number of "
                        "events in model definition)!");
        solver->AMIReInit(t, &x, &dx); /* reinitialise so that we can continue in peace */
        return;
    }

    if (rdata->sensi >= AMICI_SENSI_ORDER_FIRST
            && rdata->sensi_meth == AMICI_SENSI_FSA) {
        /* compute the new xdot  */
        model->fxdot(t, &x, &dx, &xdot);
        applyEventSensiBolusFSA();
    }

    int secondevent = 0;

    /* check whether we need to fire a secondary event */
    model->froot(t, &x, &dx, rootvals.data());
    for (int ie = 0; ie < model->ne; ie++) {
        /* the same event should not trigger itself */
        if (rootsfound.at(ie) == 0) {
            /* check whether there was a zero-crossing */
            if (0 > rvaltmp.at(ie) * rootvals.at(ie)) {
                if (rvaltmp.at(ie) < rootvals.at(ie)) {
                    rootsfound.at(ie) = 1;
                } else {
                    rootsfound.at(ie) = -1;
                }
                secondevent++;
            } else {
                rootsfound.at(ie) = 0;
            }
        } else {
            /* don't fire the same event again */
            rootsfound.at(ie) = 0;
        }
    }
    /* fire the secondary event */
    if (secondevent > 0) {
        handleEvent(tlastroot, TRUE);
    }

    /* only reinitialise in the first event fired */
    if (!seflag) {
        solver->AMIReInit(t, &x, &dx);

        /* make time derivative consistent */
        solver->AMICalcIC(t, &x, &dx);

        if (rdata->sensi >= AMICI_SENSI_ORDER_FIRST) {
            if (rdata->sensi_meth == AMICI_SENSI_FSA) {
                solver->AMISensReInit(solver->getInternalSensitivityMethod(), &sx, &sdx);
            }
        }
    }
}

void ForwardProblem::storeJacobianAndDerivativeInReturnData() {
    /**
     * evaluates the Jacobian and differential equation right hand side, stores it
     * in rdata 
     */

    model->fxdot(t, &x, &dx, &xdot);
    rdata->xdot = xdot.getVector();

    model->fJ(t, 0.0, &x, &dx, &xdot, Jtmp);
    // CVODES uses colmajor, so we need to transform to rowmajor
    for (int ix = 0; ix < model->nx; ix++) {
        for (int jx = 0; jx < model->nx; jx++) {
            rdata->J[ix*model->nx + jx] = Jtmp->data[ix + model->nx*jx];
        }
    }
}

void ForwardProblem::getEventOutput() {
    /**
     * getEventOutput extracts output information for events
     */

    if (t == model->gett(rdata->nt - 1,rdata)) {
        // call from fillEvent at last timepoint
        model->froot(t, &x, &dx, rootvals.data());
    }

    /* EVENT OUTPUT */
    for (int ie = 0; ie < model->ne; ie++) {
        /* only look for roots of the rootfunction not discontinuities */
        if (nroots.at(ie) >= rdata->nmaxevent)
            continue;

        /* only consider transitions false -> true or event filling */
        if (rootsfound.at(ie) != 1 && t != model->gett(rdata->nt - 1, rdata)) {
            continue;
        }

        model->fz(nroots.at(ie), ie, t, &x, rdata);

        if (edata) {
            model->fsigmaz(t, ie, nroots.data(), edata, rdata);
            model->fJz(nroots.at(ie), rdata, edata);

            if (t == model->gett(rdata->nt - 1,rdata)) {
                // call from fillEvent at last
                // timepoint, add regularization
                // based on rz
                model->frz(nroots.at(ie), ie, t, &x, rdata);
                model->fJrz(nroots.at(ie), rdata, edata);
            }
        }

        if (rdata->sensi >= AMICI_SENSI_ORDER_FIRST) {
            prepEventSensis(ie);
            if (rdata->sensi_meth == AMICI_SENSI_FSA) {
                getEventSensisFSA(ie);
            }
        }

        nroots.at(ie)++;
    }

    if (t == model->gett(rdata->nt - 1, rdata)) {
        // call from fillEvent at last timepoint
        // loop until all events are filled
        if(std::any_of(nroots.cbegin(), nroots.cend(), [&](int curNRoots){ return curNRoots < rdata->nmaxevent; }))
            getEventOutput();
    }
}

/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */

void ForwardProblem::prepEventSensis(int ie) {
    /**
     * prepEventSensis preprocesses the provided experimental data to compute
     * event sensitivities via adjoint or forward methods later on
     *
     * @param[in] ie index of current event @type int
     */

    if(!edata)
        return;

    for (int iz = 0; iz < model->nztrue; iz++) {
        if(model->z2event[iz] - 1 != ie)
            continue;

        if (isNaN(edata->mz[nroots.at(ie) * rdata->nztrue + iz]))
            continue;

        model->fdzdp(t, ie, &x);

        model->fdzdx(t, ie, &x);

        if (t == model->gett(rdata->nt - 1,rdata)) {
            model->fdrzdp(t, ie, &x);
            model->fdrzdx(t, ie, &x);
        }
        /* extract the value for the standard deviation, if the data
           value is NaN, use the parameter value. Store this value in the return
           struct */
        if (isNaN(edata->sigmaz[nroots.at(ie) * rdata->nztrue + iz])) {
            model->fdsigmazdp(t);
        } else {
            for (int ip = 0; ip < model->nplist(); ip++) {
                model->dsigmazdp[iz + model->nz * ip] = 0;
            }
            model->sigmaz[iz] =
                    edata->sigmaz[nroots.at(ie) * model->nztrue + iz];
        }
        rdata->sigmaz[nroots.at(ie) * model->nz + iz] = model->sigmaz[iz];
        for (int ip = 0; ip < model->nplist(); ip++) {
            rdata->ssigmaz[(nroots.at(ie)*model->np()+ip) * model->nz + iz] =
                    model->dsigmazdp[iz + model->nz * ip];
        }
    }
    model->fdJzdz(nroots.at(ie), rdata, edata);
    model->fdJzdsigma(nroots.at(ie), rdata, edata);

    if (t == rdata->ts[rdata->nt - 1]) {
        model->fdJrzdz(nroots.at(ie), rdata, edata);
        model->fdJrzdsigma(nroots.at(ie), rdata, edata);
    }

    model->fdJzdx(&dJzdx, nroots.at(ie), t, edata, rdata);
    model->fdJzdp(nroots.at(ie), t, edata, rdata);

    if (rdata->sensi_meth == AMICI_SENSI_ASA && model->nz > 0) {
        amici_daxpy(model->nplist(), -1.0, model->dJzdp.data(), 1, rdata->sllh.data(), 1);
        amici_daxpy(model->nplist(), -1.0, &model->dJzdp[1], model->nJ, rdata->s2llh.data(), model->nJ - 1);
    }

}

void ForwardProblem::getEventSensisFSA(int ie) {
    /**
     * getEventSensisFSA extracts event information for forward sensitivity
     * analysis
     *
     * @param[in] ie index of event type @type int
     */
    if (t == rdata->ts[rdata->nt - 1]) {
        // call from fillEvent at last timepoint
        model->fsz_tf(nroots.data(),ie, rdata);
        model->fsrz(nroots.at(ie),ie,t,&x,&sx,rdata);
    } else {
        model->fsz(nroots.at(ie),ie,t,&x,&sx,rdata);
    }

    if (edata) {
        model->fsJz(nroots.at(ie),dJzdx,&sx,rdata);
    }
}

void ForwardProblem::handleDataPoint(int it) {
    /**
     * handleDataPoint executes everything necessary for the handling of data
     * points
     *
     * @param[in] it index of data point @type int
     */

    std::copy_n(x.data(), model->nx, &rdata->x.at(it*model->nx));
    
    if (rdata->ts[it] > model->t0()) {
        solver->getDiagnosis(it, rdata);
    }
    
    getDataOutput(it);
}

void ForwardProblem::getDataOutput(int it) {
    /**
     * getDataOutput extracts output information for data-points
     *
     * @param[in] it index of current timepoint @type int
     */

    model->fy(it, rdata);
    model->fsigmay(it, edata, rdata);
    model->fJy(it, rdata, edata);
    model->fres(it, rdata, edata);
    model->fchi2(it, rdata);
    
    if (rdata->sensi >= AMICI_SENSI_ORDER_FIRST && model->nplist() > 0) {
        prepDataSensis(it);
        if (rdata->sensi_meth == AMICI_SENSI_FSA) {
            getDataSensisFSA(it);
        }
    }
}

void ForwardProblem::prepDataSensis(int it) {
    /**
     * prepDataSensis preprocesses the provided experimental data to compute
     * sensitivities via adjoint or forward methods later on
     *
     * @param[in] it index of current timepoint @type int
     */

    model->fdydx(it, rdata);
    model->fdydp(it, rdata);

    if (!edata)
        return;

    model->fdsigmaydp(it, rdata, edata);
    model->fdJydy(it, rdata, edata);
    model->fdJydsigma(it, rdata, edata);
    model->fdJydx(&dJydx, it, edata, rdata);
    model->fdJydp(it, edata, rdata);
}

void ForwardProblem::getDataSensisFSA(int it) {
    /**
     * getDataSensisFSA extracts data information for forward sensitivity
     * analysis
     *
     * @param[in] it index of current timepoint @type int
     */

    if (!std::isinf(rdata->ts[it]) && rdata->ts[it] > model->t0()) {
        solver->AMIGetSens(&(t), &sx);
    }
    
    for (int ix = 0; ix < model->nx; ix++) {
        for (int ip = 0; ip < model->nplist(); ip++) {
            rdata->sx[(it * model->nplist() + ip) * rdata->nx + ix] =
                    sx.at(ix,ip);
        }
    }

    if(edata) {
        for (int iy = 0; iy < model->nytrue; iy++) {
            if (isNaN(edata->sigmay[it * rdata->nytrue + iy])) {
                // TODO: it seems redundant to call this for every iy,
                // should be only called once per it. Check with redundancy
                // in prepDataSensis and Model::fdsigmaydp
                model->fdsigmaydp(it, rdata, edata);
            } else {
                for (int ip = 0; ip < model->nplist(); ip++) {
                    model->dsigmaydp[ip * model->ny + iy] = 0;
                }
            }
            for (int ip = 0; ip < model->nplist(); ip++) {
                rdata->ssigmay[(it * model->nplist() + ip) * model->ny + iy] =
                        model->dsigmaydp[ip * model->ny + iy];
            }
        }
    } else {
        std::fill_n(&rdata->ssigmay[it * model->nplist() * model->ny], model->nytrue * model->nplist(), 0.0);
    }

    if (model->ny > 0) {
        model->fsy(it, rdata);
        if (edata) {
            model->fsJy(it, dJydx, rdata);
            model->fsres(it, rdata, edata);
            model->fFIM(it, rdata);
        }
    }
}

void ForwardProblem::applyEventBolus() {
    /**
     * applyEventBolus applies the event bolus to the current state
     *
     * @param[in] model pointer to model specification object @type Model
     */

    for (int ie = 0; ie < model->ne; ie++) {
        if (rootsfound.at(ie) == 1) {
            /* only consider transitions false -> true */
            model->fdeltax(ie, t, &x, &xdot, &xdot_old);

            amici_daxpy(model->nx, 1.0, model->deltax.data(), 1, x.data(), 1);
        }
    }
}

void ForwardProblem::applyEventSensiBolusFSA() {
    /**
     * applyEventSensiBolusFSA applies the event bolus to the current
     * sensitivities
     */
    for (int ie = 0; ie < model->ne; ie++) {
        if (rootsfound.at(ie) == 1) {
            /* only consider transitions false -> true */
            model->fdeltasx(ie, t, &x_old, &sx, &xdot, &xdot_old);

            for (int ip = 0; ip < model->nplist(); ip++) {
                amici_daxpy(model->nx, 1.0, &model->deltasx[model->nx * ip], 1, sx.data(ip), 1);
            }
        }
    }
}

} // namespace amici
