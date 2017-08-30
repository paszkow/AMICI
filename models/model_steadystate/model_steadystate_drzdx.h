#ifndef _am_model_steadystate_drzdx_h
#define _am_model_steadystate_drzdx_h

#include <sundials/sundials_types.h>
#include <sundials/sundials_nvector.h>
#include <sundials/sundials_sparse.h>
#include <sundials/sundials_direct.h>

class UserData;
class ReturnData;
class TempData;
class ExpData;

int drzdx_model_steadystate(realtype t, int ie, N_Vector x, TempData *tdata);


#endif /* _am_model_steadystate_drzdx_h */