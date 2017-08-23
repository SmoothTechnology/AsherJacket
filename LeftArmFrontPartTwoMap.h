#include "CommonCode.h"

int xSizeLeftArmPartTwo = 36;
int ySizeLeftArmPartTwo = 15;
int minLEDLeftArmPartTwo = 4682;
int maxLEDLeftArmPartTwo = 5114;

LEDPos LeftArmPartTwoMap [433];

void InitializeLeftArmFrontPartTwoMap()
{
	LeftArmPartTwoMap[292].x = 0;
LeftArmPartTwoMap[292].y = 0;
LeftArmPartTwoMap[294].x = 0;
LeftArmPartTwoMap[294].y = 0;
LeftArmPartTwoMap[295].x = 1;
LeftArmPartTwoMap[295].y = 0;
LeftArmPartTwoMap[296].x = 1;
LeftArmPartTwoMap[296].y = 0;
LeftArmPartTwoMap[297].x = 2;
LeftArmPartTwoMap[297].y = 0;
LeftArmPartTwoMap[298].x = 2;
LeftArmPartTwoMap[298].y = 0;
LeftArmPartTwoMap[299].x = 2;
LeftArmPartTwoMap[299].y = 0;
LeftArmPartTwoMap[300].x = 3;
LeftArmPartTwoMap[300].y = 0;
LeftArmPartTwoMap[431].x = 3;
LeftArmPartTwoMap[431].y = 0;
LeftArmPartTwoMap[429].x = 4;
LeftArmPartTwoMap[429].y = 0;
LeftArmPartTwoMap[430].x = 4;
LeftArmPartTwoMap[430].y = 0;
LeftArmPartTwoMap[427].x = 5;
LeftArmPartTwoMap[427].y = 0;
LeftArmPartTwoMap[428].x = 5;
LeftArmPartTwoMap[428].y = 0;
LeftArmPartTwoMap[426].x = 6;
LeftArmPartTwoMap[426].y = 0;
LeftArmPartTwoMap[290].x = 1;
LeftArmPartTwoMap[290].y = 1;
LeftArmPartTwoMap[291].x = 1;
LeftArmPartTwoMap[291].y = 1;
LeftArmPartTwoMap[287].x = 2;
LeftArmPartTwoMap[287].y = 1;
LeftArmPartTwoMap[288].x = 2;
LeftArmPartTwoMap[288].y = 1;
LeftArmPartTwoMap[289].x = 2;
LeftArmPartTwoMap[289].y = 1;
LeftArmPartTwoMap[286].x = 3;
LeftArmPartTwoMap[286].y = 1;
LeftArmPartTwoMap[301].x = 3;
LeftArmPartTwoMap[301].y = 1;
LeftArmPartTwoMap[302].x = 4;
LeftArmPartTwoMap[302].y = 1;
LeftArmPartTwoMap[303].x = 4;
LeftArmPartTwoMap[303].y = 1;
LeftArmPartTwoMap[304].x = 5;
LeftArmPartTwoMap[304].y = 1;
LeftArmPartTwoMap[305].x = 5;
LeftArmPartTwoMap[305].y = 1;
LeftArmPartTwoMap[306].x = 6;
LeftArmPartTwoMap[306].y = 1;
LeftArmPartTwoMap[425].x = 6;
LeftArmPartTwoMap[425].y = 1;
LeftArmPartTwoMap[422].x = 7;
LeftArmPartTwoMap[422].y = 1;
LeftArmPartTwoMap[423].x = 7;
LeftArmPartTwoMap[423].y = 1;
LeftArmPartTwoMap[424].x = 7;
LeftArmPartTwoMap[424].y = 1;
LeftArmPartTwoMap[420].x = 8;
LeftArmPartTwoMap[420].y = 1;
LeftArmPartTwoMap[421].x = 8;
LeftArmPartTwoMap[421].y = 1;
LeftArmPartTwoMap[150].x = 0;
LeftArmPartTwoMap[150].y = 2;
LeftArmPartTwoMap[151].x = 0;
LeftArmPartTwoMap[151].y = 2;
LeftArmPartTwoMap[152].x = 1;
LeftArmPartTwoMap[152].y = 2;
LeftArmPartTwoMap[153].x = 1;
LeftArmPartTwoMap[153].y = 2;
LeftArmPartTwoMap[154].x = 2;
LeftArmPartTwoMap[154].y = 2;
LeftArmPartTwoMap[155].x = 2;
LeftArmPartTwoMap[155].y = 2;
LeftArmPartTwoMap[285].x = 3;
LeftArmPartTwoMap[285].y = 2;
LeftArmPartTwoMap[282].x = 4;
LeftArmPartTwoMap[282].y = 2;
LeftArmPartTwoMap[283].x = 4;
LeftArmPartTwoMap[283].y = 2;
LeftArmPartTwoMap[284].x = 4;
LeftArmPartTwoMap[284].y = 2;
LeftArmPartTwoMap[281].x = 5;
LeftArmPartTwoMap[281].y = 2;
LeftArmPartTwoMap[307].x = 6;
LeftArmPartTwoMap[307].y = 2;
LeftArmPartTwoMap[308].x = 6;
LeftArmPartTwoMap[308].y = 2;
LeftArmPartTwoMap[309].x = 7;
LeftArmPartTwoMap[309].y = 2;
LeftArmPartTwoMap[310].x = 7;
LeftArmPartTwoMap[310].y = 2;
LeftArmPartTwoMap[311].x = 8;
LeftArmPartTwoMap[311].y = 2;
LeftArmPartTwoMap[418].x = 9;
LeftArmPartTwoMap[418].y = 2;
LeftArmPartTwoMap[419].x = 9;
LeftArmPartTwoMap[419].y = 2;
LeftArmPartTwoMap[416].x = 10;
LeftArmPartTwoMap[416].y = 2;
LeftArmPartTwoMap[417].x = 10;
LeftArmPartTwoMap[417].y = 2;
LeftArmPartTwoMap[414].x = 11;
LeftArmPartTwoMap[414].y = 2;
LeftArmPartTwoMap[415].x = 11;
LeftArmPartTwoMap[415].y = 2;
LeftArmPartTwoMap[149].x = 0;
LeftArmPartTwoMap[149].y = 3;
LeftArmPartTwoMap[146].x = 1;
LeftArmPartTwoMap[146].y = 3;
LeftArmPartTwoMap[147].x = 1;
LeftArmPartTwoMap[147].y = 3;
LeftArmPartTwoMap[148].x = 1;
LeftArmPartTwoMap[148].y = 3;
LeftArmPartTwoMap[144].x = 2;
LeftArmPartTwoMap[144].y = 3;
LeftArmPartTwoMap[145].x = 2;
LeftArmPartTwoMap[145].y = 3;
LeftArmPartTwoMap[156].x = 2;
LeftArmPartTwoMap[156].y = 3;
LeftArmPartTwoMap[157].x = 3;
LeftArmPartTwoMap[157].y = 3;
LeftArmPartTwoMap[158].x = 3;
LeftArmPartTwoMap[158].y = 3;
LeftArmPartTwoMap[159].x = 4;
LeftArmPartTwoMap[159].y = 3;
LeftArmPartTwoMap[160].x = 4;
LeftArmPartTwoMap[160].y = 3;
LeftArmPartTwoMap[161].x = 5;
LeftArmPartTwoMap[161].y = 3;
LeftArmPartTwoMap[280].x = 5;
LeftArmPartTwoMap[280].y = 3;
LeftArmPartTwoMap[278].x = 6;
LeftArmPartTwoMap[278].y = 3;
LeftArmPartTwoMap[279].x = 6;
LeftArmPartTwoMap[279].y = 3;
LeftArmPartTwoMap[276].x = 7;
LeftArmPartTwoMap[276].y = 3;
LeftArmPartTwoMap[277].x = 7;
LeftArmPartTwoMap[277].y = 3;
LeftArmPartTwoMap[275].x = 8;
LeftArmPartTwoMap[275].y = 3;
LeftArmPartTwoMap[312].x = 8;
LeftArmPartTwoMap[312].y = 3;
LeftArmPartTwoMap[313].x = 9;
LeftArmPartTwoMap[313].y = 3;
LeftArmPartTwoMap[314].x = 9;
LeftArmPartTwoMap[314].y = 3;
LeftArmPartTwoMap[315].x = 10;
LeftArmPartTwoMap[315].y = 3;
LeftArmPartTwoMap[316].x = 10;
LeftArmPartTwoMap[316].y = 3;
LeftArmPartTwoMap[317].x = 11;
LeftArmPartTwoMap[317].y = 3;
LeftArmPartTwoMap[412].x = 12;
LeftArmPartTwoMap[412].y = 3;
LeftArmPartTwoMap[413].x = 12;
LeftArmPartTwoMap[413].y = 3;
LeftArmPartTwoMap[410].x = 13;
LeftArmPartTwoMap[410].y = 3;
LeftArmPartTwoMap[411].x = 13;
LeftArmPartTwoMap[411].y = 3;
LeftArmPartTwoMap[30].x = 0;
LeftArmPartTwoMap[30].y = 4;
LeftArmPartTwoMap[31].x = 0;
LeftArmPartTwoMap[31].y = 4;
LeftArmPartTwoMap[32].x = 1;
LeftArmPartTwoMap[32].y = 4;
LeftArmPartTwoMap[33].x = 1;
LeftArmPartTwoMap[33].y = 4;
LeftArmPartTwoMap[29].x = 2;
LeftArmPartTwoMap[29].y = 4;
LeftArmPartTwoMap[34].x = 2;
LeftArmPartTwoMap[34].y = 4;
LeftArmPartTwoMap[35].x = 2;
LeftArmPartTwoMap[35].y = 4;
LeftArmPartTwoMap[28].x = 3;
LeftArmPartTwoMap[28].y = 4;
LeftArmPartTwoMap[36].x = 3;
LeftArmPartTwoMap[36].y = 4;
LeftArmPartTwoMap[37].x = 3;
LeftArmPartTwoMap[37].y = 4;
LeftArmPartTwoMap[38].x = 3;
LeftArmPartTwoMap[38].y = 4;
LeftArmPartTwoMap[142].x = 3;
LeftArmPartTwoMap[142].y = 4;
LeftArmPartTwoMap[143].x = 3;
LeftArmPartTwoMap[143].y = 4;
LeftArmPartTwoMap[139].x = 4;
LeftArmPartTwoMap[139].y = 4;
LeftArmPartTwoMap[140].x = 4;
LeftArmPartTwoMap[140].y = 4;
LeftArmPartTwoMap[141].x = 4;
LeftArmPartTwoMap[141].y = 4;
LeftArmPartTwoMap[138].x = 5;
LeftArmPartTwoMap[138].y = 4;
LeftArmPartTwoMap[162].x = 5;
LeftArmPartTwoMap[162].y = 4;
LeftArmPartTwoMap[163].x = 5;
LeftArmPartTwoMap[163].y = 4;
LeftArmPartTwoMap[164].x = 6;
LeftArmPartTwoMap[164].y = 4;
LeftArmPartTwoMap[165].x = 6;
LeftArmPartTwoMap[165].y = 4;
LeftArmPartTwoMap[166].x = 7;
LeftArmPartTwoMap[166].y = 4;
LeftArmPartTwoMap[274].x = 8;
LeftArmPartTwoMap[274].y = 4;
LeftArmPartTwoMap[272].x = 9;
LeftArmPartTwoMap[272].y = 4;
LeftArmPartTwoMap[273].x = 9;
LeftArmPartTwoMap[273].y = 4;
LeftArmPartTwoMap[270].x = 10;
LeftArmPartTwoMap[270].y = 4;
LeftArmPartTwoMap[271].x = 10;
LeftArmPartTwoMap[271].y = 4;
LeftArmPartTwoMap[269].x = 11;
LeftArmPartTwoMap[269].y = 4;
LeftArmPartTwoMap[318].x = 11;
LeftArmPartTwoMap[318].y = 4;
LeftArmPartTwoMap[319].x = 12;
LeftArmPartTwoMap[319].y = 4;
LeftArmPartTwoMap[320].x = 12;
LeftArmPartTwoMap[320].y = 4;
LeftArmPartTwoMap[321].x = 13;
LeftArmPartTwoMap[321].y = 4;
LeftArmPartTwoMap[322].x = 13;
LeftArmPartTwoMap[322].y = 4;
LeftArmPartTwoMap[323].x = 14;
LeftArmPartTwoMap[323].y = 4;
LeftArmPartTwoMap[407].x = 14;
LeftArmPartTwoMap[407].y = 4;
LeftArmPartTwoMap[408].x = 14;
LeftArmPartTwoMap[408].y = 4;
LeftArmPartTwoMap[409].x = 14;
LeftArmPartTwoMap[409].y = 4;
LeftArmPartTwoMap[405].x = 15;
LeftArmPartTwoMap[405].y = 4;
LeftArmPartTwoMap[406].x = 15;
LeftArmPartTwoMap[406].y = 4;
LeftArmPartTwoMap[403].x = 16;
LeftArmPartTwoMap[403].y = 4;
LeftArmPartTwoMap[404].x = 16;
LeftArmPartTwoMap[404].y = 4;
LeftArmPartTwoMap[27].x = 3;
LeftArmPartTwoMap[27].y = 5;
LeftArmPartTwoMap[24].x = 4;
LeftArmPartTwoMap[24].y = 5;
LeftArmPartTwoMap[25].x = 4;
LeftArmPartTwoMap[25].y = 5;
LeftArmPartTwoMap[26].x = 4;
LeftArmPartTwoMap[26].y = 5;
LeftArmPartTwoMap[39].x = 4;
LeftArmPartTwoMap[39].y = 5;
LeftArmPartTwoMap[40].x = 4;
LeftArmPartTwoMap[40].y = 5;
LeftArmPartTwoMap[23].x = 5;
LeftArmPartTwoMap[23].y = 5;
LeftArmPartTwoMap[41].x = 5;
LeftArmPartTwoMap[41].y = 5;
LeftArmPartTwoMap[42].x = 5;
LeftArmPartTwoMap[42].y = 5;
LeftArmPartTwoMap[137].x = 5;
LeftArmPartTwoMap[137].y = 5;
LeftArmPartTwoMap[43].x = 6;
LeftArmPartTwoMap[43].y = 5;
LeftArmPartTwoMap[135].x = 6;
LeftArmPartTwoMap[135].y = 5;
LeftArmPartTwoMap[136].x = 6;
LeftArmPartTwoMap[136].y = 5;
LeftArmPartTwoMap[133].x = 7;
LeftArmPartTwoMap[133].y = 5;
LeftArmPartTwoMap[134].x = 7;
LeftArmPartTwoMap[134].y = 5;
LeftArmPartTwoMap[167].x = 7;
LeftArmPartTwoMap[167].y = 5;
LeftArmPartTwoMap[132].x = 8;
LeftArmPartTwoMap[132].y = 5;
LeftArmPartTwoMap[168].x = 8;
LeftArmPartTwoMap[168].y = 5;
LeftArmPartTwoMap[169].x = 8;
LeftArmPartTwoMap[169].y = 5;
LeftArmPartTwoMap[170].x = 9;
LeftArmPartTwoMap[170].y = 5;
LeftArmPartTwoMap[171].x = 9;
LeftArmPartTwoMap[171].y = 5;
LeftArmPartTwoMap[172].x = 10;
LeftArmPartTwoMap[172].y = 5;
LeftArmPartTwoMap[173].x = 10;
LeftArmPartTwoMap[173].y = 5;
LeftArmPartTwoMap[267].x = 11;
LeftArmPartTwoMap[267].y = 5;
LeftArmPartTwoMap[268].x = 11;
LeftArmPartTwoMap[268].y = 5;
LeftArmPartTwoMap[265].x = 12;
LeftArmPartTwoMap[265].y = 5;
LeftArmPartTwoMap[266].x = 12;
LeftArmPartTwoMap[266].y = 5;
LeftArmPartTwoMap[264].x = 13;
LeftArmPartTwoMap[264].y = 5;
LeftArmPartTwoMap[324].x = 14;
LeftArmPartTwoMap[324].y = 5;
LeftArmPartTwoMap[325].x = 14;
LeftArmPartTwoMap[325].y = 5;
LeftArmPartTwoMap[326].x = 15;
LeftArmPartTwoMap[326].y = 5;
LeftArmPartTwoMap[327].x = 15;
LeftArmPartTwoMap[327].y = 5;
LeftArmPartTwoMap[328].x = 16;
LeftArmPartTwoMap[328].y = 5;
LeftArmPartTwoMap[329].x = 16;
LeftArmPartTwoMap[329].y = 5;
LeftArmPartTwoMap[401].x = 17;
LeftArmPartTwoMap[401].y = 5;
LeftArmPartTwoMap[402].x = 17;
LeftArmPartTwoMap[402].y = 5;
LeftArmPartTwoMap[399].x = 18;
LeftArmPartTwoMap[399].y = 5;
LeftArmPartTwoMap[400].x = 18;
LeftArmPartTwoMap[400].y = 5;
LeftArmPartTwoMap[397].x = 19;
LeftArmPartTwoMap[397].y = 5;
LeftArmPartTwoMap[398].x = 19;
LeftArmPartTwoMap[398].y = 5;
LeftArmPartTwoMap[395].x = 20;
LeftArmPartTwoMap[395].y = 5;
LeftArmPartTwoMap[396].x = 20;
LeftArmPartTwoMap[396].y = 5;
LeftArmPartTwoMap[22].x = 5;
LeftArmPartTwoMap[22].y = 6;
LeftArmPartTwoMap[19].x = 6;
LeftArmPartTwoMap[19].y = 6;
LeftArmPartTwoMap[20].x = 6;
LeftArmPartTwoMap[20].y = 6;
LeftArmPartTwoMap[21].x = 6;
LeftArmPartTwoMap[21].y = 6;
LeftArmPartTwoMap[44].x = 6;
LeftArmPartTwoMap[44].y = 6;
LeftArmPartTwoMap[45].x = 6;
LeftArmPartTwoMap[45].y = 6;
LeftArmPartTwoMap[17].x = 7;
LeftArmPartTwoMap[17].y = 6;
LeftArmPartTwoMap[18].x = 7;
LeftArmPartTwoMap[18].y = 6;
LeftArmPartTwoMap[46].x = 7;
LeftArmPartTwoMap[46].y = 6;
LeftArmPartTwoMap[47].x = 7;
LeftArmPartTwoMap[47].y = 6;
LeftArmPartTwoMap[16].x = 8;
LeftArmPartTwoMap[16].y = 6;
LeftArmPartTwoMap[48].x = 8;
LeftArmPartTwoMap[48].y = 6;
LeftArmPartTwoMap[49].x = 8;
LeftArmPartTwoMap[49].y = 6;
LeftArmPartTwoMap[130].x = 8;
LeftArmPartTwoMap[130].y = 6;
LeftArmPartTwoMap[131].x = 8;
LeftArmPartTwoMap[131].y = 6;
LeftArmPartTwoMap[50].x = 9;
LeftArmPartTwoMap[50].y = 6;
LeftArmPartTwoMap[128].x = 9;
LeftArmPartTwoMap[128].y = 6;
LeftArmPartTwoMap[129].x = 9;
LeftArmPartTwoMap[129].y = 6;
LeftArmPartTwoMap[126].x = 10;
LeftArmPartTwoMap[126].y = 6;
LeftArmPartTwoMap[127].x = 10;
LeftArmPartTwoMap[127].y = 6;
LeftArmPartTwoMap[174].x = 11;
LeftArmPartTwoMap[174].y = 6;
LeftArmPartTwoMap[175].x = 11;
LeftArmPartTwoMap[175].y = 6;
LeftArmPartTwoMap[176].x = 12;
LeftArmPartTwoMap[176].y = 6;
LeftArmPartTwoMap[177].x = 12;
LeftArmPartTwoMap[177].y = 6;
LeftArmPartTwoMap[178].x = 12;
LeftArmPartTwoMap[178].y = 6;
LeftArmPartTwoMap[263].x = 13;
LeftArmPartTwoMap[263].y = 6;
LeftArmPartTwoMap[261].x = 14;
LeftArmPartTwoMap[261].y = 6;
LeftArmPartTwoMap[262].x = 14;
LeftArmPartTwoMap[262].y = 6;
LeftArmPartTwoMap[259].x = 15;
LeftArmPartTwoMap[259].y = 6;
LeftArmPartTwoMap[260].x = 15;
LeftArmPartTwoMap[260].y = 6;
LeftArmPartTwoMap[258].x = 16;
LeftArmPartTwoMap[258].y = 6;
LeftArmPartTwoMap[330].x = 17;
LeftArmPartTwoMap[330].y = 6;
LeftArmPartTwoMap[331].x = 17;
LeftArmPartTwoMap[331].y = 6;
LeftArmPartTwoMap[332].x = 18;
LeftArmPartTwoMap[332].y = 6;
LeftArmPartTwoMap[333].x = 18;
LeftArmPartTwoMap[333].y = 6;
LeftArmPartTwoMap[334].x = 19;
LeftArmPartTwoMap[334].y = 6;
LeftArmPartTwoMap[335].x = 19;
LeftArmPartTwoMap[335].y = 6;
LeftArmPartTwoMap[393].x = 21;
LeftArmPartTwoMap[393].y = 6;
LeftArmPartTwoMap[394].x = 21;
LeftArmPartTwoMap[394].y = 6;
LeftArmPartTwoMap[391].x = 22;
LeftArmPartTwoMap[391].y = 6;
LeftArmPartTwoMap[392].x = 22;
LeftArmPartTwoMap[392].y = 6;
LeftArmPartTwoMap[390].x = 23;
LeftArmPartTwoMap[390].y = 6;
LeftArmPartTwoMap[15].x = 8;
LeftArmPartTwoMap[15].y = 7;
LeftArmPartTwoMap[13].x = 9;
LeftArmPartTwoMap[13].y = 7;
LeftArmPartTwoMap[14].x = 9;
LeftArmPartTwoMap[14].y = 7;
LeftArmPartTwoMap[51].x = 9;
LeftArmPartTwoMap[51].y = 7;
LeftArmPartTwoMap[11].x = 10;
LeftArmPartTwoMap[11].y = 7;
LeftArmPartTwoMap[12].x = 10;
LeftArmPartTwoMap[12].y = 7;
LeftArmPartTwoMap[52].x = 10;
LeftArmPartTwoMap[52].y = 7;
LeftArmPartTwoMap[53].x = 11;
LeftArmPartTwoMap[53].y = 7;
LeftArmPartTwoMap[55].x = 11;
LeftArmPartTwoMap[55].y = 7;
LeftArmPartTwoMap[124].x = 11;
LeftArmPartTwoMap[124].y = 7;
LeftArmPartTwoMap[125].x = 11;
LeftArmPartTwoMap[125].y = 7;
LeftArmPartTwoMap[6].x = 12;
LeftArmPartTwoMap[6].y = 7;
LeftArmPartTwoMap[56].x = 12;
LeftArmPartTwoMap[56].y = 7;
LeftArmPartTwoMap[122].x = 12;
LeftArmPartTwoMap[122].y = 7;
LeftArmPartTwoMap[123].x = 12;
LeftArmPartTwoMap[123].y = 7;
LeftArmPartTwoMap[120].x = 13;
LeftArmPartTwoMap[120].y = 7;
LeftArmPartTwoMap[121].x = 13;
LeftArmPartTwoMap[121].y = 7;
LeftArmPartTwoMap[179].x = 13;
LeftArmPartTwoMap[179].y = 7;
LeftArmPartTwoMap[180].x = 13;
LeftArmPartTwoMap[180].y = 7;
LeftArmPartTwoMap[181].x = 14;
LeftArmPartTwoMap[181].y = 7;
LeftArmPartTwoMap[182].x = 14;
LeftArmPartTwoMap[182].y = 7;
LeftArmPartTwoMap[183].x = 15;
LeftArmPartTwoMap[183].y = 7;
LeftArmPartTwoMap[184].x = 15;
LeftArmPartTwoMap[184].y = 7;
LeftArmPartTwoMap[257].x = 16;
LeftArmPartTwoMap[257].y = 7;
LeftArmPartTwoMap[255].x = 17;
LeftArmPartTwoMap[255].y = 7;
LeftArmPartTwoMap[256].x = 17;
LeftArmPartTwoMap[256].y = 7;
LeftArmPartTwoMap[253].x = 18;
LeftArmPartTwoMap[253].y = 7;
LeftArmPartTwoMap[254].x = 18;
LeftArmPartTwoMap[254].y = 7;
LeftArmPartTwoMap[252].x = 19;
LeftArmPartTwoMap[252].y = 7;
LeftArmPartTwoMap[336].x = 20;
LeftArmPartTwoMap[336].y = 7;
LeftArmPartTwoMap[337].x = 20;
LeftArmPartTwoMap[337].y = 7;
LeftArmPartTwoMap[338].x = 21;
LeftArmPartTwoMap[338].y = 7;
LeftArmPartTwoMap[339].x = 21;
LeftArmPartTwoMap[339].y = 7;
LeftArmPartTwoMap[340].x = 22;
LeftArmPartTwoMap[340].y = 7;
LeftArmPartTwoMap[341].x = 22;
LeftArmPartTwoMap[341].y = 7;
LeftArmPartTwoMap[389].x = 23;
LeftArmPartTwoMap[389].y = 7;
LeftArmPartTwoMap[387].x = 24;
LeftArmPartTwoMap[387].y = 7;
LeftArmPartTwoMap[388].x = 24;
LeftArmPartTwoMap[388].y = 7;
LeftArmPartTwoMap[385].x = 25;
LeftArmPartTwoMap[385].y = 7;
LeftArmPartTwoMap[386].x = 25;
LeftArmPartTwoMap[386].y = 7;
LeftArmPartTwoMap[10].x = 10;
LeftArmPartTwoMap[10].y = 8;
LeftArmPartTwoMap[7].x = 11;
LeftArmPartTwoMap[7].y = 8;
LeftArmPartTwoMap[8].x = 11;
LeftArmPartTwoMap[8].y = 8;
LeftArmPartTwoMap[9].x = 11;
LeftArmPartTwoMap[9].y = 8;
LeftArmPartTwoMap[54].x = 11;
LeftArmPartTwoMap[54].y = 8;
LeftArmPartTwoMap[5].x = 12;
LeftArmPartTwoMap[5].y = 8;
LeftArmPartTwoMap[57].x = 12;
LeftArmPartTwoMap[57].y = 8;
LeftArmPartTwoMap[58].x = 12;
LeftArmPartTwoMap[58].y = 8;
LeftArmPartTwoMap[0].x = 13;
LeftArmPartTwoMap[0].y = 8;
LeftArmPartTwoMap[1].x = 13;
LeftArmPartTwoMap[1].y = 8;
LeftArmPartTwoMap[2].x = 13;
LeftArmPartTwoMap[2].y = 8;
LeftArmPartTwoMap[3].x = 13;
LeftArmPartTwoMap[3].y = 8;
LeftArmPartTwoMap[4].x = 13;
LeftArmPartTwoMap[4].y = 8;
LeftArmPartTwoMap[59].x = 13;
LeftArmPartTwoMap[59].y = 8;
LeftArmPartTwoMap[60].x = 13;
LeftArmPartTwoMap[60].y = 8;
LeftArmPartTwoMap[61].x = 13;
LeftArmPartTwoMap[61].y = 8;
LeftArmPartTwoMap[62].x = 14;
LeftArmPartTwoMap[62].y = 8;
LeftArmPartTwoMap[118].x = 14;
LeftArmPartTwoMap[118].y = 8;
LeftArmPartTwoMap[119].x = 14;
LeftArmPartTwoMap[119].y = 8;
LeftArmPartTwoMap[63].x = 15;
LeftArmPartTwoMap[63].y = 8;
LeftArmPartTwoMap[64].x = 15;
LeftArmPartTwoMap[64].y = 8;
LeftArmPartTwoMap[116].x = 15;
LeftArmPartTwoMap[116].y = 8;
LeftArmPartTwoMap[117].x = 15;
LeftArmPartTwoMap[117].y = 8;
LeftArmPartTwoMap[65].x = 16;
LeftArmPartTwoMap[65].y = 8;
LeftArmPartTwoMap[114].x = 16;
LeftArmPartTwoMap[114].y = 8;
LeftArmPartTwoMap[115].x = 16;
LeftArmPartTwoMap[115].y = 8;
LeftArmPartTwoMap[185].x = 16;
LeftArmPartTwoMap[185].y = 8;
LeftArmPartTwoMap[186].x = 16;
LeftArmPartTwoMap[186].y = 8;
LeftArmPartTwoMap[112].x = 17;
LeftArmPartTwoMap[112].y = 8;
LeftArmPartTwoMap[113].x = 17;
LeftArmPartTwoMap[113].y = 8;
LeftArmPartTwoMap[187].x = 17;
LeftArmPartTwoMap[187].y = 8;
LeftArmPartTwoMap[188].x = 17;
LeftArmPartTwoMap[188].y = 8;
LeftArmPartTwoMap[111].x = 18;
LeftArmPartTwoMap[111].y = 8;
LeftArmPartTwoMap[189].x = 18;
LeftArmPartTwoMap[189].y = 8;
LeftArmPartTwoMap[190].x = 18;
LeftArmPartTwoMap[190].y = 8;
LeftArmPartTwoMap[191].x = 19;
LeftArmPartTwoMap[191].y = 8;
LeftArmPartTwoMap[251].x = 19;
LeftArmPartTwoMap[251].y = 8;
LeftArmPartTwoMap[249].x = 20;
LeftArmPartTwoMap[249].y = 8;
LeftArmPartTwoMap[250].x = 20;
LeftArmPartTwoMap[250].y = 8;
LeftArmPartTwoMap[247].x = 21;
LeftArmPartTwoMap[247].y = 8;
LeftArmPartTwoMap[248].x = 21;
LeftArmPartTwoMap[248].y = 8;
LeftArmPartTwoMap[245].x = 22;
LeftArmPartTwoMap[245].y = 8;
LeftArmPartTwoMap[246].x = 22;
LeftArmPartTwoMap[246].y = 8;
LeftArmPartTwoMap[342].x = 23;
LeftArmPartTwoMap[342].y = 8;
LeftArmPartTwoMap[343].x = 23;
LeftArmPartTwoMap[343].y = 8;
LeftArmPartTwoMap[344].x = 24;
LeftArmPartTwoMap[344].y = 8;
LeftArmPartTwoMap[345].x = 24;
LeftArmPartTwoMap[345].y = 8;
LeftArmPartTwoMap[346].x = 25;
LeftArmPartTwoMap[346].y = 8;
LeftArmPartTwoMap[383].x = 26;
LeftArmPartTwoMap[383].y = 8;
LeftArmPartTwoMap[384].x = 26;
LeftArmPartTwoMap[384].y = 8;
LeftArmPartTwoMap[381].x = 27;
LeftArmPartTwoMap[381].y = 8;
LeftArmPartTwoMap[382].x = 27;
LeftArmPartTwoMap[382].y = 8;
LeftArmPartTwoMap[379].x = 28;
LeftArmPartTwoMap[379].y = 8;
LeftArmPartTwoMap[380].x = 28;
LeftArmPartTwoMap[380].y = 8;
LeftArmPartTwoMap[66].x = 16;
LeftArmPartTwoMap[66].y = 9;
LeftArmPartTwoMap[67].x = 17;
LeftArmPartTwoMap[67].y = 9;
LeftArmPartTwoMap[68].x = 18;
LeftArmPartTwoMap[68].y = 9;
LeftArmPartTwoMap[69].x = 18;
LeftArmPartTwoMap[69].y = 9;
LeftArmPartTwoMap[70].x = 18;
LeftArmPartTwoMap[70].y = 9;
LeftArmPartTwoMap[110].x = 18;
LeftArmPartTwoMap[110].y = 9;
LeftArmPartTwoMap[71].x = 19;
LeftArmPartTwoMap[71].y = 9;
LeftArmPartTwoMap[108].x = 19;
LeftArmPartTwoMap[108].y = 9;
LeftArmPartTwoMap[109].x = 19;
LeftArmPartTwoMap[109].y = 9;
LeftArmPartTwoMap[192].x = 19;
LeftArmPartTwoMap[192].y = 9;
LeftArmPartTwoMap[106].x = 20;
LeftArmPartTwoMap[106].y = 9;
LeftArmPartTwoMap[193].x = 20;
LeftArmPartTwoMap[193].y = 9;
LeftArmPartTwoMap[194].x = 20;
LeftArmPartTwoMap[194].y = 9;
LeftArmPartTwoMap[195].x = 21;
LeftArmPartTwoMap[195].y = 9;
LeftArmPartTwoMap[196].x = 21;
LeftArmPartTwoMap[196].y = 9;
LeftArmPartTwoMap[243].x = 23;
LeftArmPartTwoMap[243].y = 9;
LeftArmPartTwoMap[244].x = 23;
LeftArmPartTwoMap[244].y = 9;
LeftArmPartTwoMap[241].x = 24;
LeftArmPartTwoMap[241].y = 9;
LeftArmPartTwoMap[242].x = 24;
LeftArmPartTwoMap[242].y = 9;
LeftArmPartTwoMap[239].x = 25;
LeftArmPartTwoMap[239].y = 9;
LeftArmPartTwoMap[240].x = 25;
LeftArmPartTwoMap[240].y = 9;
LeftArmPartTwoMap[347].x = 25;
LeftArmPartTwoMap[347].y = 9;
LeftArmPartTwoMap[348].x = 26;
LeftArmPartTwoMap[348].y = 9;
LeftArmPartTwoMap[349].x = 26;
LeftArmPartTwoMap[349].y = 9;
LeftArmPartTwoMap[350].x = 27;
LeftArmPartTwoMap[350].y = 9;
LeftArmPartTwoMap[351].x = 27;
LeftArmPartTwoMap[351].y = 9;
LeftArmPartTwoMap[352].x = 28;
LeftArmPartTwoMap[352].y = 9;
LeftArmPartTwoMap[378].x = 29;
LeftArmPartTwoMap[378].y = 9;
LeftArmPartTwoMap[376].x = 30;
LeftArmPartTwoMap[376].y = 9;
LeftArmPartTwoMap[377].x = 30;
LeftArmPartTwoMap[377].y = 9;
LeftArmPartTwoMap[374].x = 31;
LeftArmPartTwoMap[374].y = 9;
LeftArmPartTwoMap[375].x = 31;
LeftArmPartTwoMap[375].y = 9;
LeftArmPartTwoMap[72].x = 19;
LeftArmPartTwoMap[72].y = 10;
LeftArmPartTwoMap[73].x = 20;
LeftArmPartTwoMap[73].y = 10;
LeftArmPartTwoMap[74].x = 20;
LeftArmPartTwoMap[74].y = 10;
LeftArmPartTwoMap[75].x = 20;
LeftArmPartTwoMap[75].y = 10;
LeftArmPartTwoMap[107].x = 20;
LeftArmPartTwoMap[107].y = 10;
LeftArmPartTwoMap[76].x = 21;
LeftArmPartTwoMap[76].y = 10;
LeftArmPartTwoMap[77].x = 21;
LeftArmPartTwoMap[77].y = 10;
LeftArmPartTwoMap[103].x = 21;
LeftArmPartTwoMap[103].y = 10;
LeftArmPartTwoMap[104].x = 21;
LeftArmPartTwoMap[104].y = 10;
LeftArmPartTwoMap[105].x = 21;
LeftArmPartTwoMap[105].y = 10;
LeftArmPartTwoMap[78].x = 22;
LeftArmPartTwoMap[78].y = 10;
LeftArmPartTwoMap[102].x = 22;
LeftArmPartTwoMap[102].y = 10;
LeftArmPartTwoMap[197].x = 22;
LeftArmPartTwoMap[197].y = 10;
LeftArmPartTwoMap[198].x = 22;
LeftArmPartTwoMap[198].y = 10;
LeftArmPartTwoMap[79].x = 23;
LeftArmPartTwoMap[79].y = 10;
LeftArmPartTwoMap[100].x = 23;
LeftArmPartTwoMap[100].y = 10;
LeftArmPartTwoMap[101].x = 23;
LeftArmPartTwoMap[101].y = 10;
LeftArmPartTwoMap[199].x = 23;
LeftArmPartTwoMap[199].y = 10;
LeftArmPartTwoMap[200].x = 23;
LeftArmPartTwoMap[200].y = 10;
LeftArmPartTwoMap[98].x = 24;
LeftArmPartTwoMap[98].y = 10;
LeftArmPartTwoMap[99].x = 24;
LeftArmPartTwoMap[99].y = 10;
LeftArmPartTwoMap[201].x = 24;
LeftArmPartTwoMap[201].y = 10;
LeftArmPartTwoMap[202].x = 24;
LeftArmPartTwoMap[202].y = 10;
LeftArmPartTwoMap[238].x = 26;
LeftArmPartTwoMap[238].y = 10;
LeftArmPartTwoMap[353].x = 28;
LeftArmPartTwoMap[353].y = 10;
LeftArmPartTwoMap[354].x = 29;
LeftArmPartTwoMap[354].y = 10;
LeftArmPartTwoMap[355].x = 29;
LeftArmPartTwoMap[355].y = 10;
LeftArmPartTwoMap[356].x = 30;
LeftArmPartTwoMap[356].y = 10;
LeftArmPartTwoMap[357].x = 31;
LeftArmPartTwoMap[357].y = 10;
LeftArmPartTwoMap[358].x = 31;
LeftArmPartTwoMap[358].y = 10;
LeftArmPartTwoMap[359].x = 32;
LeftArmPartTwoMap[359].y = 10;
LeftArmPartTwoMap[373].x = 32;
LeftArmPartTwoMap[373].y = 10;
LeftArmPartTwoMap[371].x = 33;
LeftArmPartTwoMap[371].y = 10;
LeftArmPartTwoMap[372].x = 33;
LeftArmPartTwoMap[372].y = 10;
LeftArmPartTwoMap[369].x = 34;
LeftArmPartTwoMap[369].y = 10;
LeftArmPartTwoMap[370].x = 34;
LeftArmPartTwoMap[370].y = 10;
LeftArmPartTwoMap[367].x = 35;
LeftArmPartTwoMap[367].y = 10;
LeftArmPartTwoMap[366].x = 35;
LeftArmPartTwoMap[366].y = 10;
LeftArmPartTwoMap[368].x = 35;
LeftArmPartTwoMap[368].y = 10;
LeftArmPartTwoMap[96].x = 24;
LeftArmPartTwoMap[96].y = 11;
LeftArmPartTwoMap[94].x = 25;
LeftArmPartTwoMap[94].y = 11;
LeftArmPartTwoMap[97].x = 25;
LeftArmPartTwoMap[97].y = 11;
LeftArmPartTwoMap[203].x = 25;
LeftArmPartTwoMap[203].y = 11;
LeftArmPartTwoMap[204].x = 25;
LeftArmPartTwoMap[204].y = 11;
LeftArmPartTwoMap[93].x = 26;
LeftArmPartTwoMap[93].y = 11;
LeftArmPartTwoMap[205].x = 26;
LeftArmPartTwoMap[205].y = 11;
LeftArmPartTwoMap[91].x = 27;
LeftArmPartTwoMap[91].y = 11;
LeftArmPartTwoMap[92].x = 27;
LeftArmPartTwoMap[92].y = 11;
LeftArmPartTwoMap[206].x = 27;
LeftArmPartTwoMap[206].y = 11;
LeftArmPartTwoMap[207].x = 27;
LeftArmPartTwoMap[207].y = 11;
LeftArmPartTwoMap[235].x = 27;
LeftArmPartTwoMap[235].y = 11;
LeftArmPartTwoMap[236].x = 27;
LeftArmPartTwoMap[236].y = 11;
LeftArmPartTwoMap[237].x = 27;
LeftArmPartTwoMap[237].y = 11;
LeftArmPartTwoMap[90].x = 28;
LeftArmPartTwoMap[90].y = 11;
LeftArmPartTwoMap[208].x = 28;
LeftArmPartTwoMap[208].y = 11;
LeftArmPartTwoMap[209].x = 28;
LeftArmPartTwoMap[209].y = 11;
LeftArmPartTwoMap[233].x = 28;
LeftArmPartTwoMap[233].y = 11;
LeftArmPartTwoMap[234].x = 28;
LeftArmPartTwoMap[234].y = 11;
LeftArmPartTwoMap[210].x = 29;
LeftArmPartTwoMap[210].y = 11;
LeftArmPartTwoMap[211].x = 29;
LeftArmPartTwoMap[211].y = 11;
LeftArmPartTwoMap[212].x = 29;
LeftArmPartTwoMap[212].y = 11;
LeftArmPartTwoMap[213].x = 29;
LeftArmPartTwoMap[213].y = 11;
LeftArmPartTwoMap[231].x = 29;
LeftArmPartTwoMap[231].y = 11;
LeftArmPartTwoMap[232].x = 29;
LeftArmPartTwoMap[232].y = 11;
LeftArmPartTwoMap[213].x = 29;
LeftArmPartTwoMap[213].y = 11;
LeftArmPartTwoMap[229].x = 30;
LeftArmPartTwoMap[229].y = 11;
LeftArmPartTwoMap[230].x = 30;
LeftArmPartTwoMap[230].y = 11;
LeftArmPartTwoMap[214].x = 30;
LeftArmPartTwoMap[214].y = 11;
LeftArmPartTwoMap[215].x = 31;
LeftArmPartTwoMap[215].y = 11;
LeftArmPartTwoMap[228].x = 31;
LeftArmPartTwoMap[228].y = 11;
LeftArmPartTwoMap[226].x = 32;
LeftArmPartTwoMap[226].y = 11;
LeftArmPartTwoMap[227].x = 32;
LeftArmPartTwoMap[227].y = 11;
LeftArmPartTwoMap[360].x = 32;
LeftArmPartTwoMap[360].y = 11;
LeftArmPartTwoMap[361].x = 33;
LeftArmPartTwoMap[361].y = 11;
LeftArmPartTwoMap[362].x = 33;
LeftArmPartTwoMap[362].y = 11;
LeftArmPartTwoMap[363].x = 34;
LeftArmPartTwoMap[363].y = 11;
LeftArmPartTwoMap[364].x = 34;
LeftArmPartTwoMap[364].y = 11;
LeftArmPartTwoMap[95].x = 25;
LeftArmPartTwoMap[95].y = 12;
LeftArmPartTwoMap[89].x = 28;
LeftArmPartTwoMap[89].y = 12;
LeftArmPartTwoMap[87].x = 29;
LeftArmPartTwoMap[87].y = 12;
LeftArmPartTwoMap[88].x = 29;
LeftArmPartTwoMap[88].y = 12;
LeftArmPartTwoMap[86].x = 30;
LeftArmPartTwoMap[86].y = 12;
LeftArmPartTwoMap[217].x = 32;
LeftArmPartTwoMap[217].y = 12;
LeftArmPartTwoMap[218].x = 33;
LeftArmPartTwoMap[218].y = 12;
LeftArmPartTwoMap[224].x = 33;
LeftArmPartTwoMap[224].y = 12;
LeftArmPartTwoMap[225].x = 33;
LeftArmPartTwoMap[225].y = 12;
LeftArmPartTwoMap[222].x = 34;
LeftArmPartTwoMap[222].y = 12;
LeftArmPartTwoMap[223].x = 34;
LeftArmPartTwoMap[223].y = 12;
LeftArmPartTwoMap[365].x = 35;
LeftArmPartTwoMap[365].y = 12;
LeftArmPartTwoMap[85].x = 30;
LeftArmPartTwoMap[85].y = 13;
LeftArmPartTwoMap[83].x = 31;
LeftArmPartTwoMap[83].y = 13;
LeftArmPartTwoMap[84].x = 31;
LeftArmPartTwoMap[84].y = 13;
LeftArmPartTwoMap[216].x = 32;
LeftArmPartTwoMap[216].y = 13;
LeftArmPartTwoMap[219].x = 33;
LeftArmPartTwoMap[219].y = 13;
LeftArmPartTwoMap[220].x = 34;
LeftArmPartTwoMap[220].y = 13;
LeftArmPartTwoMap[221].x = 34;
LeftArmPartTwoMap[221].y = 13;
LeftArmPartTwoMap[81].x = 32;
LeftArmPartTwoMap[81].y = 14;
LeftArmPartTwoMap[82].x = 32;
LeftArmPartTwoMap[82].y = 14;
}

