
#include "amici/symbolic_functions.h"
#include "amici/amici_defines.h" //realtype definition
typedef amici::realtype realtype;
#include <cmath> 

void qBdot_model_jakstat_adjoint_o2(realtype *qBdot, const int ip, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *xB, const realtype *w, const realtype *dwdp) {
switch (ip) {
  case 0: {
  qBdot[0] = -w[0]*x[0]*xB[1]+k[0]*w[0]*x[0]*w[2]*xB[0];
  qBdot[1] = w[0]*x[9]*xB[0]-w[0]*x[0]*xB[10]-w[0]*x[9]*xB[1]+k[0]*w[0]*x[0]*w[2]*xB[9];
  qBdot[2] = w[0]*x[18]*xB[0]-w[0]*x[0]*xB[19]-w[0]*x[18]*xB[1]+k[0]*w[0]*x[0]*w[2]*xB[18];
  qBdot[3] = w[0]*x[27]*xB[0]-w[0]*x[0]*xB[28]-w[0]*x[27]*xB[1]+k[0]*w[0]*x[0]*w[2]*xB[27];
  qBdot[4] = w[0]*x[36]*xB[0]-w[0]*x[0]*xB[37]-w[0]*x[36]*xB[1]+k[0]*w[0]*x[0]*w[2]*xB[36];
  qBdot[5] = w[0]*x[45]*xB[0]-w[0]*x[0]*xB[46]-w[0]*x[45]*xB[1]+k[0]*w[0]*x[0]*w[2]*xB[45];
  qBdot[6] = xB[0]*(x[0]*w[5]+w[0]*x[54])-xB[1]*(x[0]*w[5]+w[0]*x[54])-w[0]*x[0]*xB[55]+k[0]*w[0]*x[0]*w[2]*xB[54];
  qBdot[7] = xB[0]*(x[0]*w[6]+w[0]*x[63])-xB[1]*(x[0]*w[6]+w[0]*x[63])-w[0]*x[0]*xB[64]+k[0]*w[0]*x[0]*w[2]*xB[63];
  qBdot[8] = xB[0]*(x[0]*w[7]+w[0]*x[72])-xB[1]*(x[0]*w[7]+w[0]*x[72])-w[0]*x[0]*xB[73]+k[0]*w[0]*x[0]*w[2]*xB[72];
  qBdot[9] = xB[0]*(x[0]*w[8]+w[0]*x[81])-xB[1]*(x[0]*w[8]+w[0]*x[81])-w[0]*x[0]*xB[82]+k[0]*w[0]*x[0]*w[2]*xB[81];
  qBdot[10] = xB[0]*(x[0]*w[9]+w[0]*x[90])-xB[1]*(x[0]*w[9]+w[0]*x[90])-w[0]*x[0]*xB[91]+k[0]*w[0]*x[0]*w[2]*xB[90];
  qBdot[11] = w[0]*xB[0]*x[99]-w[0]*x[0]*xB[100]-w[0]*xB[1]*x[99]+k[0]*w[0]*x[0]*w[2]*xB[99];
  qBdot[12] = w[0]*xB[0]*x[108]-w[0]*x[0]*xB[109]-w[0]*xB[1]*x[108]+k[0]*w[0]*x[0]*w[2]*xB[108];
  qBdot[13] = w[0]*xB[0]*x[117]-w[0]*x[0]*xB[118]-w[0]*xB[1]*x[117]+k[0]*w[0]*x[0]*w[2]*xB[117];
  qBdot[14] = w[0]*xB[0]*x[126]-w[0]*x[0]*xB[127]-w[0]*xB[1]*x[126]+k[0]*w[0]*x[0]*w[2]*xB[126];
  qBdot[15] = w[0]*xB[0]*x[135]-w[0]*x[0]*xB[136]-w[0]*xB[1]*x[135]+k[0]*w[0]*x[0]*w[2]*xB[135];
  qBdot[16] = w[0]*xB[0]*x[144]-w[0]*x[0]*xB[145]-w[0]*xB[1]*x[144]+k[0]*w[0]*x[0]*w[2]*xB[144];
  qBdot[17] = w[0]*xB[0]*x[153]-w[0]*x[0]*xB[154]-w[0]*xB[1]*x[153]+k[0]*w[0]*x[0]*w[2]*xB[153];

  } break;

  case 1: {
  qBdot[0] = w[1]*xB[1]*2.0-w[1]*xB[2];
  qBdot[1] = w[1]*xB[10]*2.0-w[1]*xB[11]+x[1]*x[10]*xB[1]*4.0-x[1]*x[10]*xB[2]*2.0;
  qBdot[2] = w[1]*xB[19]*2.0-w[1]*xB[20]+x[1]*x[19]*xB[1]*4.0-x[1]*x[19]*xB[2]*2.0;
  qBdot[3] = w[1]*xB[28]*2.0-w[1]*xB[29]+x[1]*x[28]*xB[1]*4.0-x[1]*x[28]*xB[2]*2.0;
  qBdot[4] = w[1]*xB[37]*2.0-w[1]*xB[38]+x[1]*x[37]*xB[1]*4.0-x[1]*x[37]*xB[2]*2.0;
  qBdot[5] = w[1]*xB[46]*2.0-w[1]*xB[47]+x[1]*x[46]*xB[1]*4.0-x[1]*x[46]*xB[2]*2.0;
  qBdot[6] = w[1]*xB[55]*2.0-w[1]*xB[56]+x[1]*x[55]*xB[1]*4.0-x[1]*x[55]*xB[2]*2.0;
  qBdot[7] = w[1]*xB[64]*2.0-w[1]*xB[65]+x[1]*x[64]*xB[1]*4.0-x[1]*x[64]*xB[2]*2.0;
  qBdot[8] = w[1]*xB[73]*2.0-w[1]*xB[74]+x[1]*xB[1]*x[73]*4.0-x[1]*xB[2]*x[73]*2.0;
  qBdot[9] = w[1]*xB[82]*2.0-w[1]*xB[83]+x[1]*xB[1]*x[82]*4.0-x[1]*xB[2]*x[82]*2.0;
  qBdot[10] = w[1]*xB[91]*2.0-w[1]*xB[92]+x[1]*xB[1]*x[91]*4.0-x[1]*xB[2]*x[91]*2.0;
  qBdot[11] = w[1]*xB[100]*2.0-w[1]*xB[101]+x[1]*xB[1]*x[100]*4.0-x[1]*xB[2]*x[100]*2.0;
  qBdot[12] = w[1]*xB[109]*2.0-w[1]*xB[110]+x[1]*xB[1]*x[109]*4.0-x[1]*xB[2]*x[109]*2.0;
  qBdot[13] = w[1]*xB[118]*2.0-w[1]*xB[119]+x[1]*xB[1]*x[118]*4.0-x[1]*xB[2]*x[118]*2.0;
  qBdot[14] = w[1]*xB[127]*2.0-w[1]*xB[128]+x[1]*xB[1]*x[127]*4.0-x[1]*xB[2]*x[127]*2.0;
  qBdot[15] = w[1]*xB[136]*2.0-w[1]*xB[137]+x[1]*xB[1]*x[136]*4.0-x[1]*xB[2]*x[136]*2.0;
  qBdot[16] = w[1]*xB[145]*2.0-w[1]*xB[146]+x[1]*xB[1]*x[145]*4.0-x[1]*xB[2]*x[145]*2.0;
  qBdot[17] = w[1]*xB[154]*2.0-w[1]*xB[155]+x[1]*xB[1]*x[154]*4.0-x[1]*xB[2]*x[154]*2.0;

  } break;

  case 2: {
  qBdot[0] = x[2]*xB[2]-k[0]*w[3]*x[2]*xB[3];
  qBdot[1] = x[2]*xB[11]+x[11]*xB[2]-k[0]*w[3]*x[2]*xB[12]-k[0]*w[3]*x[11]*xB[3];
  qBdot[2] = x[2]*xB[20]+x[20]*xB[2]-k[0]*w[3]*x[2]*xB[21]-k[0]*w[3]*x[20]*xB[3];
  qBdot[3] = x[2]*xB[29]+x[29]*xB[2]-k[0]*w[3]*x[2]*xB[30]-k[0]*w[3]*x[29]*xB[3];
  qBdot[4] = x[2]*xB[38]+x[38]*xB[2]-k[0]*w[3]*x[2]*xB[39]-k[0]*w[3]*x[38]*xB[3];
  qBdot[5] = x[2]*xB[47]+x[47]*xB[2]-k[0]*w[3]*x[2]*xB[48]-k[0]*w[3]*x[47]*xB[3];
  qBdot[6] = x[2]*xB[56]+x[56]*xB[2]-k[0]*w[3]*x[2]*xB[57]-k[0]*w[3]*x[56]*xB[3];
  qBdot[7] = x[2]*xB[65]+x[65]*xB[2]-k[0]*w[3]*x[2]*xB[66]-k[0]*w[3]*x[65]*xB[3];
  qBdot[8] = x[2]*xB[74]+xB[2]*x[74]-k[0]*w[3]*x[2]*xB[75]-k[0]*w[3]*xB[3]*x[74];
  qBdot[9] = x[2]*xB[83]+xB[2]*x[83]-k[0]*w[3]*x[2]*xB[84]-k[0]*w[3]*xB[3]*x[83];
  qBdot[10] = x[2]*xB[92]+xB[2]*x[92]-k[0]*w[3]*x[2]*xB[93]-k[0]*w[3]*xB[3]*x[92];
  qBdot[11] = x[2]*xB[101]+xB[2]*x[101]-k[0]*w[3]*x[2]*xB[102]-k[0]*w[3]*xB[3]*x[101];
  qBdot[12] = x[2]*xB[110]+xB[2]*x[110]-k[0]*w[3]*x[2]*xB[111]-k[0]*w[3]*xB[3]*x[110];
  qBdot[13] = x[2]*xB[119]+xB[2]*x[119]-k[0]*w[3]*x[2]*xB[120]-k[0]*w[3]*xB[3]*x[119];
  qBdot[14] = x[2]*xB[128]+xB[2]*x[128]-k[0]*w[3]*x[2]*xB[129]-k[0]*w[3]*xB[3]*x[128];
  qBdot[15] = x[2]*xB[137]+xB[2]*x[137]-k[0]*w[3]*x[2]*xB[138]-k[0]*w[3]*xB[3]*x[137];
  qBdot[16] = x[2]*xB[146]+xB[2]*x[146]-k[0]*w[3]*x[2]*xB[147]-k[0]*w[3]*xB[3]*x[146];
  qBdot[17] = x[2]*xB[155]+xB[2]*x[155]-k[0]*w[3]*x[2]*xB[156]-k[0]*w[3]*xB[3]*x[155];

  } break;

  case 3: {
  qBdot[0] = -xB[4]*(w[4]-x[4])-xB[5]*(x[4]-x[5])-xB[6]*(x[5]-x[6])-xB[7]*(x[6]-x[7])-xB[8]*(x[7]-x[8])+k[1]*w[3]*x[3]*xB[3]-k[1]*w[2]*x[8]*xB[0];
  qBdot[1] = x[12]*xB[3]-xB[13]*(w[4]-x[4])-xB[14]*(x[4]-x[5])-xB[15]*(x[5]-x[6])-xB[16]*(x[6]-x[7])-xB[5]*(x[13]-x[14])-xB[17]*(x[7]-x[8])-xB[6]*(x[14]-x[15])-xB[7]*(x[15]-x[16])-xB[8]*(x[16]-x[17])-xB[4]*(x[12]*2.0-x[13])+k[1]*w[3]*x[3]*xB[12]-k[1]*w[2]*x[8]*xB[9]-k[1]*w[2]*x[17]*xB[0];
  qBdot[2] = x[21]*xB[3]-xB[22]*(w[4]-x[4])-xB[23]*(x[4]-x[5])-xB[24]*(x[5]-x[6])-xB[25]*(x[6]-x[7])-xB[26]*(x[7]-x[8])-xB[5]*(x[22]-x[23])-xB[6]*(x[23]-x[24])-xB[7]*(x[24]-x[25])-xB[8]*(x[25]-x[26])-xB[4]*(x[21]*2.0-x[22])+k[1]*w[3]*x[3]*xB[21]-k[1]*w[2]*x[8]*xB[18]-k[1]*w[2]*x[26]*xB[0];
  qBdot[3] = x[30]*xB[3]-xB[31]*(w[4]-x[4])-xB[32]*(x[4]-x[5])-xB[33]*(x[5]-x[6])-xB[34]*(x[6]-x[7])-xB[35]*(x[7]-x[8])-xB[5]*(x[31]-x[32])-xB[6]*(x[32]-x[33])-xB[7]*(x[33]-x[34])-xB[8]*(x[34]-x[35])-xB[4]*(x[30]*2.0-x[31])+k[1]*w[3]*x[3]*xB[30]-k[1]*w[2]*x[8]*xB[27]-k[1]*w[2]*x[35]*xB[0];
  qBdot[4] = x[39]*xB[3]-xB[40]*(w[4]-x[4])-xB[41]*(x[4]-x[5])-xB[42]*(x[5]-x[6])-xB[43]*(x[6]-x[7])-xB[44]*(x[7]-x[8])-xB[5]*(x[40]-x[41])-xB[6]*(x[41]-x[42])-xB[7]*(x[42]-x[43])-xB[8]*(x[43]-x[44])-xB[4]*(x[39]*2.0-x[40])+k[1]*w[3]*x[3]*xB[39]-k[1]*w[2]*x[8]*xB[36]-k[1]*w[2]*x[44]*xB[0];
  qBdot[5] = x[48]*xB[3]-xB[49]*(w[4]-x[4])-xB[50]*(x[4]-x[5])-xB[51]*(x[5]-x[6])-xB[52]*(x[6]-x[7])-xB[53]*(x[7]-x[8])-xB[5]*(x[49]-x[50])-xB[6]*(x[50]-x[51])-xB[7]*(x[51]-x[52])-xB[8]*(x[52]-x[53])-xB[4]*(x[48]*2.0-x[49])+k[1]*w[3]*x[3]*xB[48]-k[1]*w[2]*x[8]*xB[45]-k[1]*w[2]*x[53]*xB[0];
  qBdot[6] = x[57]*xB[3]-xB[58]*(w[4]-x[4])-xB[59]*(x[4]-x[5])-xB[60]*(x[5]-x[6])-xB[61]*(x[6]-x[7])-xB[62]*(x[7]-x[8])-xB[5]*(x[58]-x[59])-xB[6]*(x[59]-x[60])-xB[7]*(x[60]-x[61])-xB[8]*(x[61]-x[62])-xB[4]*(x[57]*2.0-x[58])+k[1]*w[3]*x[3]*xB[57]-k[1]*w[2]*x[8]*xB[54]-k[1]*w[2]*x[62]*xB[0];
  qBdot[7] = x[66]*xB[3]-xB[67]*(w[4]-x[4])-xB[68]*(x[4]-x[5])-xB[69]*(x[5]-x[6])-xB[70]*(x[6]-x[7])-xB[71]*(x[7]-x[8])-xB[5]*(x[67]-x[68])-xB[6]*(x[68]-x[69])-xB[7]*(x[69]-x[70])-xB[8]*(x[70]-x[71])-xB[4]*(x[66]*2.0-x[67])+k[1]*w[3]*x[3]*xB[66]-k[1]*w[2]*x[8]*xB[63]-k[1]*w[2]*xB[0]*x[71];
  qBdot[8] = xB[3]*x[75]-xB[76]*(w[4]-x[4])-xB[77]*(x[4]-x[5])-xB[78]*(x[5]-x[6])-xB[79]*(x[6]-x[7])-xB[80]*(x[7]-x[8])-xB[5]*(x[76]-x[77])-xB[6]*(x[77]-x[78])-xB[7]*(x[78]-x[79])-xB[8]*(x[79]-x[80])-xB[4]*(x[75]*2.0-x[76])+k[1]*w[3]*x[3]*xB[75]-k[1]*w[2]*x[8]*xB[72]-k[1]*w[2]*xB[0]*x[80];
  qBdot[9] = xB[3]*x[84]-xB[85]*(w[4]-x[4])-xB[86]*(x[4]-x[5])-xB[87]*(x[5]-x[6])-xB[88]*(x[6]-x[7])-xB[89]*(x[7]-x[8])-xB[5]*(x[85]-x[86])-xB[6]*(x[86]-x[87])-xB[7]*(x[87]-x[88])-xB[8]*(x[88]-x[89])-xB[4]*(x[84]*2.0-x[85])+k[1]*w[3]*x[3]*xB[84]-k[1]*w[2]*x[8]*xB[81]-k[1]*w[2]*xB[0]*x[89];
  qBdot[10] = xB[3]*x[93]-xB[94]*(w[4]-x[4])-xB[95]*(x[4]-x[5])-xB[96]*(x[5]-x[6])-xB[97]*(x[6]-x[7])-xB[98]*(x[7]-x[8])-xB[5]*(x[94]-x[95])-xB[6]*(x[95]-x[96])-xB[7]*(x[96]-x[97])-xB[8]*(x[97]-x[98])-xB[4]*(x[93]*2.0-x[94])+k[1]*w[3]*x[3]*xB[93]-k[1]*w[2]*x[8]*xB[90]-k[1]*w[2]*xB[0]*x[98];
  qBdot[11] = xB[3]*x[102]-xB[103]*(w[4]-x[4])-xB[104]*(x[4]-x[5])-xB[105]*(x[5]-x[6])-xB[106]*(x[6]-x[7])-xB[107]*(x[7]-x[8])-xB[5]*(x[103]-x[104])-xB[6]*(x[104]-x[105])-xB[7]*(x[105]-x[106])-xB[8]*(x[106]-x[107])-xB[4]*(x[102]*2.0-x[103])+k[1]*w[3]*x[3]*xB[102]-k[1]*w[2]*x[8]*xB[99]-k[1]*w[2]*xB[0]*x[107];
  qBdot[12] = xB[3]*x[111]-xB[112]*(w[4]-x[4])-xB[113]*(x[4]-x[5])-xB[114]*(x[5]-x[6])-xB[115]*(x[6]-x[7])-xB[116]*(x[7]-x[8])-xB[5]*(x[112]-x[113])-xB[6]*(x[113]-x[114])-xB[7]*(x[114]-x[115])-xB[8]*(x[115]-x[116])-xB[4]*(x[111]*2.0-x[112])+k[1]*w[3]*x[3]*xB[111]-k[1]*w[2]*x[8]*xB[108]-k[1]*w[2]*xB[0]*x[116];
  qBdot[13] = xB[3]*x[120]-xB[121]*(w[4]-x[4])-xB[122]*(x[4]-x[5])-xB[123]*(x[5]-x[6])-xB[124]*(x[6]-x[7])-xB[125]*(x[7]-x[8])-xB[5]*(x[121]-x[122])-xB[6]*(x[122]-x[123])-xB[7]*(x[123]-x[124])-xB[8]*(x[124]-x[125])-xB[4]*(x[120]*2.0-x[121])+k[1]*w[3]*x[3]*xB[120]-k[1]*w[2]*x[8]*xB[117]-k[1]*w[2]*xB[0]*x[125];
  qBdot[14] = xB[3]*x[129]-xB[130]*(w[4]-x[4])-xB[131]*(x[4]-x[5])-xB[132]*(x[5]-x[6])-xB[133]*(x[6]-x[7])-xB[134]*(x[7]-x[8])-xB[5]*(x[130]-x[131])-xB[6]*(x[131]-x[132])-xB[7]*(x[132]-x[133])-xB[8]*(x[133]-x[134])-xB[4]*(x[129]*2.0-x[130])+k[1]*w[3]*x[3]*xB[129]-k[1]*w[2]*x[8]*xB[126]-k[1]*w[2]*xB[0]*x[134];
  qBdot[15] = xB[3]*x[138]-xB[139]*(w[4]-x[4])-xB[140]*(x[4]-x[5])-xB[141]*(x[5]-x[6])-xB[142]*(x[6]-x[7])-xB[143]*(x[7]-x[8])-xB[5]*(x[139]-x[140])-xB[6]*(x[140]-x[141])-xB[7]*(x[141]-x[142])-xB[8]*(x[142]-x[143])-xB[4]*(x[138]*2.0-x[139])+k[1]*w[3]*x[3]*xB[138]-k[1]*w[2]*x[8]*xB[135]-k[1]*w[2]*xB[0]*x[143];
  qBdot[16] = xB[3]*x[147]-xB[148]*(w[4]-x[4])-xB[149]*(x[4]-x[5])-xB[150]*(x[5]-x[6])-xB[151]*(x[6]-x[7])-xB[152]*(x[7]-x[8])-xB[5]*(x[148]-x[149])-xB[6]*(x[149]-x[150])-xB[7]*(x[150]-x[151])-xB[8]*(x[151]-x[152])-xB[4]*(x[147]*2.0-x[148])+k[1]*w[3]*x[3]*xB[147]-k[1]*w[2]*x[8]*xB[144]-k[1]*w[2]*xB[0]*x[152];
  qBdot[17] = xB[3]*x[156]-xB[157]*(w[4]-x[4])-xB[158]*(x[4]-x[5])-xB[159]*(x[5]-x[6])-xB[160]*(x[6]-x[7])-xB[161]*(x[7]-x[8])-xB[5]*(x[157]-x[158])-xB[6]*(x[158]-x[159])-xB[7]*(x[159]-x[160])-xB[8]*(x[160]-x[161])-xB[4]*(x[156]*2.0-x[157])+k[1]*w[3]*x[3]*xB[156]-k[1]*w[2]*x[8]*xB[153]-k[1]*w[2]*xB[0]*x[161];

  } break;

  case 5: {
  qBdot[0] = -p[0]*x[0]*xB[1]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[0]*dwdp[0];
  qBdot[1] = xB[0]*dwdp[0]*(x[0]+p[0]*x[9])-xB[1]*dwdp[0]*(x[0]+p[0]*x[9])-p[0]*x[0]*xB[10]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[9]*dwdp[0];
  qBdot[2] = p[0]*x[18]*xB[0]*dwdp[0]-p[0]*x[0]*xB[19]*dwdp[0]-p[0]*x[18]*xB[1]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[18]*dwdp[0];
  qBdot[3] = p[0]*x[27]*xB[0]*dwdp[0]-p[0]*x[0]*xB[28]*dwdp[0]-p[0]*x[27]*xB[1]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[27]*dwdp[0];
  qBdot[4] = p[0]*x[36]*xB[0]*dwdp[0]-p[0]*x[0]*xB[37]*dwdp[0]-p[0]*x[36]*xB[1]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[36]*dwdp[0];
  qBdot[5] = p[0]*x[45]*xB[0]*dwdp[0]-p[0]*x[0]*xB[46]*dwdp[0]-p[0]*x[45]*xB[1]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[45]*dwdp[0];
  qBdot[6] = xB[0]*(p[0]*x[0]*dwdp[1]+p[0]*x[54]*dwdp[0])-xB[1]*(p[0]*x[0]*dwdp[1]+p[0]*x[54]*dwdp[0])-p[0]*x[0]*xB[55]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[54]*dwdp[0];
  qBdot[7] = xB[0]*(p[0]*x[0]*dwdp[2]+p[0]*x[63]*dwdp[0])-xB[1]*(p[0]*x[0]*dwdp[2]+p[0]*x[63]*dwdp[0])-p[0]*x[0]*xB[64]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[63]*dwdp[0];
  qBdot[8] = xB[0]*(p[0]*x[0]*dwdp[3]+p[0]*x[72]*dwdp[0])-xB[1]*(p[0]*x[0]*dwdp[3]+p[0]*x[72]*dwdp[0])-p[0]*x[0]*xB[73]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[72]*dwdp[0];
  qBdot[9] = xB[0]*(p[0]*x[0]*dwdp[4]+p[0]*x[81]*dwdp[0])-xB[1]*(p[0]*x[0]*dwdp[4]+p[0]*x[81]*dwdp[0])-p[0]*x[0]*xB[82]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[81]*dwdp[0];
  qBdot[10] = xB[0]*(p[0]*x[0]*dwdp[5]+p[0]*x[90]*dwdp[0])-xB[1]*(p[0]*x[0]*dwdp[5]+p[0]*x[90]*dwdp[0])-p[0]*x[0]*xB[91]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[90]*dwdp[0];
  qBdot[11] = p[0]*xB[0]*x[99]*dwdp[0]-p[0]*x[0]*xB[100]*dwdp[0]-p[0]*xB[1]*x[99]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[99]*dwdp[0];
  qBdot[12] = p[0]*xB[0]*x[108]*dwdp[0]-p[0]*x[0]*xB[109]*dwdp[0]-p[0]*xB[1]*x[108]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[108]*dwdp[0];
  qBdot[13] = p[0]*xB[0]*x[117]*dwdp[0]-p[0]*x[0]*xB[118]*dwdp[0]-p[0]*xB[1]*x[117]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[117]*dwdp[0];
  qBdot[14] = p[0]*xB[0]*x[126]*dwdp[0]-p[0]*x[0]*xB[127]*dwdp[0]-p[0]*xB[1]*x[126]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[126]*dwdp[0];
  qBdot[15] = p[0]*xB[0]*x[135]*dwdp[0]-p[0]*x[0]*xB[136]*dwdp[0]-p[0]*xB[1]*x[135]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[135]*dwdp[0];
  qBdot[16] = p[0]*xB[0]*x[144]*dwdp[0]-p[0]*x[0]*xB[145]*dwdp[0]-p[0]*xB[1]*x[144]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[144]*dwdp[0];
  qBdot[17] = p[0]*xB[0]*x[153]*dwdp[0]-p[0]*x[0]*xB[154]*dwdp[0]-p[0]*xB[1]*x[153]*dwdp[0]+k[0]*p[0]*x[0]*w[2]*xB[153]*dwdp[0];

  } break;

  case 6: {
  qBdot[0] = -p[0]*x[0]*xB[1]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[0]*dwdp[6];
  qBdot[1] = xB[0]*dwdp[6]*(x[0]+p[0]*x[9])-xB[1]*dwdp[6]*(x[0]+p[0]*x[9])-p[0]*x[0]*xB[10]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[9]*dwdp[6];
  qBdot[2] = p[0]*x[18]*xB[0]*dwdp[6]-p[0]*x[0]*xB[19]*dwdp[6]-p[0]*x[18]*xB[1]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[18]*dwdp[6];
  qBdot[3] = p[0]*x[27]*xB[0]*dwdp[6]-p[0]*x[0]*xB[28]*dwdp[6]-p[0]*x[27]*xB[1]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[27]*dwdp[6];
  qBdot[4] = p[0]*x[36]*xB[0]*dwdp[6]-p[0]*x[0]*xB[37]*dwdp[6]-p[0]*x[36]*xB[1]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[36]*dwdp[6];
  qBdot[5] = p[0]*x[45]*xB[0]*dwdp[6]-p[0]*x[0]*xB[46]*dwdp[6]-p[0]*x[45]*xB[1]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[45]*dwdp[6];
  qBdot[6] = xB[0]*(p[0]*x[0]*dwdp[7]+p[0]*x[54]*dwdp[6])-xB[1]*(p[0]*x[0]*dwdp[7]+p[0]*x[54]*dwdp[6])-p[0]*x[0]*xB[55]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[54]*dwdp[6];
  qBdot[7] = xB[0]*(p[0]*x[0]*dwdp[8]+p[0]*x[63]*dwdp[6])-xB[1]*(p[0]*x[0]*dwdp[8]+p[0]*x[63]*dwdp[6])-p[0]*x[0]*xB[64]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[63]*dwdp[6];
  qBdot[8] = xB[0]*(p[0]*x[0]*dwdp[9]+p[0]*x[72]*dwdp[6])-xB[1]*(p[0]*x[0]*dwdp[9]+p[0]*x[72]*dwdp[6])-p[0]*x[0]*xB[73]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[72]*dwdp[6];
  qBdot[9] = xB[0]*(p[0]*x[0]*dwdp[10]+p[0]*x[81]*dwdp[6])-xB[1]*(p[0]*x[0]*dwdp[10]+p[0]*x[81]*dwdp[6])-p[0]*x[0]*xB[82]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[81]*dwdp[6];
  qBdot[10] = xB[0]*(p[0]*x[0]*dwdp[11]+p[0]*x[90]*dwdp[6])-xB[1]*(p[0]*x[0]*dwdp[11]+p[0]*x[90]*dwdp[6])-p[0]*x[0]*xB[91]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[90]*dwdp[6];
  qBdot[11] = p[0]*xB[0]*x[99]*dwdp[6]-p[0]*x[0]*xB[100]*dwdp[6]-p[0]*xB[1]*x[99]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[99]*dwdp[6];
  qBdot[12] = p[0]*xB[0]*x[108]*dwdp[6]-p[0]*x[0]*xB[109]*dwdp[6]-p[0]*xB[1]*x[108]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[108]*dwdp[6];
  qBdot[13] = p[0]*xB[0]*x[117]*dwdp[6]-p[0]*x[0]*xB[118]*dwdp[6]-p[0]*xB[1]*x[117]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[117]*dwdp[6];
  qBdot[14] = p[0]*xB[0]*x[126]*dwdp[6]-p[0]*x[0]*xB[127]*dwdp[6]-p[0]*xB[1]*x[126]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[126]*dwdp[6];
  qBdot[15] = p[0]*xB[0]*x[135]*dwdp[6]-p[0]*x[0]*xB[136]*dwdp[6]-p[0]*xB[1]*x[135]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[135]*dwdp[6];
  qBdot[16] = p[0]*xB[0]*x[144]*dwdp[6]-p[0]*x[0]*xB[145]*dwdp[6]-p[0]*xB[1]*x[144]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[144]*dwdp[6];
  qBdot[17] = p[0]*xB[0]*x[153]*dwdp[6]-p[0]*x[0]*xB[154]*dwdp[6]-p[0]*xB[1]*x[153]*dwdp[6]+k[0]*p[0]*x[0]*w[2]*xB[153]*dwdp[6];

  } break;

  case 7: {
  qBdot[0] = -p[0]*x[0]*xB[1]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[0]*dwdp[12];
  qBdot[1] = xB[0]*dwdp[12]*(x[0]+p[0]*x[9])-xB[1]*dwdp[12]*(x[0]+p[0]*x[9])-p[0]*x[0]*xB[10]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[9]*dwdp[12];
  qBdot[2] = p[0]*x[18]*xB[0]*dwdp[12]-p[0]*x[0]*xB[19]*dwdp[12]-p[0]*x[18]*xB[1]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[18]*dwdp[12];
  qBdot[3] = p[0]*x[27]*xB[0]*dwdp[12]-p[0]*x[0]*xB[28]*dwdp[12]-p[0]*x[27]*xB[1]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[27]*dwdp[12];
  qBdot[4] = p[0]*x[36]*xB[0]*dwdp[12]-p[0]*x[0]*xB[37]*dwdp[12]-p[0]*x[36]*xB[1]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[36]*dwdp[12];
  qBdot[5] = p[0]*x[45]*xB[0]*dwdp[12]-p[0]*x[0]*xB[46]*dwdp[12]-p[0]*x[45]*xB[1]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[45]*dwdp[12];
  qBdot[6] = xB[0]*(p[0]*x[0]*dwdp[13]+p[0]*x[54]*dwdp[12])-xB[1]*(p[0]*x[0]*dwdp[13]+p[0]*x[54]*dwdp[12])-p[0]*x[0]*xB[55]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[54]*dwdp[12];
  qBdot[7] = xB[0]*(p[0]*x[0]*dwdp[14]+p[0]*x[63]*dwdp[12])-xB[1]*(p[0]*x[0]*dwdp[14]+p[0]*x[63]*dwdp[12])-p[0]*x[0]*xB[64]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[63]*dwdp[12];
  qBdot[8] = xB[0]*(p[0]*x[0]*dwdp[15]+p[0]*x[72]*dwdp[12])-xB[1]*(p[0]*x[0]*dwdp[15]+p[0]*x[72]*dwdp[12])-p[0]*x[0]*xB[73]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[72]*dwdp[12];
  qBdot[9] = xB[0]*(p[0]*x[0]*dwdp[16]+p[0]*x[81]*dwdp[12])-xB[1]*(p[0]*x[0]*dwdp[16]+p[0]*x[81]*dwdp[12])-p[0]*x[0]*xB[82]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[81]*dwdp[12];
  qBdot[10] = xB[0]*(p[0]*x[0]*dwdp[17]+p[0]*x[90]*dwdp[12])-xB[1]*(p[0]*x[0]*dwdp[17]+p[0]*x[90]*dwdp[12])-p[0]*x[0]*xB[91]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[90]*dwdp[12];
  qBdot[11] = p[0]*xB[0]*x[99]*dwdp[12]-p[0]*x[0]*xB[100]*dwdp[12]-p[0]*xB[1]*x[99]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[99]*dwdp[12];
  qBdot[12] = p[0]*xB[0]*x[108]*dwdp[12]-p[0]*x[0]*xB[109]*dwdp[12]-p[0]*xB[1]*x[108]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[108]*dwdp[12];
  qBdot[13] = p[0]*xB[0]*x[117]*dwdp[12]-p[0]*x[0]*xB[118]*dwdp[12]-p[0]*xB[1]*x[117]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[117]*dwdp[12];
  qBdot[14] = p[0]*xB[0]*x[126]*dwdp[12]-p[0]*x[0]*xB[127]*dwdp[12]-p[0]*xB[1]*x[126]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[126]*dwdp[12];
  qBdot[15] = p[0]*xB[0]*x[135]*dwdp[12]-p[0]*x[0]*xB[136]*dwdp[12]-p[0]*xB[1]*x[135]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[135]*dwdp[12];
  qBdot[16] = p[0]*xB[0]*x[144]*dwdp[12]-p[0]*x[0]*xB[145]*dwdp[12]-p[0]*xB[1]*x[144]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[144]*dwdp[12];
  qBdot[17] = p[0]*xB[0]*x[153]*dwdp[12]-p[0]*x[0]*xB[154]*dwdp[12]-p[0]*xB[1]*x[153]*dwdp[12]+k[0]*p[0]*x[0]*w[2]*xB[153]*dwdp[12];

  } break;

  case 8: {
  qBdot[0] = -p[0]*x[0]*xB[1]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[0]*dwdp[18];
  qBdot[1] = xB[0]*dwdp[18]*(x[0]+p[0]*x[9])-xB[1]*dwdp[18]*(x[0]+p[0]*x[9])-p[0]*x[0]*xB[10]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[9]*dwdp[18];
  qBdot[2] = p[0]*x[18]*xB[0]*dwdp[18]-p[0]*x[0]*xB[19]*dwdp[18]-p[0]*x[18]*xB[1]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[18]*dwdp[18];
  qBdot[3] = p[0]*x[27]*xB[0]*dwdp[18]-p[0]*x[0]*xB[28]*dwdp[18]-p[0]*x[27]*xB[1]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[27]*dwdp[18];
  qBdot[4] = p[0]*x[36]*xB[0]*dwdp[18]-p[0]*x[0]*xB[37]*dwdp[18]-p[0]*x[36]*xB[1]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[36]*dwdp[18];
  qBdot[5] = p[0]*x[45]*xB[0]*dwdp[18]-p[0]*x[0]*xB[46]*dwdp[18]-p[0]*x[45]*xB[1]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[45]*dwdp[18];
  qBdot[6] = xB[0]*(p[0]*x[0]*dwdp[19]+p[0]*x[54]*dwdp[18])-xB[1]*(p[0]*x[0]*dwdp[19]+p[0]*x[54]*dwdp[18])-p[0]*x[0]*xB[55]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[54]*dwdp[18];
  qBdot[7] = xB[0]*(p[0]*x[0]*dwdp[20]+p[0]*x[63]*dwdp[18])-xB[1]*(p[0]*x[0]*dwdp[20]+p[0]*x[63]*dwdp[18])-p[0]*x[0]*xB[64]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[63]*dwdp[18];
  qBdot[8] = xB[0]*(p[0]*x[0]*dwdp[21]+p[0]*x[72]*dwdp[18])-xB[1]*(p[0]*x[0]*dwdp[21]+p[0]*x[72]*dwdp[18])-p[0]*x[0]*xB[73]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[72]*dwdp[18];
  qBdot[9] = xB[0]*(p[0]*x[0]*dwdp[22]+p[0]*x[81]*dwdp[18])-xB[1]*(p[0]*x[0]*dwdp[22]+p[0]*x[81]*dwdp[18])-p[0]*x[0]*xB[82]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[81]*dwdp[18];
  qBdot[10] = xB[0]*(p[0]*x[0]*dwdp[23]+p[0]*x[90]*dwdp[18])-xB[1]*(p[0]*x[0]*dwdp[23]+p[0]*x[90]*dwdp[18])-p[0]*x[0]*xB[91]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[90]*dwdp[18];
  qBdot[11] = p[0]*xB[0]*x[99]*dwdp[18]-p[0]*x[0]*xB[100]*dwdp[18]-p[0]*xB[1]*x[99]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[99]*dwdp[18];
  qBdot[12] = p[0]*xB[0]*x[108]*dwdp[18]-p[0]*x[0]*xB[109]*dwdp[18]-p[0]*xB[1]*x[108]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[108]*dwdp[18];
  qBdot[13] = p[0]*xB[0]*x[117]*dwdp[18]-p[0]*x[0]*xB[118]*dwdp[18]-p[0]*xB[1]*x[117]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[117]*dwdp[18];
  qBdot[14] = p[0]*xB[0]*x[126]*dwdp[18]-p[0]*x[0]*xB[127]*dwdp[18]-p[0]*xB[1]*x[126]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[126]*dwdp[18];
  qBdot[15] = p[0]*xB[0]*x[135]*dwdp[18]-p[0]*x[0]*xB[136]*dwdp[18]-p[0]*xB[1]*x[135]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[135]*dwdp[18];
  qBdot[16] = p[0]*xB[0]*x[144]*dwdp[18]-p[0]*x[0]*xB[145]*dwdp[18]-p[0]*xB[1]*x[144]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[144]*dwdp[18];
  qBdot[17] = p[0]*xB[0]*x[153]*dwdp[18]-p[0]*x[0]*xB[154]*dwdp[18]-p[0]*xB[1]*x[153]*dwdp[18]+k[0]*p[0]*x[0]*w[2]*xB[153]*dwdp[18];

  } break;

  case 9: {
  qBdot[0] = -p[0]*x[0]*xB[1]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[0]*dwdp[24];
  qBdot[1] = xB[0]*dwdp[24]*(x[0]+p[0]*x[9])-xB[1]*dwdp[24]*(x[0]+p[0]*x[9])-p[0]*x[0]*xB[10]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[9]*dwdp[24];
  qBdot[2] = p[0]*x[18]*xB[0]*dwdp[24]-p[0]*x[0]*xB[19]*dwdp[24]-p[0]*x[18]*xB[1]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[18]*dwdp[24];
  qBdot[3] = p[0]*x[27]*xB[0]*dwdp[24]-p[0]*x[0]*xB[28]*dwdp[24]-p[0]*x[27]*xB[1]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[27]*dwdp[24];
  qBdot[4] = p[0]*x[36]*xB[0]*dwdp[24]-p[0]*x[0]*xB[37]*dwdp[24]-p[0]*x[36]*xB[1]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[36]*dwdp[24];
  qBdot[5] = p[0]*x[45]*xB[0]*dwdp[24]-p[0]*x[0]*xB[46]*dwdp[24]-p[0]*x[45]*xB[1]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[45]*dwdp[24];
  qBdot[6] = xB[0]*(p[0]*x[0]*dwdp[25]+p[0]*x[54]*dwdp[24])-xB[1]*(p[0]*x[0]*dwdp[25]+p[0]*x[54]*dwdp[24])-p[0]*x[0]*xB[55]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[54]*dwdp[24];
  qBdot[7] = xB[0]*(p[0]*x[0]*dwdp[26]+p[0]*x[63]*dwdp[24])-xB[1]*(p[0]*x[0]*dwdp[26]+p[0]*x[63]*dwdp[24])-p[0]*x[0]*xB[64]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[63]*dwdp[24];
  qBdot[8] = xB[0]*(p[0]*x[0]*dwdp[27]+p[0]*x[72]*dwdp[24])-xB[1]*(p[0]*x[0]*dwdp[27]+p[0]*x[72]*dwdp[24])-p[0]*x[0]*xB[73]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[72]*dwdp[24];
  qBdot[9] = xB[0]*(p[0]*x[0]*dwdp[28]+p[0]*x[81]*dwdp[24])-xB[1]*(p[0]*x[0]*dwdp[28]+p[0]*x[81]*dwdp[24])-p[0]*x[0]*xB[82]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[81]*dwdp[24];
  qBdot[10] = xB[0]*(p[0]*x[0]*dwdp[29]+p[0]*x[90]*dwdp[24])-xB[1]*(p[0]*x[0]*dwdp[29]+p[0]*x[90]*dwdp[24])-p[0]*x[0]*xB[91]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[90]*dwdp[24];
  qBdot[11] = p[0]*xB[0]*x[99]*dwdp[24]-p[0]*x[0]*xB[100]*dwdp[24]-p[0]*xB[1]*x[99]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[99]*dwdp[24];
  qBdot[12] = p[0]*xB[0]*x[108]*dwdp[24]-p[0]*x[0]*xB[109]*dwdp[24]-p[0]*xB[1]*x[108]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[108]*dwdp[24];
  qBdot[13] = p[0]*xB[0]*x[117]*dwdp[24]-p[0]*x[0]*xB[118]*dwdp[24]-p[0]*xB[1]*x[117]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[117]*dwdp[24];
  qBdot[14] = p[0]*xB[0]*x[126]*dwdp[24]-p[0]*x[0]*xB[127]*dwdp[24]-p[0]*xB[1]*x[126]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[126]*dwdp[24];
  qBdot[15] = p[0]*xB[0]*x[135]*dwdp[24]-p[0]*x[0]*xB[136]*dwdp[24]-p[0]*xB[1]*x[135]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[135]*dwdp[24];
  qBdot[16] = p[0]*xB[0]*x[144]*dwdp[24]-p[0]*x[0]*xB[145]*dwdp[24]-p[0]*xB[1]*x[144]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[144]*dwdp[24];
  qBdot[17] = p[0]*xB[0]*x[153]*dwdp[24]-p[0]*x[0]*xB[154]*dwdp[24]-p[0]*xB[1]*x[153]*dwdp[24]+k[0]*p[0]*x[0]*w[2]*xB[153]*dwdp[24];

  } break;

}
}

