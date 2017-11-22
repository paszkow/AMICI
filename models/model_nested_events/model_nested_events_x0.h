#ifndef _am_model_nested_events_x0_h
#define _am_model_nested_events_x0_h

#include <sundials/sundials_types.h>
#include <sundials/sundials_nvector.h>
#include <sundials/sundials_sparse.h>
#include <sundials/sundials_direct.h>

using namespace amici;

namespace amici {
class UserData;
class ReturnData;
class TempData;
class ExpData;
}

void x0_model_nested_events(N_Vector x0, void *user_data);


#endif /* _am_model_nested_events_x0_h */