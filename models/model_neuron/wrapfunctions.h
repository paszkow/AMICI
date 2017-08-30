#ifndef _amici_wrapfunctions_h
#define _amici_wrapfunctions_h
#include <math.h>
#include <include/amici_model.h>
#include "model_neuron.h"
#include <include/amici_solver_cvodes.h>

class UserData;
class Solver;


#define pi M_PI

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

UserData getUserData();
Solver *getSolver();
Model *getModel();
int fx0(N_Vector x0, void *user_data);
int fdx0(N_Vector x0, N_Vector dx0, void *user_data);
int fsx0(N_Vector *sx0, N_Vector x, N_Vector dx, void *user_data);
int fsdx0(N_Vector *sdx0, N_Vector x, N_Vector dx, void *user_data);
int fJ(long int N, realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xdot, DlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);
int fJB(long int NeqBdot, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, DlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B);
int fJDiag(realtype t, N_Vector JDiag, N_Vector x, void *user_data);
int fJv(N_Vector v, N_Vector Jv, realtype t, N_Vector x, N_Vector xdot, void *user_data, N_Vector tmp);
int froot(realtype t, N_Vector x, N_Vector dx, realtype *root, void *user_data);
int frz(realtype t, int ie, N_Vector x, TempData *tdata, ReturnData *rdata);
int fsrz(realtype t, int ie, N_Vector x, N_Vector *sx, TempData *tdata, ReturnData *rdata);
int fstau(realtype t, int ie, N_Vector x, N_Vector *sx, TempData *tdata);
int fy(realtype t, int it, N_Vector x, void *user_data, ReturnData *rdata);
int fdydp(realtype t, int it, N_Vector x, TempData *tdata);
int fdydx(realtype t, int it, N_Vector x, TempData *tdata);
int fz(realtype t, int ie, N_Vector x, TempData *tdata, ReturnData *rdata);
int fsz(realtype t, int ie, N_Vector x, N_Vector *sx, TempData *tdata, ReturnData *rdata);
int fdzdp(realtype t, int ie, N_Vector x, TempData *tdata);
int fdzdx(realtype t, int ie, N_Vector x, TempData *tdata);
int fdrzdp(realtype t, int ie, N_Vector x, TempData *tdata);
int fdrzdx(realtype t, int ie, N_Vector x, TempData *tdata);
int fsxdot(int Ns, realtype t, N_Vector x, N_Vector xdot,int ip,  N_Vector sx, N_Vector sxdot, void *user_data, N_Vector tmp1, N_Vector tmp2);
int fxdot(realtype t, N_Vector x, N_Vector dx, N_Vector xdot, void *user_data);
int fxBdot(realtype t, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector xBdot, void *user_data);
int fqBdot(realtype t, N_Vector x, N_Vector xB, N_Vector qBdot, void *user_data);
int fdxdotdp(realtype t, N_Vector x, N_Vector dx, void *user_data);
int fdeltax(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, TempData *tdata);
int fdeltasx(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, N_Vector *sx, TempData *tdata);
int fdeltaxB(realtype t, int ie, N_Vector x, N_Vector xB, N_Vector xdot, N_Vector xdot_old, TempData *tdata);
int fdeltaqB(realtype t, int ie, N_Vector x, N_Vector xB, N_Vector qBdot, N_Vector xdot, N_Vector xdot_old, TempData *tdata);
int fsigma_y(realtype t, TempData *tdata);
int fdsigma_ydp(realtype t, TempData *tdata);
int fsigma_z(realtype t, int ie, TempData *tdata);
int fdsigma_zdp(realtype t, int ie, TempData *tdata);
int fJSparse(realtype t, N_Vector x, N_Vector xdot, SlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);
int fJBand(long int N, long int mupper, long int mlower, realtype t, N_Vector x, N_Vector xdot, DlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);
int fJSparseB(realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, SlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B);
int fJBandB(long int NeqBdot, long int mupper, long int mlower, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, DlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B);
int fJvB(N_Vector vB, N_Vector JvB, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, void *user_data, N_Vector tmpB);
int fJy(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fJz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fJrz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJydy(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJydsigma(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJzdz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJzdsigma(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJrzdz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJrzdsigma(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata);

class Model_model_neuron : public Model {
public:
    Model_model_neuron() : Model(4,
                    2,
                    2,
                    2,
                    1,
                    1,
                    1,
                    1,
                    1,
                    1,
                    0,
                    0,
                    0,
                    4,
                    1,
                    1,
                    AMICI_O2MODE_NONE)
    {
        z2event = new int[1] {1,};
        idlist = new realtype[2] {0, 0,};
    }

    Solver *getSolver(){
        return new CVodeSolver();
    }

    int fJ(long int N, realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xdot, DlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3) {
        return J_model_neuron(N, t, x, xdot, J, user_data, tmp1, tmp2, tmp3);
    }

    int fJB(long int NeqBdot, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, DlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B) {
        return JB_model_neuron(NeqBdot, t, x, xB, xBdot, JB, user_data, tmp1B, tmp2B, tmp3B);
    }

    int fJBand(long int N, long int mupper, long int mlower, realtype t, N_Vector x, N_Vector xdot, DlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3) {
        return JBand_model_neuron(N, mupper, mlower, t, x, xdot, J, user_data, tmp1, tmp2, tmp3);
    }

    int fJBandB(long int NeqBdot, long int mupper, long int mlower, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, DlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B) {
        return JBandB_model_neuron(NeqBdot, mupper, mlower, t, x, xB, xBdot, JB, user_data, tmp1B, tmp2B, tmp3B);
    }

    int fJDiag(realtype t, N_Vector JDiag, N_Vector x, void *user_data) {
        return JDiag_model_neuron(t, JDiag, x, user_data);
    }

    int fJSparse(realtype t, N_Vector x, N_Vector xdot, SlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3) {
        return JSparse_model_neuron(t, x, xdot, J, user_data, tmp1, tmp2, tmp3);
    }

    int fJSparseB(realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, SlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B) {
        return JSparseB_model_neuron(t, x, xB, xBdot, JB, user_data, tmp1B, tmp2B, tmp3B);
    }

    int fJrz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) {
        return Jrz_model_neuron(t, ie, x, tdata, edata, rdata);
    }

    int fJv(N_Vector v, N_Vector Jv, realtype t, N_Vector x, N_Vector xdot, void *user_data, N_Vector tmp) {
        return Jv_model_neuron(v, Jv, t, x, xdot, user_data, tmp);
    }

    int fJvB(N_Vector vB, N_Vector JvB, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, void *user_data, N_Vector tmpB) {
        return JvB_model_neuron(vB, JvB, t, x, xB, xBdot, user_data, tmpB);
    }

    int fJy(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) {
        return Jy_model_neuron(t, it, x, tdata, edata, rdata);
    }

    int fJz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) {
        return Jz_model_neuron(t, ie, x, tdata, edata, rdata);
    }

    int fdJrzdsigma(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) {
        return dJrzdsigma_model_neuron(t, ie, x, tdata, edata, rdata);
    }

    int fdJrzdz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) {
        return dJrzdz_model_neuron(t, ie, x, tdata, edata, rdata);
    }

    int fdJydsigma(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) {
        return dJydsigma_model_neuron(t, it, x, tdata, edata, rdata);
    }

    int fdJydy(realtype t, int it, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) {
        return dJydy_model_neuron(t, it, x, tdata, edata, rdata);
    }

    int fdJzdsigma(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) {
        return dJzdsigma_model_neuron(t, ie, x, tdata, edata, rdata);
    }

    int fdJzdz(realtype t, int ie, N_Vector x, TempData *tdata, const ExpData *edata, ReturnData *rdata) {
        return dJzdz_model_neuron(t, ie, x, tdata, edata, rdata);
    }

    int fdeltaqB(realtype t, int ie, N_Vector x, N_Vector xB, N_Vector qBdot, N_Vector xdot, N_Vector xdot_old, TempData *tdata) {
        return deltaqB_model_neuron(t, ie, x, xB, qBdot, xdot, xdot_old, tdata);
    }

    int fdeltasx(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, N_Vector *sx, TempData *tdata) {
        return deltasx_model_neuron(t, ie, x, xdot, xdot_old, sx, tdata);
    }

    int fdeltax(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, TempData *tdata) {
        return deltax_model_neuron(t, ie, x, xdot, xdot_old, tdata);
    }

    int fdeltaxB(realtype t, int ie, N_Vector x, N_Vector xB, N_Vector xdot, N_Vector xdot_old, TempData *tdata) {
        return deltaxB_model_neuron(t, ie, x, xB, xdot, xdot_old, tdata);
    }

    int fdrzdp(realtype t, int ie, N_Vector x, TempData *tdata) {
        return drzdp_model_neuron(t, ie, x, tdata);
    }

    int fdrzdx(realtype t, int ie, N_Vector x, TempData *tdata) {
        return drzdx_model_neuron(t, ie, x, tdata);
    }

    int fdsigma_ydp(realtype t, TempData *tdata) {
        return dsigma_ydp_model_neuron(t, tdata);
    }

    int fdsigma_zdp(realtype t, int ie, TempData *tdata) {
        return dsigma_zdp_model_neuron(t, ie, tdata);
    }

    int fdwdp(realtype t, N_Vector x, N_Vector dx, void *user_data) {
        return dwdp_model_neuron(t, x, dx, user_data);
    }

    int fdwdx(realtype t, N_Vector x, N_Vector dx, void *user_data) {
        return dwdx_model_neuron(t, x, dx, user_data);
    }

    int fdxdotdp(realtype t, N_Vector x, N_Vector dx, void *user_data) {
        return dxdotdp_model_neuron(t, x, dx, user_data);
    }

    int fdydp(realtype t, int it, N_Vector x, TempData *tdata) {
        return dydp_model_neuron(t, it, x, tdata);
    }

    int fdydx(realtype t, int it, N_Vector x, TempData *tdata) {
        return dydx_model_neuron(t, it, x, tdata);
    }

    int fdzdp(realtype t, int ie, N_Vector x, TempData *tdata) {
        return dzdp_model_neuron(t, ie, x, tdata);
    }

    int fdzdx(realtype t, int ie, N_Vector x, TempData *tdata) {
        return dzdx_model_neuron(t, ie, x, tdata);
    }

    int fqBdot(realtype t, N_Vector x, N_Vector xB, N_Vector qBdot, void *user_data) {
        return qBdot_model_neuron(t, x, xB, qBdot, user_data);
    }

    int froot(realtype t, N_Vector x, N_Vector dx, realtype *root, void *user_data) {
        return root_model_neuron(t, x, root, user_data);
    }

    int frz(realtype t, int ie, N_Vector x, TempData *tdata, ReturnData *rdata) {
        return rz_model_neuron(t, ie, x, tdata, rdata);
    }

    int fsigma_y(realtype t, TempData *tdata) {
        return sigma_y_model_neuron(t, tdata);
    }

    int fsigma_z(realtype t, int ie, TempData *tdata) {
        return sigma_z_model_neuron(t, ie, tdata);
    }

    int fsrz(realtype t, int ie, N_Vector x, N_Vector *sx, TempData *tdata, ReturnData *rdata) {
        return srz_model_neuron(t, ie, x, sx, tdata, rdata);
    }

    int fstau(realtype t, int ie, N_Vector x, N_Vector *sx, TempData *tdata) {
        return stau_model_neuron(t, ie, x, sx, tdata);
    }

    int fsx0(N_Vector *sx0, N_Vector x, N_Vector dx, void *user_data) {
        return sx0_model_neuron(sx0, x, dx, user_data);
    }

    int fsxdot(int Ns, realtype t, N_Vector x, N_Vector xdot,int ip,  N_Vector sx, N_Vector sxdot, void *user_data, N_Vector tmp1, N_Vector tmp2) {
        return sxdot_model_neuron(Ns, t, x, xdot, ip, sx, sxdot, user_data, tmp1, tmp2);
    }

    int fsz(realtype t, int ie, N_Vector x, N_Vector *sx, TempData *tdata, ReturnData *rdata) {
        return sz_model_neuron(t, ie, x, sx, tdata, rdata);
    }

    int fw(realtype t, N_Vector x, N_Vector dx, void *user_data) {
        return w_model_neuron(t, x, dx, user_data);
    }

    int fx0(N_Vector x0, void *user_data) {
        return x0_model_neuron(x0, user_data);
    }

    int fxBdot(realtype t, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector xBdot, void *user_data) {
        return xBdot_model_neuron(t, x, xB, xBdot, user_data);
    }

    int fxdot(realtype t, N_Vector x, N_Vector dx, N_Vector xdot, void *user_data) {
        return xdot_model_neuron(t, x, xdot, user_data);
    }

    int fy(realtype t, int it, N_Vector x, void *user_data, ReturnData *rdata) {
        return y_model_neuron(t, it, x, user_data, rdata);
    }

    int fz(realtype t, int ie, N_Vector x, TempData *tdata, ReturnData *rdata) {
        return z_model_neuron(t, ie, x, tdata, rdata);
    }

};

#endif /* _amici_wrapfunctions_h */