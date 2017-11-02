#ifndef _amici_wrapfunctions_h
#define _amici_wrapfunctions_h
#include <math.h>
#include <include/amici_model.h>
#include "model_robertson.h"
#include <include/amici_solver_idas.h>

namespace amici {
class UserData;
class Solver;
}


#define pi M_PI

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

amici::UserData getUserData();
amici::Solver *getSolver();
amici::Model *getModel();
int fx0(N_Vector x0, void *user_data);
int fdx0(N_Vector x0, N_Vector dx0, void *user_data);
int fsx0(N_Vector *sx0, N_Vector x, N_Vector dx, void *user_data);
int fsdx0(N_Vector *sdx0, N_Vector x, N_Vector dx, void *user_data);
int fJ(long int N, realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xdot, DlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);
int fJB(long int NeqBdot, realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector xBdot, DlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B);
int fJDiag(realtype t, N_Vector JDiag, realtype cj, N_Vector x, N_Vector dx, void *user_data);
int fJv(realtype t, N_Vector x, N_Vector dx, N_Vector xdot, N_Vector v, N_Vector Jv, realtype cj, void *user_data, N_Vector tmp1, N_Vector tmp2);
int froot(realtype t, N_Vector x, N_Vector dx, realtype *root, void *user_data);
int frz(realtype t, int ie, N_Vector x, amici::TempData *tdata, amici::ReturnData *rdata);
int fsrz(realtype t, int ie, N_Vector x, N_Vector *sx, amici::TempData *tdata, amici::ReturnData *rdata);
int fstau(realtype t, int ie, N_Vector x, N_Vector *sx, amici::TempData *tdata);
int fy(realtype t, int it, N_Vector x, void *user_data, amici::ReturnData *rdata);
int fdydp(realtype t, int it, N_Vector x, amici::TempData *tdata);
int fdydx(realtype t, int it, N_Vector x, amici::TempData *tdata);
int fz(realtype t, int ie, N_Vector x, amici::TempData *tdata, amici::ReturnData *rdata);
int fsz(realtype t, int ie, N_Vector x, N_Vector *sx, amici::TempData *tdata, amici::ReturnData *rdata);
int fdzdp(realtype t, int ie, N_Vector x, amici::TempData *tdata);
int fdzdx(realtype t, int ie, N_Vector x, amici::TempData *tdata);
int fdrzdp(realtype t, int ie, N_Vector x, amici::TempData *tdata);
int fdrzdx(realtype t, int ie, N_Vector x, amici::TempData *tdata);
int fsxdot(int Ns, realtype t, N_Vector x, N_Vector dx, N_Vector xdot,int ip,  N_Vector sx, N_Vector sdx, N_Vector sxdot, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);
int fxdot(realtype t, N_Vector x, N_Vector dx, N_Vector xdot, void *user_data);
int fxBdot(realtype t, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector xBdot, void *user_data);
int fqBdot(realtype t, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector qBdot, void *user_data);
int fdxdotdp(realtype t, N_Vector x, N_Vector dx, void *user_data);
int fdeltax(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, amici::TempData *tdata);
int fdeltasx(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, N_Vector *sx, amici::TempData *tdata);
int fdeltaxB(realtype t, int ie, N_Vector x, N_Vector xB, N_Vector xdot, N_Vector xdot_old, amici::TempData *tdata);
int fdeltaqB(realtype t, int ie, N_Vector x, N_Vector xB, N_Vector qBdot, N_Vector xdot, N_Vector xdot_old, amici::TempData *tdata);
int fsigma_y(realtype t, amici::TempData *tdata);
int fdsigma_ydp(realtype t, amici::TempData *tdata);
int fsigma_z(realtype t, int ie, amici::TempData *tdata);
int fdsigma_zdp(realtype t, int ie, amici::TempData *tdata);
int fJSparse(realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xdot, SlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);
int fJBand(long int N, long int mupper, long int mlower, realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xdot, DlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);
int fJSparseB(realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector xBdot, SlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B);
int fJBandB(long int NeqBdot, long int mupper, long int mlower, realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector xBdot, DlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B);
int fJvB(realtype t, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector xBdot, N_Vector vB, N_Vector JvB, realtype cj, void *user_data, N_Vector tmpB1, N_Vector tmpB2);
int fJy(realtype t, int it, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata);
int fJz(realtype t, int ie, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata);
int fJrz(realtype t, int ie, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata);
int fdJydy(realtype t, int it, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata);
int fdJydsigma(realtype t, int it, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata);
int fdJzdz(realtype t, int ie, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata);
int fdJzdsigma(realtype t, int ie, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata);
int fdJrzdz(realtype t, int ie, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata);
int fdJrzdsigma(realtype t, int ie, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata);

