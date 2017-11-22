
#include <include/symbolic_functions.h>
#include <include/amici.h>
#include <include/amici_model.h>
#include <string.h>
#include <include/tdata.h>
#include <include/udata.h>
#include "model_nested_events_w.h"

using namespace amici;

void sigma_y_model_nested_events(realtype t, amici::TempData *tdata) {
Model *model = (Model*) tdata->model;
UserData *udata = (UserData*) tdata->udata;
memset(tdata->sigmay,0,sizeof(realtype)*1);
  tdata->sigmay[0] = 1.0;
return;

}

