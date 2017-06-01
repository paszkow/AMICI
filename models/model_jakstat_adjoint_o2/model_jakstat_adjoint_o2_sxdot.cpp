
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include "model_jakstat_adjoint_o2_JSparse.h"
#include "model_jakstat_adjoint_o2_dxdotdp.h"
#include "model_jakstat_adjoint_o2_w.h"

int sxdot_model_jakstat_adjoint_o2(int Ns, realtype t, N_Vector x, N_Vector xdot,int ip,  N_Vector sx, N_Vector sxdot, void *user_data, N_Vector tmp1, N_Vector tmp2) {
int status = 0;
UserData *udata = (UserData*) user_data;
realtype *x_tmp = N_VGetArrayPointer(x);
realtype *sx_tmp = N_VGetArrayPointer(sx);
realtype *sxdot_tmp = N_VGetArrayPointer(sxdot);
realtype *xdot_tmp = N_VGetArrayPointer(xdot);
memset(sxdot_tmp,0,sizeof(realtype)*162);
if(ip == 0) {
    status = JSparse_model_jakstat_adjoint_o2(t,x,xdot,udata->J,user_data,NULL,NULL,NULL);
    status = dxdotdp_model_jakstat_adjoint_o2(t,udata->dxdotdp,x,NULL,user_data);
}
  sxdot_tmp[0] = udata->dxdotdp[0 + ip*udata->nx]+sx_tmp[0]*udata->J->data[0]+sx_tmp[8]*udata->J->data[74];
  sxdot_tmp[1] = udata->dxdotdp[1 + ip*udata->nx]+sx_tmp[0]*udata->J->data[1]+sx_tmp[1]*udata->J->data[14];
  sxdot_tmp[2] = udata->dxdotdp[2 + ip*udata->nx]+sx_tmp[1]*udata->J->data[15]+sx_tmp[2]*udata->J->data[50];
  sxdot_tmp[3] = udata->dxdotdp[3 + ip*udata->nx]+sx_tmp[2]*udata->J->data[51]+sx_tmp[3]*udata->J->data[54];
  sxdot_tmp[4] = udata->dxdotdp[4 + ip*udata->nx]+sx_tmp[3]*udata->J->data[55]+sx_tmp[4]*udata->J->data[58];
  sxdot_tmp[5] = udata->dxdotdp[5 + ip*udata->nx]+sx_tmp[4]*udata->J->data[59]+sx_tmp[5]*udata->J->data[62];
  sxdot_tmp[6] = udata->dxdotdp[6 + ip*udata->nx]+sx_tmp[5]*udata->J->data[63]+sx_tmp[6]*udata->J->data[66];
  sxdot_tmp[7] = udata->dxdotdp[7 + ip*udata->nx]+sx_tmp[6]*udata->J->data[67]+sx_tmp[7]*udata->J->data[70];
  sxdot_tmp[8] = udata->dxdotdp[8 + ip*udata->nx]+sx_tmp[7]*udata->J->data[71]+sx_tmp[8]*udata->J->data[75];
  sxdot_tmp[9] = udata->dxdotdp[9 + ip*udata->nx]+sx_tmp[0]*udata->J->data[2]+sx_tmp[9]*udata->J->data[78]+sx_tmp[17]*udata->J->data[94];
  sxdot_tmp[10] = udata->dxdotdp[10 + ip*udata->nx]+sx_tmp[0]*udata->J->data[3]+sx_tmp[1]*udata->J->data[16]+sx_tmp[9]*udata->J->data[79]+sx_tmp[10]*udata->J->data[80];
  sxdot_tmp[11] = udata->dxdotdp[11 + ip*udata->nx]+sx_tmp[1]*udata->J->data[17]+sx_tmp[10]*udata->J->data[81]+sx_tmp[11]*udata->J->data[82];
  sxdot_tmp[12] = udata->dxdotdp[12 + ip*udata->nx]+sx_tmp[11]*udata->J->data[83]+sx_tmp[12]*udata->J->data[84];
  sxdot_tmp[13] = udata->dxdotdp[13 + ip*udata->nx]+sx_tmp[12]*udata->J->data[85]+sx_tmp[13]*udata->J->data[86];
  sxdot_tmp[14] = udata->dxdotdp[14 + ip*udata->nx]+sx_tmp[13]*udata->J->data[87]+sx_tmp[14]*udata->J->data[88];
  sxdot_tmp[15] = udata->dxdotdp[15 + ip*udata->nx]+sx_tmp[14]*udata->J->data[89]+sx_tmp[15]*udata->J->data[90];
  sxdot_tmp[16] = udata->dxdotdp[16 + ip*udata->nx]+sx_tmp[15]*udata->J->data[91]+sx_tmp[16]*udata->J->data[92];
  sxdot_tmp[17] = udata->dxdotdp[17 + ip*udata->nx]+sx_tmp[16]*udata->J->data[93]+sx_tmp[17]*udata->J->data[95];
  sxdot_tmp[18] = udata->dxdotdp[18 + ip*udata->nx]+sx_tmp[18]*udata->J->data[96]+sx_tmp[26]*udata->J->data[112];
  sxdot_tmp[19] = udata->dxdotdp[19 + ip*udata->nx]+sx_tmp[1]*udata->J->data[18]+sx_tmp[18]*udata->J->data[97]+sx_tmp[19]*udata->J->data[98];
  sxdot_tmp[20] = udata->dxdotdp[20 + ip*udata->nx]+sx_tmp[1]*udata->J->data[19]+sx_tmp[19]*udata->J->data[99]+sx_tmp[20]*udata->J->data[100];
  sxdot_tmp[21] = udata->dxdotdp[21 + ip*udata->nx]+sx_tmp[20]*udata->J->data[101]+sx_tmp[21]*udata->J->data[102];
  sxdot_tmp[22] = udata->dxdotdp[22 + ip*udata->nx]+sx_tmp[21]*udata->J->data[103]+sx_tmp[22]*udata->J->data[104];
  sxdot_tmp[23] = udata->dxdotdp[23 + ip*udata->nx]+sx_tmp[22]*udata->J->data[105]+sx_tmp[23]*udata->J->data[106];
  sxdot_tmp[24] = udata->dxdotdp[24 + ip*udata->nx]+sx_tmp[23]*udata->J->data[107]+sx_tmp[24]*udata->J->data[108];
  sxdot_tmp[25] = udata->dxdotdp[25 + ip*udata->nx]+sx_tmp[24]*udata->J->data[109]+sx_tmp[25]*udata->J->data[110];
  sxdot_tmp[26] = udata->dxdotdp[26 + ip*udata->nx]+sx_tmp[25]*udata->J->data[111]+sx_tmp[26]*udata->J->data[113];
  sxdot_tmp[27] = udata->dxdotdp[27 + ip*udata->nx]+sx_tmp[27]*udata->J->data[114]+sx_tmp[35]*udata->J->data[130];
  sxdot_tmp[28] = udata->dxdotdp[28 + ip*udata->nx]+sx_tmp[1]*udata->J->data[20]+sx_tmp[27]*udata->J->data[115]+sx_tmp[28]*udata->J->data[116];
  sxdot_tmp[29] = udata->dxdotdp[29 + ip*udata->nx]+sx_tmp[1]*udata->J->data[21]+sx_tmp[2]*udata->J->data[52]+sx_tmp[28]*udata->J->data[117]+sx_tmp[29]*udata->J->data[118];
  sxdot_tmp[30] = udata->dxdotdp[30 + ip*udata->nx]+sx_tmp[2]*udata->J->data[53]+sx_tmp[29]*udata->J->data[119]+sx_tmp[30]*udata->J->data[120];
  sxdot_tmp[31] = udata->dxdotdp[31 + ip*udata->nx]+sx_tmp[30]*udata->J->data[121]+sx_tmp[31]*udata->J->data[122];
  sxdot_tmp[32] = udata->dxdotdp[32 + ip*udata->nx]+sx_tmp[31]*udata->J->data[123]+sx_tmp[32]*udata->J->data[124];
  sxdot_tmp[33] = udata->dxdotdp[33 + ip*udata->nx]+sx_tmp[32]*udata->J->data[125]+sx_tmp[33]*udata->J->data[126];
  sxdot_tmp[34] = udata->dxdotdp[34 + ip*udata->nx]+sx_tmp[33]*udata->J->data[127]+sx_tmp[34]*udata->J->data[128];
  sxdot_tmp[35] = udata->dxdotdp[35 + ip*udata->nx]+sx_tmp[34]*udata->J->data[129]+sx_tmp[35]*udata->J->data[131];
  sxdot_tmp[36] = udata->dxdotdp[36 + ip*udata->nx]+sx_tmp[8]*udata->J->data[76]+sx_tmp[36]*udata->J->data[132]+sx_tmp[44]*udata->J->data[148];
  sxdot_tmp[37] = udata->dxdotdp[37 + ip*udata->nx]+sx_tmp[1]*udata->J->data[22]+sx_tmp[36]*udata->J->data[133]+sx_tmp[37]*udata->J->data[134];
  sxdot_tmp[38] = udata->dxdotdp[38 + ip*udata->nx]+sx_tmp[1]*udata->J->data[23]+sx_tmp[37]*udata->J->data[135]+sx_tmp[38]*udata->J->data[136];
  sxdot_tmp[39] = udata->dxdotdp[39 + ip*udata->nx]+sx_tmp[3]*udata->J->data[56]+sx_tmp[38]*udata->J->data[137]+sx_tmp[39]*udata->J->data[138];
  sxdot_tmp[40] = udata->dxdotdp[40 + ip*udata->nx]+sx_tmp[3]*udata->J->data[57]+sx_tmp[4]*udata->J->data[60]+sx_tmp[39]*udata->J->data[139]+sx_tmp[40]*udata->J->data[140];
  sxdot_tmp[41] = udata->dxdotdp[41 + ip*udata->nx]+sx_tmp[4]*udata->J->data[61]+sx_tmp[5]*udata->J->data[64]+sx_tmp[40]*udata->J->data[141]+sx_tmp[41]*udata->J->data[142];
  sxdot_tmp[42] = udata->dxdotdp[42 + ip*udata->nx]+sx_tmp[5]*udata->J->data[65]+sx_tmp[6]*udata->J->data[68]+sx_tmp[41]*udata->J->data[143]+sx_tmp[42]*udata->J->data[144];
  sxdot_tmp[43] = udata->dxdotdp[43 + ip*udata->nx]+sx_tmp[6]*udata->J->data[69]+sx_tmp[7]*udata->J->data[72]+sx_tmp[42]*udata->J->data[145]+sx_tmp[43]*udata->J->data[146];
  sxdot_tmp[44] = udata->dxdotdp[44 + ip*udata->nx]+sx_tmp[7]*udata->J->data[73]+sx_tmp[8]*udata->J->data[77]+sx_tmp[43]*udata->J->data[147]+sx_tmp[44]*udata->J->data[149];
  sxdot_tmp[45] = udata->dxdotdp[45 + ip*udata->nx]+sx_tmp[45]*udata->J->data[150]+sx_tmp[53]*udata->J->data[166];
  sxdot_tmp[46] = udata->dxdotdp[46 + ip*udata->nx]+sx_tmp[1]*udata->J->data[24]+sx_tmp[45]*udata->J->data[151]+sx_tmp[46]*udata->J->data[152];
  sxdot_tmp[47] = udata->dxdotdp[47 + ip*udata->nx]+sx_tmp[1]*udata->J->data[25]+sx_tmp[46]*udata->J->data[153]+sx_tmp[47]*udata->J->data[154];
  sxdot_tmp[48] = udata->dxdotdp[48 + ip*udata->nx]+sx_tmp[47]*udata->J->data[155]+sx_tmp[48]*udata->J->data[156];
  sxdot_tmp[49] = udata->dxdotdp[49 + ip*udata->nx]+sx_tmp[48]*udata->J->data[157]+sx_tmp[49]*udata->J->data[158];
  sxdot_tmp[50] = udata->dxdotdp[50 + ip*udata->nx]+sx_tmp[49]*udata->J->data[159]+sx_tmp[50]*udata->J->data[160];
  sxdot_tmp[51] = udata->dxdotdp[51 + ip*udata->nx]+sx_tmp[50]*udata->J->data[161]+sx_tmp[51]*udata->J->data[162];
  sxdot_tmp[52] = udata->dxdotdp[52 + ip*udata->nx]+sx_tmp[51]*udata->J->data[163]+sx_tmp[52]*udata->J->data[164];
  sxdot_tmp[53] = udata->dxdotdp[53 + ip*udata->nx]+sx_tmp[52]*udata->J->data[165]+sx_tmp[53]*udata->J->data[167];
  sxdot_tmp[54] = udata->dxdotdp[54 + ip*udata->nx]+sx_tmp[0]*udata->J->data[4]+sx_tmp[54]*udata->J->data[168]+sx_tmp[62]*udata->J->data[184];
  sxdot_tmp[55] = udata->dxdotdp[55 + ip*udata->nx]+sx_tmp[0]*udata->J->data[5]+sx_tmp[1]*udata->J->data[26]+sx_tmp[54]*udata->J->data[169]+sx_tmp[55]*udata->J->data[170];
  sxdot_tmp[56] = udata->dxdotdp[56 + ip*udata->nx]+sx_tmp[1]*udata->J->data[27]+sx_tmp[55]*udata->J->data[171]+sx_tmp[56]*udata->J->data[172];
  sxdot_tmp[57] = udata->dxdotdp[57 + ip*udata->nx]+sx_tmp[56]*udata->J->data[173]+sx_tmp[57]*udata->J->data[174];
  sxdot_tmp[58] = udata->dxdotdp[58 + ip*udata->nx]+sx_tmp[57]*udata->J->data[175]+sx_tmp[58]*udata->J->data[176];
  sxdot_tmp[59] = udata->dxdotdp[59 + ip*udata->nx]+sx_tmp[58]*udata->J->data[177]+sx_tmp[59]*udata->J->data[178];
  sxdot_tmp[60] = udata->dxdotdp[60 + ip*udata->nx]+sx_tmp[59]*udata->J->data[179]+sx_tmp[60]*udata->J->data[180];
  sxdot_tmp[61] = udata->dxdotdp[61 + ip*udata->nx]+sx_tmp[60]*udata->J->data[181]+sx_tmp[61]*udata->J->data[182];
  sxdot_tmp[62] = udata->dxdotdp[62 + ip*udata->nx]+sx_tmp[61]*udata->J->data[183]+sx_tmp[62]*udata->J->data[185];
  sxdot_tmp[63] = udata->dxdotdp[63 + ip*udata->nx]+sx_tmp[0]*udata->J->data[6]+sx_tmp[63]*udata->J->data[186]+sx_tmp[71]*udata->J->data[202];
  sxdot_tmp[64] = udata->dxdotdp[64 + ip*udata->nx]+sx_tmp[0]*udata->J->data[7]+sx_tmp[1]*udata->J->data[28]+sx_tmp[63]*udata->J->data[187]+sx_tmp[64]*udata->J->data[188];
  sxdot_tmp[65] = udata->dxdotdp[65 + ip*udata->nx]+sx_tmp[1]*udata->J->data[29]+sx_tmp[64]*udata->J->data[189]+sx_tmp[65]*udata->J->data[190];
  sxdot_tmp[66] = udata->dxdotdp[66 + ip*udata->nx]+sx_tmp[65]*udata->J->data[191]+sx_tmp[66]*udata->J->data[192];
  sxdot_tmp[67] = udata->dxdotdp[67 + ip*udata->nx]+sx_tmp[66]*udata->J->data[193]+sx_tmp[67]*udata->J->data[194];
  sxdot_tmp[68] = udata->dxdotdp[68 + ip*udata->nx]+sx_tmp[67]*udata->J->data[195]+sx_tmp[68]*udata->J->data[196];
  sxdot_tmp[69] = udata->dxdotdp[69 + ip*udata->nx]+sx_tmp[68]*udata->J->data[197]+sx_tmp[69]*udata->J->data[198];
  sxdot_tmp[70] = udata->dxdotdp[70 + ip*udata->nx]+sx_tmp[69]*udata->J->data[199]+sx_tmp[70]*udata->J->data[200];
  sxdot_tmp[71] = udata->dxdotdp[71 + ip*udata->nx]+sx_tmp[70]*udata->J->data[201]+sx_tmp[71]*udata->J->data[203];
  sxdot_tmp[72] = udata->dxdotdp[72 + ip*udata->nx]+sx_tmp[0]*udata->J->data[8]+sx_tmp[72]*udata->J->data[204]+sx_tmp[80]*udata->J->data[220];
  sxdot_tmp[73] = udata->dxdotdp[73 + ip*udata->nx]+sx_tmp[0]*udata->J->data[9]+sx_tmp[1]*udata->J->data[30]+sx_tmp[72]*udata->J->data[205]+sx_tmp[73]*udata->J->data[206];
  sxdot_tmp[74] = udata->dxdotdp[74 + ip*udata->nx]+sx_tmp[1]*udata->J->data[31]+sx_tmp[73]*udata->J->data[207]+sx_tmp[74]*udata->J->data[208];
  sxdot_tmp[75] = udata->dxdotdp[75 + ip*udata->nx]+sx_tmp[74]*udata->J->data[209]+sx_tmp[75]*udata->J->data[210];
  sxdot_tmp[76] = udata->dxdotdp[76 + ip*udata->nx]+sx_tmp[75]*udata->J->data[211]+sx_tmp[76]*udata->J->data[212];
  sxdot_tmp[77] = udata->dxdotdp[77 + ip*udata->nx]+sx_tmp[76]*udata->J->data[213]+sx_tmp[77]*udata->J->data[214];
  sxdot_tmp[78] = udata->dxdotdp[78 + ip*udata->nx]+sx_tmp[77]*udata->J->data[215]+sx_tmp[78]*udata->J->data[216];
  sxdot_tmp[79] = udata->dxdotdp[79 + ip*udata->nx]+sx_tmp[78]*udata->J->data[217]+sx_tmp[79]*udata->J->data[218];
  sxdot_tmp[80] = udata->dxdotdp[80 + ip*udata->nx]+sx_tmp[79]*udata->J->data[219]+sx_tmp[80]*udata->J->data[221];
  sxdot_tmp[81] = udata->dxdotdp[81 + ip*udata->nx]+sx_tmp[0]*udata->J->data[10]+sx_tmp[81]*udata->J->data[222]+sx_tmp[89]*udata->J->data[238];
  sxdot_tmp[82] = udata->dxdotdp[82 + ip*udata->nx]+sx_tmp[0]*udata->J->data[11]+sx_tmp[1]*udata->J->data[32]+sx_tmp[81]*udata->J->data[223]+sx_tmp[82]*udata->J->data[224];
  sxdot_tmp[83] = udata->dxdotdp[83 + ip*udata->nx]+sx_tmp[1]*udata->J->data[33]+sx_tmp[82]*udata->J->data[225]+sx_tmp[83]*udata->J->data[226];
  sxdot_tmp[84] = udata->dxdotdp[84 + ip*udata->nx]+sx_tmp[83]*udata->J->data[227]+sx_tmp[84]*udata->J->data[228];
  sxdot_tmp[85] = udata->dxdotdp[85 + ip*udata->nx]+sx_tmp[84]*udata->J->data[229]+sx_tmp[85]*udata->J->data[230];
  sxdot_tmp[86] = udata->dxdotdp[86 + ip*udata->nx]+sx_tmp[85]*udata->J->data[231]+sx_tmp[86]*udata->J->data[232];
  sxdot_tmp[87] = udata->dxdotdp[87 + ip*udata->nx]+sx_tmp[86]*udata->J->data[233]+sx_tmp[87]*udata->J->data[234];
  sxdot_tmp[88] = udata->dxdotdp[88 + ip*udata->nx]+sx_tmp[87]*udata->J->data[235]+sx_tmp[88]*udata->J->data[236];
  sxdot_tmp[89] = udata->dxdotdp[89 + ip*udata->nx]+sx_tmp[88]*udata->J->data[237]+sx_tmp[89]*udata->J->data[239];
  sxdot_tmp[90] = udata->dxdotdp[90 + ip*udata->nx]+sx_tmp[0]*udata->J->data[12]+sx_tmp[90]*udata->J->data[240]+sx_tmp[98]*udata->J->data[256];
  sxdot_tmp[91] = udata->dxdotdp[91 + ip*udata->nx]+sx_tmp[0]*udata->J->data[13]+sx_tmp[1]*udata->J->data[34]+sx_tmp[90]*udata->J->data[241]+sx_tmp[91]*udata->J->data[242];
  sxdot_tmp[92] = udata->dxdotdp[92 + ip*udata->nx]+sx_tmp[1]*udata->J->data[35]+sx_tmp[91]*udata->J->data[243]+sx_tmp[92]*udata->J->data[244];
  sxdot_tmp[93] = udata->dxdotdp[93 + ip*udata->nx]+sx_tmp[92]*udata->J->data[245]+sx_tmp[93]*udata->J->data[246];
  sxdot_tmp[94] = udata->dxdotdp[94 + ip*udata->nx]+sx_tmp[93]*udata->J->data[247]+sx_tmp[94]*udata->J->data[248];
  sxdot_tmp[95] = udata->dxdotdp[95 + ip*udata->nx]+sx_tmp[94]*udata->J->data[249]+sx_tmp[95]*udata->J->data[250];
  sxdot_tmp[96] = udata->dxdotdp[96 + ip*udata->nx]+sx_tmp[95]*udata->J->data[251]+sx_tmp[96]*udata->J->data[252];
  sxdot_tmp[97] = udata->dxdotdp[97 + ip*udata->nx]+sx_tmp[96]*udata->J->data[253]+sx_tmp[97]*udata->J->data[254];
  sxdot_tmp[98] = udata->dxdotdp[98 + ip*udata->nx]+sx_tmp[97]*udata->J->data[255]+sx_tmp[98]*udata->J->data[257];
  sxdot_tmp[99] = udata->dxdotdp[99 + ip*udata->nx]+sx_tmp[99]*udata->J->data[258]+sx_tmp[107]*udata->J->data[274];
  sxdot_tmp[100] = udata->dxdotdp[100 + ip*udata->nx]+sx_tmp[1]*udata->J->data[36]+sx_tmp[99]*udata->J->data[259]+sx_tmp[100]*udata->J->data[260];
  sxdot_tmp[101] = udata->dxdotdp[101 + ip*udata->nx]+sx_tmp[1]*udata->J->data[37]+sx_tmp[100]*udata->J->data[261]+sx_tmp[101]*udata->J->data[262];
  sxdot_tmp[102] = udata->dxdotdp[102 + ip*udata->nx]+sx_tmp[101]*udata->J->data[263]+sx_tmp[102]*udata->J->data[264];
  sxdot_tmp[103] = udata->dxdotdp[103 + ip*udata->nx]+sx_tmp[102]*udata->J->data[265]+sx_tmp[103]*udata->J->data[266];
  sxdot_tmp[104] = udata->dxdotdp[104 + ip*udata->nx]+sx_tmp[103]*udata->J->data[267]+sx_tmp[104]*udata->J->data[268];
  sxdot_tmp[105] = udata->dxdotdp[105 + ip*udata->nx]+sx_tmp[104]*udata->J->data[269]+sx_tmp[105]*udata->J->data[270];
  sxdot_tmp[106] = udata->dxdotdp[106 + ip*udata->nx]+sx_tmp[105]*udata->J->data[271]+sx_tmp[106]*udata->J->data[272];
  sxdot_tmp[107] = udata->dxdotdp[107 + ip*udata->nx]+sx_tmp[106]*udata->J->data[273]+sx_tmp[107]*udata->J->data[275];
  sxdot_tmp[108] = udata->dxdotdp[108 + ip*udata->nx]+sx_tmp[108]*udata->J->data[276]+sx_tmp[116]*udata->J->data[292];
  sxdot_tmp[109] = udata->dxdotdp[109 + ip*udata->nx]+sx_tmp[1]*udata->J->data[38]+sx_tmp[108]*udata->J->data[277]+sx_tmp[109]*udata->J->data[278];
  sxdot_tmp[110] = udata->dxdotdp[110 + ip*udata->nx]+sx_tmp[1]*udata->J->data[39]+sx_tmp[109]*udata->J->data[279]+sx_tmp[110]*udata->J->data[280];
  sxdot_tmp[111] = udata->dxdotdp[111 + ip*udata->nx]+sx_tmp[110]*udata->J->data[281]+sx_tmp[111]*udata->J->data[282];
  sxdot_tmp[112] = udata->dxdotdp[112 + ip*udata->nx]+sx_tmp[111]*udata->J->data[283]+sx_tmp[112]*udata->J->data[284];
  sxdot_tmp[113] = udata->dxdotdp[113 + ip*udata->nx]+sx_tmp[112]*udata->J->data[285]+sx_tmp[113]*udata->J->data[286];
  sxdot_tmp[114] = udata->dxdotdp[114 + ip*udata->nx]+sx_tmp[113]*udata->J->data[287]+sx_tmp[114]*udata->J->data[288];
  sxdot_tmp[115] = udata->dxdotdp[115 + ip*udata->nx]+sx_tmp[114]*udata->J->data[289]+sx_tmp[115]*udata->J->data[290];
  sxdot_tmp[116] = udata->dxdotdp[116 + ip*udata->nx]+sx_tmp[115]*udata->J->data[291]+sx_tmp[116]*udata->J->data[293];
  sxdot_tmp[117] = udata->dxdotdp[117 + ip*udata->nx]+sx_tmp[117]*udata->J->data[294]+sx_tmp[125]*udata->J->data[310];
  sxdot_tmp[118] = udata->dxdotdp[118 + ip*udata->nx]+sx_tmp[1]*udata->J->data[40]+sx_tmp[117]*udata->J->data[295]+sx_tmp[118]*udata->J->data[296];
  sxdot_tmp[119] = udata->dxdotdp[119 + ip*udata->nx]+sx_tmp[1]*udata->J->data[41]+sx_tmp[118]*udata->J->data[297]+sx_tmp[119]*udata->J->data[298];
  sxdot_tmp[120] = udata->dxdotdp[120 + ip*udata->nx]+sx_tmp[119]*udata->J->data[299]+sx_tmp[120]*udata->J->data[300];
  sxdot_tmp[121] = udata->dxdotdp[121 + ip*udata->nx]+sx_tmp[120]*udata->J->data[301]+sx_tmp[121]*udata->J->data[302];
  sxdot_tmp[122] = udata->dxdotdp[122 + ip*udata->nx]+sx_tmp[121]*udata->J->data[303]+sx_tmp[122]*udata->J->data[304];
  sxdot_tmp[123] = udata->dxdotdp[123 + ip*udata->nx]+sx_tmp[122]*udata->J->data[305]+sx_tmp[123]*udata->J->data[306];
  sxdot_tmp[124] = udata->dxdotdp[124 + ip*udata->nx]+sx_tmp[123]*udata->J->data[307]+sx_tmp[124]*udata->J->data[308];
  sxdot_tmp[125] = udata->dxdotdp[125 + ip*udata->nx]+sx_tmp[124]*udata->J->data[309]+sx_tmp[125]*udata->J->data[311];
  sxdot_tmp[126] = udata->dxdotdp[126 + ip*udata->nx]+sx_tmp[126]*udata->J->data[312]+sx_tmp[134]*udata->J->data[328];
  sxdot_tmp[127] = udata->dxdotdp[127 + ip*udata->nx]+sx_tmp[1]*udata->J->data[42]+sx_tmp[126]*udata->J->data[313]+sx_tmp[127]*udata->J->data[314];
  sxdot_tmp[128] = udata->dxdotdp[128 + ip*udata->nx]+sx_tmp[1]*udata->J->data[43]+sx_tmp[127]*udata->J->data[315]+sx_tmp[128]*udata->J->data[316];
  sxdot_tmp[129] = udata->dxdotdp[129 + ip*udata->nx]+sx_tmp[128]*udata->J->data[317]+sx_tmp[129]*udata->J->data[318];
  sxdot_tmp[130] = udata->dxdotdp[130 + ip*udata->nx]+sx_tmp[129]*udata->J->data[319]+sx_tmp[130]*udata->J->data[320];
  sxdot_tmp[131] = udata->dxdotdp[131 + ip*udata->nx]+sx_tmp[130]*udata->J->data[321]+sx_tmp[131]*udata->J->data[322];
  sxdot_tmp[132] = udata->dxdotdp[132 + ip*udata->nx]+sx_tmp[131]*udata->J->data[323]+sx_tmp[132]*udata->J->data[324];
  sxdot_tmp[133] = udata->dxdotdp[133 + ip*udata->nx]+sx_tmp[132]*udata->J->data[325]+sx_tmp[133]*udata->J->data[326];
  sxdot_tmp[134] = udata->dxdotdp[134 + ip*udata->nx]+sx_tmp[133]*udata->J->data[327]+sx_tmp[134]*udata->J->data[329];
  sxdot_tmp[135] = udata->dxdotdp[135 + ip*udata->nx]+sx_tmp[135]*udata->J->data[330]+sx_tmp[143]*udata->J->data[346];
  sxdot_tmp[136] = udata->dxdotdp[136 + ip*udata->nx]+sx_tmp[1]*udata->J->data[44]+sx_tmp[135]*udata->J->data[331]+sx_tmp[136]*udata->J->data[332];
  sxdot_tmp[137] = udata->dxdotdp[137 + ip*udata->nx]+sx_tmp[1]*udata->J->data[45]+sx_tmp[136]*udata->J->data[333]+sx_tmp[137]*udata->J->data[334];
  sxdot_tmp[138] = udata->dxdotdp[138 + ip*udata->nx]+sx_tmp[137]*udata->J->data[335]+sx_tmp[138]*udata->J->data[336];
  sxdot_tmp[139] = udata->dxdotdp[139 + ip*udata->nx]+sx_tmp[138]*udata->J->data[337]+sx_tmp[139]*udata->J->data[338];
  sxdot_tmp[140] = udata->dxdotdp[140 + ip*udata->nx]+sx_tmp[139]*udata->J->data[339]+sx_tmp[140]*udata->J->data[340];
  sxdot_tmp[141] = udata->dxdotdp[141 + ip*udata->nx]+sx_tmp[140]*udata->J->data[341]+sx_tmp[141]*udata->J->data[342];
  sxdot_tmp[142] = udata->dxdotdp[142 + ip*udata->nx]+sx_tmp[141]*udata->J->data[343]+sx_tmp[142]*udata->J->data[344];
  sxdot_tmp[143] = udata->dxdotdp[143 + ip*udata->nx]+sx_tmp[142]*udata->J->data[345]+sx_tmp[143]*udata->J->data[347];
  sxdot_tmp[144] = udata->dxdotdp[144 + ip*udata->nx]+sx_tmp[144]*udata->J->data[348]+sx_tmp[152]*udata->J->data[364];
  sxdot_tmp[145] = udata->dxdotdp[145 + ip*udata->nx]+sx_tmp[1]*udata->J->data[46]+sx_tmp[144]*udata->J->data[349]+sx_tmp[145]*udata->J->data[350];
  sxdot_tmp[146] = udata->dxdotdp[146 + ip*udata->nx]+sx_tmp[1]*udata->J->data[47]+sx_tmp[145]*udata->J->data[351]+sx_tmp[146]*udata->J->data[352];
  sxdot_tmp[147] = udata->dxdotdp[147 + ip*udata->nx]+sx_tmp[146]*udata->J->data[353]+sx_tmp[147]*udata->J->data[354];
  sxdot_tmp[148] = udata->dxdotdp[148 + ip*udata->nx]+sx_tmp[147]*udata->J->data[355]+sx_tmp[148]*udata->J->data[356];
  sxdot_tmp[149] = udata->dxdotdp[149 + ip*udata->nx]+sx_tmp[148]*udata->J->data[357]+sx_tmp[149]*udata->J->data[358];
  sxdot_tmp[150] = udata->dxdotdp[150 + ip*udata->nx]+sx_tmp[149]*udata->J->data[359]+sx_tmp[150]*udata->J->data[360];
  sxdot_tmp[151] = udata->dxdotdp[151 + ip*udata->nx]+sx_tmp[150]*udata->J->data[361]+sx_tmp[151]*udata->J->data[362];
  sxdot_tmp[152] = udata->dxdotdp[152 + ip*udata->nx]+sx_tmp[151]*udata->J->data[363]+sx_tmp[152]*udata->J->data[365];
  sxdot_tmp[153] = udata->dxdotdp[153 + ip*udata->nx]+sx_tmp[153]*udata->J->data[366]+sx_tmp[161]*udata->J->data[382];
  sxdot_tmp[154] = udata->dxdotdp[154 + ip*udata->nx]+sx_tmp[1]*udata->J->data[48]+sx_tmp[153]*udata->J->data[367]+sx_tmp[154]*udata->J->data[368];
  sxdot_tmp[155] = udata->dxdotdp[155 + ip*udata->nx]+sx_tmp[1]*udata->J->data[49]+sx_tmp[154]*udata->J->data[369]+sx_tmp[155]*udata->J->data[370];
  sxdot_tmp[156] = udata->dxdotdp[156 + ip*udata->nx]+sx_tmp[155]*udata->J->data[371]+sx_tmp[156]*udata->J->data[372];
  sxdot_tmp[157] = udata->dxdotdp[157 + ip*udata->nx]+sx_tmp[156]*udata->J->data[373]+sx_tmp[157]*udata->J->data[374];
  sxdot_tmp[158] = udata->dxdotdp[158 + ip*udata->nx]+sx_tmp[157]*udata->J->data[375]+sx_tmp[158]*udata->J->data[376];
  sxdot_tmp[159] = udata->dxdotdp[159 + ip*udata->nx]+sx_tmp[158]*udata->J->data[377]+sx_tmp[159]*udata->J->data[378];
  sxdot_tmp[160] = udata->dxdotdp[160 + ip*udata->nx]+sx_tmp[159]*udata->J->data[379]+sx_tmp[160]*udata->J->data[380];
  sxdot_tmp[161] = udata->dxdotdp[161 + ip*udata->nx]+sx_tmp[160]*udata->J->data[381]+sx_tmp[161]*udata->J->data[383];
return(status);

}