class Model_model_robertson : public amici::Model {
public:
    Model_model_robertson() : amici::Model(3,
                    3,
                    3,
                    1,
                    3,
                    3,
                    0,
                    0,
                    0,
                    1,
                    1,
                    2,
                    1,
                    9,
                    2,
                    2,
                    amici::AMICI_O2MODE_NONE)
    {
        z2event = new int[0] {};
        idlist = new realtype[3] {1, 1, 0,};
    }

    amici::Solver *getSolver() override {
        return new amici::IDASolver();
    }

    int fJ(long int N, realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xdot, DlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3) override {
        return J_model_robertson(N, t, cj, x, dx, xdot, J, user_data, tmp1, tmp2, tmp3);
    }

    int fJB(long int NeqBdot, realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector xBdot, DlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B) override {
        return JB_model_robertson(NeqBdot, t, cj, x, dx, xB, dxB, xBdot, JB, user_data, tmp1B, tmp2B, tmp3B);
    }

    int fJBand(long int N, long int mupper, long int mlower, realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xdot, DlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3) override {
        return JBand_model_robertson(N, mupper, mlower, t, cj, x, dx, xdot, J, user_data, tmp1, tmp2, tmp3);
    }

    int fJBandB(long int NeqBdot, long int mupper, long int mlower, realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector xBdot, DlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B) override {
        return JBandB_model_robertson(NeqBdot, mupper, mlower, t, cj, x, dx, xB, dxB, xBdot, JB, user_data, tmp1B, tmp2B, tmp3B);
    }

    int fJDiag(realtype t, N_Vector JDiag, realtype cj, N_Vector x, N_Vector dx, void *user_data) override {
        return JDiag_model_robertson(t, JDiag, cj, x, dx, user_data);
    }

    int fJSparse(realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xdot, SlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3) override {
        return JSparse_model_robertson(t, cj, x, dx, xdot, J, user_data, tmp1, tmp2, tmp3);
    }

    int fJSparseB(realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector xBdot, SlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B) override {
        return JSparseB_model_robertson(t, cj, x, dx, xB, dxB, xBdot, JB, user_data, tmp1B, tmp2B, tmp3B);
    }

    int fJrz(realtype t, int ie, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata) override {
        return Jrz_model_robertson(t, ie, x, tdata, edata, rdata);
    }

    int fJv(realtype t, N_Vector x, N_Vector dx, N_Vector xdot, N_Vector v, N_Vector Jv, realtype cj, void *user_data, N_Vector tmp1, N_Vector tmp2) override {
        return Jv_model_robertson(t, x, dx, xdot, v, Jv, cj, user_data, tmp1, tmp2);
    }

    int fJvB(realtype t, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector xBdot, N_Vector vB, N_Vector JvB, realtype cj, void *user_data, N_Vector tmpB1, N_Vector tmpB2) override {
        return JvB_model_robertson(t, x, dx, xB, dxB, xBdot, vB, JvB, cj, user_data, tmpB1, tmpB2);
    }

    int fJy(realtype t, int it, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata) override {
        return Jy_model_robertson(t, it, x, tdata, edata, rdata);
    }

    int fJz(realtype t, int ie, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata) override {
        return Jz_model_robertson(t, ie, x, tdata, edata, rdata);
    }

    int fM(realtype t, N_Vector x, N_Vector dx, void *user_data) override {
        return M_model_robertson(t, x, dx, user_data);
    }

    int fdJrzdsigma(realtype t, int ie, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata) override {
        return dJrzdsigma_model_robertson(t, ie, x, tdata, edata, rdata);
    }

    int fdJrzdz(realtype t, int ie, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata) override {
        return dJrzdz_model_robertson(t, ie, x, tdata, edata, rdata);
    }

    int fdJydsigma(realtype t, int it, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata) override {
        return dJydsigma_model_robertson(t, it, x, tdata, edata, rdata);
    }

    int fdJydy(realtype t, int it, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata) override {
        return dJydy_model_robertson(t, it, x, tdata, edata, rdata);
    }

    int fdJzdsigma(realtype t, int ie, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata) override {
        return dJzdsigma_model_robertson(t, ie, x, tdata, edata, rdata);
    }

    int fdJzdz(realtype t, int ie, N_Vector x, amici::TempData *tdata, const amici::ExpData *edata, amici::ReturnData *rdata) override {
        return dJzdz_model_robertson(t, ie, x, tdata, edata, rdata);
    }

    int fdeltaqB(realtype t, int ie, N_Vector x, N_Vector xB, N_Vector qBdot, N_Vector xdot, N_Vector xdot_old, amici::TempData *tdata) override {
        return deltaqB_model_robertson(t, ie, x, xB, qBdot, xdot, xdot_old, tdata);
    }

    int fdeltasx(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, N_Vector *sx, amici::TempData *tdata) override {
        return deltasx_model_robertson(t, ie, x, xdot, xdot_old, sx, tdata);
    }

    int fdeltax(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, amici::TempData *tdata) override {
        return deltax_model_robertson(t, ie, x, xdot, xdot_old, tdata);
    }

    int fdeltaxB(realtype t, int ie, N_Vector x, N_Vector xB, N_Vector xdot, N_Vector xdot_old, amici::TempData *tdata) override {
        return deltaxB_model_robertson(t, ie, x, xB, xdot, xdot_old, tdata);
    }

    int fdfdx(realtype t, N_Vector x, N_Vector dx, void *user_data) override {
        return dfdx_model_robertson(t, x, dx, user_data);
    }

    int fdrzdp(realtype t, int ie, N_Vector x, amici::TempData *tdata) override {
        return drzdp_model_robertson(t, ie, x, tdata);
    }

    int fdrzdx(realtype t, int ie, N_Vector x, amici::TempData *tdata) override {
        return drzdx_model_robertson(t, ie, x, tdata);
    }

    int fdsigma_ydp(realtype t, amici::TempData *tdata) override {
        return dsigma_ydp_model_robertson(t, tdata);
    }

    int fdsigma_zdp(realtype t, int ie, amici::TempData *tdata) override {
        return dsigma_zdp_model_robertson(t, ie, tdata);
    }

    int fdwdp(realtype t, N_Vector x, N_Vector dx, void *user_data) override {
        return dwdp_model_robertson(t, x, dx, user_data);
    }

    int fdwdx(realtype t, N_Vector x, N_Vector dx, void *user_data) override {
        return dwdx_model_robertson(t, x, dx, user_data);
    }

    int fdx0(N_Vector x0, N_Vector dx0, void *user_data) override {
        return dx0_model_robertson(x0, dx0, user_data);
    }

    int fdxdotdp(realtype t, N_Vector x, N_Vector dx, void *user_data) override {
        return dxdotdp_model_robertson(t, x, dx, user_data);
    }

    int fdydp(realtype t, int it, N_Vector x, amici::TempData *tdata) override {
        return dydp_model_robertson(t, it, x, tdata);
    }

    int fdydx(realtype t, int it, N_Vector x, amici::TempData *tdata) override {
        return dydx_model_robertson(t, it, x, tdata);
    }

    int fdzdp(realtype t, int ie, N_Vector x, amici::TempData *tdata) override {
        return dzdp_model_robertson(t, ie, x, tdata);
    }

    int fdzdx(realtype t, int ie, N_Vector x, amici::TempData *tdata) override {
        return dzdx_model_robertson(t, ie, x, tdata);
    }

    int fqBdot(realtype t, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector qBdot, void *user_data) override {
        return qBdot_model_robertson(t, x, dx, xB, dxB, qBdot, user_data);
    }

    int froot(realtype t, N_Vector x, N_Vector dx, realtype *root, void *user_data) override {
        return root_model_robertson(t, x, dx, root, user_data);
    }

    int frz(realtype t, int ie, N_Vector x, amici::TempData *tdata, amici::ReturnData *rdata) override {
        return rz_model_robertson(t, ie, x, tdata, rdata);
    }

    int fsdx0(N_Vector *sdx0, N_Vector x, N_Vector dx, void *user_data) override {
        return sdx0_model_robertson(sdx0, x, dx, user_data);
    }

    int fsigma_y(realtype t, amici::TempData *tdata) override {
        return sigma_y_model_robertson(t, tdata);
    }

    int fsigma_z(realtype t, int ie, amici::TempData *tdata) override {
        return sigma_z_model_robertson(t, ie, tdata);
    }

    int fsrz(realtype t, int ie, N_Vector x, N_Vector *sx, amici::TempData *tdata, amici::ReturnData *rdata) override {
        return srz_model_robertson(t, ie, x, sx, tdata, rdata);
    }

    int fstau(realtype t, int ie, N_Vector x, N_Vector *sx, amici::TempData *tdata) override {
        return stau_model_robertson(t, ie, x, sx, tdata);
    }

    int fsx0(N_Vector *sx0, N_Vector x, N_Vector dx, void *user_data) override {
        return sx0_model_robertson(sx0, x, dx, user_data);
    }

    int fsxdot(int Ns, realtype t, N_Vector x, N_Vector dx, N_Vector xdot,int ip,  N_Vector sx, N_Vector sdx, N_Vector sxdot, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3) override {
        return sxdot_model_robertson(Ns, t, x, dx, xdot, ip, sx, sdx, sxdot, user_data, tmp1, tmp2, tmp3);
    }

    int fsz(realtype t, int ie, N_Vector x, N_Vector *sx, amici::TempData *tdata, amici::ReturnData *rdata) override {
        return sz_model_robertson(t, ie, x, sx, tdata, rdata);
    }

    int fw(realtype t, N_Vector x, N_Vector dx, void *user_data) override {
        return w_model_robertson(t, x, dx, user_data);
    }

    int fx0(N_Vector x0, void *user_data) override {
        return x0_model_robertson(x0, user_data);
    }

    int fxBdot(realtype t, N_Vector x, N_Vector dx, N_Vector xB, N_Vector dxB, N_Vector xBdot, void *user_data) override {
        return xBdot_model_robertson(t, x, dx, xB, dxB, xBdot, user_data);
    }

    int fxdot(realtype t, N_Vector x, N_Vector dx, N_Vector xdot, void *user_data) override {
        return xdot_model_robertson(t, x, dx, xdot, user_data);
    }

    int fy(realtype t, int it, N_Vector x, void *user_data, amici::ReturnData *rdata) override {
        return y_model_robertson(t, it, x, user_data, rdata);
    }

    int fz(realtype t, int ie, N_Vector x, amici::TempData *tdata, amici::ReturnData *rdata) override {
        return z_model_robertson(t, ie, x, tdata, rdata);
    }

};

#endif /* _amici_wrapfunctions_h */
