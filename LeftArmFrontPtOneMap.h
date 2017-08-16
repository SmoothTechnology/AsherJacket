#include "CommonCode.h"

int xSizeLeftArmFrontPartOne = 28;
int ySizeLeftArmFrontPartOne = 14;
int minLEDLeftArmFrontPartOne = 3840;
int maxLEDLeftArmFrontPartOne = 4092;

LEDPos LeftArmPartOneMap [252];

void InitializeLeftArmFrontPartOneMap
{
LeftArmPartOneMap[64].x = 0;
LeftArmPartOneMap[64].y = 0;
LeftArmPartOneMap[65].x = 0;
LeftArmPartOneMap[65].y = 0;
LeftArmPartOneMap[61].x = 1;
LeftArmPartOneMap[61].y = 0;
LeftArmPartOneMap[62].x = 1;
LeftArmPartOneMap[62].y = 0;
LeftArmPartOneMap[63].x = 1;
LeftArmPartOneMap[63].y = 0;
LeftArmPartOneMap[67].x = 1;
LeftArmPartOneMap[67].y = 0;
LeftArmPartOneMap[68].x = 1;
LeftArmPartOneMap[68].y = 0;
LeftArmPartOneMap[69].x = 2;
LeftArmPartOneMap[69].y = 0;
LeftArmPartOneMap[69].x = 2;
LeftArmPartOneMap[69].y = 0;
LeftArmPartOneMap[70].x = 2;
LeftArmPartOneMap[70].y = 0;
LeftArmPartOneMap[71].x = 3;
LeftArmPartOneMap[71].y = 0;
LeftArmPartOneMap[72].x = 3;
LeftArmPartOneMap[72].y = 0;
LeftArmPartOneMap[182].x = 3;
LeftArmPartOneMap[182].y = 0;
LeftArmPartOneMap[183].x = 3;
LeftArmPartOneMap[183].y = 0;
LeftArmPartOneMap[184].x = 3;
LeftArmPartOneMap[184].y = 0;
LeftArmPartOneMap[73].x = 4;
LeftArmPartOneMap[73].y = 0;
LeftArmPartOneMap[180].x = 4;
LeftArmPartOneMap[180].y = 0;
LeftArmPartOneMap[181].x = 4;
LeftArmPartOneMap[181].y = 0;
LeftArmPartOneMap[203].x = 4;
LeftArmPartOneMap[203].y = 0;
LeftArmPartOneMap[178].x = 5;
LeftArmPartOneMap[178].y = 0;
LeftArmPartOneMap[179].x = 5;
LeftArmPartOneMap[179].y = 0;
LeftArmPartOneMap[205].x = 5;
LeftArmPartOneMap[205].y = 0;
LeftArmPartOneMap[206].x = 5;
LeftArmPartOneMap[206].y = 0;
LeftArmPartOneMap[207].x = 5;
LeftArmPartOneMap[207].y = 0;
LeftArmPartOneMap[177].x = 6;
LeftArmPartOneMap[177].y = 0;
LeftArmPartOneMap[208].x = 6;
LeftArmPartOneMap[208].y = 0;
LeftArmPartOneMap[209].x = 6;
LeftArmPartOneMap[209].y = 0;
LeftArmPartOneMap[210].x = 6;
LeftArmPartOneMap[210].y = 0;
LeftArmPartOneMap[211].x = 7;
LeftArmPartOneMap[211].y = 0;
LeftArmPartOneMap[212].x = 7;
LeftArmPartOneMap[212].y = 0;
LeftArmPartOneMap[59].x = 2;
LeftArmPartOneMap[59].y = 1;
LeftArmPartOneMap[60].x = 2;
LeftArmPartOneMap[60].y = 1;
LeftArmPartOneMap[58].x = 3;
LeftArmPartOneMap[58].y = 1;
LeftArmPartOneMap[74].x = 4;
LeftArmPartOneMap[74].y = 1;
LeftArmPartOneMap[75].x = 4;
LeftArmPartOneMap[75].y = 1;
LeftArmPartOneMap[76].x = 5;
LeftArmPartOneMap[76].y = 1;
LeftArmPartOneMap[77].x = 5;
LeftArmPartOneMap[77].y = 1;
LeftArmPartOneMap[78].x = 6;
LeftArmPartOneMap[78].y = 1;
LeftArmPartOneMap[176].x = 6;
LeftArmPartOneMap[176].y = 1;
LeftArmPartOneMap[173].x = 7;
LeftArmPartOneMap[173].y = 1;
LeftArmPartOneMap[174].x = 7;
LeftArmPartOneMap[174].y = 1;
LeftArmPartOneMap[175].x = 7;
LeftArmPartOneMap[175].y = 1;
LeftArmPartOneMap[213].x = 7;
LeftArmPartOneMap[213].y = 1;
LeftArmPartOneMap[172].x = 8;
LeftArmPartOneMap[172].y = 1;
LeftArmPartOneMap[214].x = 8;
LeftArmPartOneMap[214].y = 1;
LeftArmPartOneMap[215].x = 8;
LeftArmPartOneMap[215].y = 1;
LeftArmPartOneMap[169].x = 9;
LeftArmPartOneMap[169].y = 1;
LeftArmPartOneMap[170].x = 9;
LeftArmPartOneMap[170].y = 1;
LeftArmPartOneMap[171].x = 9;
LeftArmPartOneMap[171].y = 1;
LeftArmPartOneMap[216].x = 9;
LeftArmPartOneMap[216].y = 1;
LeftArmPartOneMap[217].x = 9;
LeftArmPartOneMap[217].y = 1;
LeftArmPartOneMap[218].x = 10;
LeftArmPartOneMap[218].y = 1;
LeftArmPartOneMap[230].x = 17;
LeftArmPartOneMap[230].y = 1;
LeftArmPartOneMap[155].x = 18;
LeftArmPartOneMap[155].y = 1;
LeftArmPartOneMap[231].x = 18;
LeftArmPartOneMap[231].y = 1;
LeftArmPartOneMap[232].x = 18;
LeftArmPartOneMap[232].y = 1;
LeftArmPartOneMap[56].x = 3;
LeftArmPartOneMap[56].y = 2;
LeftArmPartOneMap[57].x = 3;
LeftArmPartOneMap[57].y = 2;
LeftArmPartOneMap[54].x = 4;
LeftArmPartOneMap[54].y = 2;
LeftArmPartOneMap[55].x = 4;
LeftArmPartOneMap[55].y = 2;
LeftArmPartOneMap[53].x = 5;
LeftArmPartOneMap[53].y = 2;
LeftArmPartOneMap[79].x = 6;
LeftArmPartOneMap[79].y = 2;
LeftArmPartOneMap[80].x = 6;
LeftArmPartOneMap[80].y = 2;
LeftArmPartOneMap[81].x = 7;
LeftArmPartOneMap[81].y = 2;
LeftArmPartOneMap[82].x = 7;
LeftArmPartOneMap[82].y = 2;
LeftArmPartOneMap[219].x = 10;
LeftArmPartOneMap[219].y = 2;
LeftArmPartOneMap[220].x = 10;
LeftArmPartOneMap[220].y = 2;
LeftArmPartOneMap[221].x = 11;
LeftArmPartOneMap[221].y = 2;
LeftArmPartOneMap[222].x = 11;
LeftArmPartOneMap[222].y = 2;
LeftArmPartOneMap[223].x = 12;
LeftArmPartOneMap[223].y = 2;
LeftArmPartOneMap[52].x = 5;
LeftArmPartOneMap[52].y = 3;
LeftArmPartOneMap[49].x = 6;
LeftArmPartOneMap[49].y = 3;
LeftArmPartOneMap[50].x = 6;
LeftArmPartOneMap[50].y = 3;
LeftArmPartOneMap[51].x = 6;
LeftArmPartOneMap[51].y = 3;
LeftArmPartOneMap[48].x = 7;
LeftArmPartOneMap[48].y = 3;
LeftArmPartOneMap[83].x = 8;
LeftArmPartOneMap[83].y = 3;
LeftArmPartOneMap[84].x = 8;
LeftArmPartOneMap[84].y = 3;
LeftArmPartOneMap[85].x = 8;
LeftArmPartOneMap[85].y = 3;
LeftArmPartOneMap[86].x = 9;
LeftArmPartOneMap[86].y = 3;
LeftArmPartOneMap[87].x = 9;
LeftArmPartOneMap[87].y = 3;
LeftArmPartOneMap[168].x = 9;
LeftArmPartOneMap[168].y = 3;
LeftArmPartOneMap[165].x = 10;
LeftArmPartOneMap[165].y = 3;
LeftArmPartOneMap[166].x = 10;
LeftArmPartOneMap[166].y = 3;
LeftArmPartOneMap[167].x = 10;
LeftArmPartOneMap[167].y = 3;
LeftArmPartOneMap[163].x = 11;
LeftArmPartOneMap[163].y = 3;
LeftArmPartOneMap[164].x = 11;
LeftArmPartOneMap[164].y = 3;
LeftArmPartOneMap[162].x = 12;
LeftArmPartOneMap[162].y = 3;
LeftArmPartOneMap[224].x = 12;
LeftArmPartOneMap[224].y = 3;
LeftArmPartOneMap[225].x = 12;
LeftArmPartOneMap[225].y = 3;
LeftArmPartOneMap[226].x = 13;
LeftArmPartOneMap[226].y = 3;
LeftArmPartOneMap[227].x = 13;
LeftArmPartOneMap[227].y = 3;
LeftArmPartOneMap[228].x = 14;
LeftArmPartOneMap[228].y = 3;
LeftArmPartOneMap[229].x = 14;
LeftArmPartOneMap[229].y = 3;
LeftArmPartOneMap[233].x = 17;
LeftArmPartOneMap[233].y = 3;
LeftArmPartOneMap[47].x = 7;
LeftArmPartOneMap[47].y = 4;
LeftArmPartOneMap[45].x = 8;
LeftArmPartOneMap[45].y = 4;
LeftArmPartOneMap[46].x = 8;
LeftArmPartOneMap[46].y = 4;
LeftArmPartOneMap[43].x = 9;
LeftArmPartOneMap[43].y = 4;
LeftArmPartOneMap[44].x = 9;
LeftArmPartOneMap[44].y = 4;
LeftArmPartOneMap[88].x = 10;
LeftArmPartOneMap[88].y = 4;
LeftArmPartOneMap[89].x = 10;
LeftArmPartOneMap[89].y = 4;
LeftArmPartOneMap[90].x = 11;
LeftArmPartOneMap[90].y = 4;
LeftArmPartOneMap[91].x = 11;
LeftArmPartOneMap[91].y = 4;
LeftArmPartOneMap[92].x = 11;
LeftArmPartOneMap[92].y = 4;
LeftArmPartOneMap[93].x = 12;
LeftArmPartOneMap[93].y = 4;
LeftArmPartOneMap[161].x = 12;
LeftArmPartOneMap[161].y = 4;
LeftArmPartOneMap[159].x = 13;
LeftArmPartOneMap[159].y = 4;
LeftArmPartOneMap[160].x = 13;
LeftArmPartOneMap[160].y = 4;
LeftArmPartOneMap[156].x = 14;
LeftArmPartOneMap[156].y = 4;
LeftArmPartOneMap[157].x = 14;
LeftArmPartOneMap[157].y = 4;
LeftArmPartOneMap[158].x = 14;
LeftArmPartOneMap[158].y = 4;
LeftArmPartOneMap[154].x = 16;
LeftArmPartOneMap[154].y = 4;
LeftArmPartOneMap[234].x = 17;
LeftArmPartOneMap[234].y = 4;
LeftArmPartOneMap[40].x = 10;
LeftArmPartOneMap[40].y = 5;
LeftArmPartOneMap[41].x = 10;
LeftArmPartOneMap[41].y = 5;
LeftArmPartOneMap[42].x = 10;
LeftArmPartOneMap[42].y = 5;
LeftArmPartOneMap[38].x = 11;
LeftArmPartOneMap[38].y = 5;
LeftArmPartOneMap[39].x = 11;
LeftArmPartOneMap[39].y = 5;
LeftArmPartOneMap[94].x = 12;
LeftArmPartOneMap[94].y = 5;
LeftArmPartOneMap[95].x = 13;
LeftArmPartOneMap[95].y = 5;
LeftArmPartOneMap[96].x = 13;
LeftArmPartOneMap[96].y = 5;
LeftArmPartOneMap[97].x = 14;
LeftArmPartOneMap[97].y = 5;
LeftArmPartOneMap[98].x = 14;
LeftArmPartOneMap[98].y = 5;
LeftArmPartOneMap[152].x = 16;
LeftArmPartOneMap[152].y = 5;
LeftArmPartOneMap[153].x = 16;
LeftArmPartOneMap[153].y = 5;
LeftArmPartOneMap[151].x = 17;
LeftArmPartOneMap[151].y = 5;
LeftArmPartOneMap[235].x = 17;
LeftArmPartOneMap[235].y = 5;
LeftArmPartOneMap[236].x = 17;
LeftArmPartOneMap[236].y = 5;
LeftArmPartOneMap[237].x = 18;
LeftArmPartOneMap[237].y = 5;
LeftArmPartOneMap[35].x = 12;
LeftArmPartOneMap[35].y = 6;
LeftArmPartOneMap[36].x = 12;
LeftArmPartOneMap[36].y = 6;
LeftArmPartOneMap[37].x = 12;
LeftArmPartOneMap[37].y = 6;
LeftArmPartOneMap[34].x = 13;
LeftArmPartOneMap[34].y = 6;
LeftArmPartOneMap[99].x = 15;
LeftArmPartOneMap[99].y = 6;
LeftArmPartOneMap[100].x = 15;
LeftArmPartOneMap[100].y = 6;
LeftArmPartOneMap[101].x = 15;
LeftArmPartOneMap[101].y = 6;
LeftArmPartOneMap[102].x = 17;
LeftArmPartOneMap[102].y = 6;
LeftArmPartOneMap[103].x = 17;
LeftArmPartOneMap[103].y = 6;
LeftArmPartOneMap[150].x = 17;
LeftArmPartOneMap[150].y = 6;
LeftArmPartOneMap[105].x = 18;
LeftArmPartOneMap[105].y = 6;
LeftArmPartOneMap[148].x = 18;
LeftArmPartOneMap[148].y = 6;
LeftArmPartOneMap[149].x = 18;
LeftArmPartOneMap[149].y = 6;
LeftArmPartOneMap[238].x = 18;
LeftArmPartOneMap[238].y = 6;
LeftArmPartOneMap[239].x = 18;
LeftArmPartOneMap[239].y = 6;
LeftArmPartOneMap[147].x = 19;
LeftArmPartOneMap[147].y = 6;
LeftArmPartOneMap[202].x = 19;
LeftArmPartOneMap[202].y = 6;
LeftArmPartOneMap[240].x = 19;
LeftArmPartOneMap[240].y = 6;
LeftArmPartOneMap[241].x = 19;
LeftArmPartOneMap[241].y = 6;
LeftArmPartOneMap[200].x = 20;
LeftArmPartOneMap[200].y = 6;
LeftArmPartOneMap[201].x = 20;
LeftArmPartOneMap[201].y = 6;
LeftArmPartOneMap[242].x = 20;
LeftArmPartOneMap[242].y = 6;
LeftArmPartOneMap[243].x = 20;
LeftArmPartOneMap[243].y = 6;
LeftArmPartOneMap[244].x = 21;
LeftArmPartOneMap[244].y = 6;
LeftArmPartOneMap[33].x = 13;
LeftArmPartOneMap[33].y = 7;
LeftArmPartOneMap[31].x = 14;
LeftArmPartOneMap[31].y = 7;
LeftArmPartOneMap[32].x = 14;
LeftArmPartOneMap[32].y = 7;
LeftArmPartOneMap[30].x = 15;
LeftArmPartOneMap[30].y = 7;
LeftArmPartOneMap[104].x = 17;
LeftArmPartOneMap[104].y = 7;
LeftArmPartOneMap[106].x = 18;
LeftArmPartOneMap[106].y = 7;
LeftArmPartOneMap[107].x = 18;
LeftArmPartOneMap[107].y = 7;
LeftArmPartOneMap[108].x = 19;
LeftArmPartOneMap[108].y = 7;
LeftArmPartOneMap[109].x = 19;
LeftArmPartOneMap[109].y = 7;
LeftArmPartOneMap[145].x = 19;
LeftArmPartOneMap[145].y = 7;
LeftArmPartOneMap[146].x = 19;
LeftArmPartOneMap[146].y = 7;
LeftArmPartOneMap[143].x = 20;
LeftArmPartOneMap[143].y = 7;
LeftArmPartOneMap[144].x = 20;
LeftArmPartOneMap[144].y = 7;
LeftArmPartOneMap[199].x = 20;
LeftArmPartOneMap[199].y = 7;
LeftArmPartOneMap[197].x = 21;
LeftArmPartOneMap[197].y = 7;
LeftArmPartOneMap[198].x = 21;
LeftArmPartOneMap[198].y = 7;
LeftArmPartOneMap[196].x = 22;
LeftArmPartOneMap[196].y = 7;
LeftArmPartOneMap[245].x = 22;
LeftArmPartOneMap[245].y = 7;
LeftArmPartOneMap[246].x = 23;
LeftArmPartOneMap[246].y = 7;
LeftArmPartOneMap[247].x = 23;
LeftArmPartOneMap[247].y = 7;
LeftArmPartOneMap[248].x = 23;
LeftArmPartOneMap[248].y = 7;
LeftArmPartOneMap[249].x = 24;
LeftArmPartOneMap[249].y = 7;
LeftArmPartOneMap[250].x = 24;
LeftArmPartOneMap[250].y = 7;
LeftArmPartOneMap[192].x = 25;
LeftArmPartOneMap[192].y = 7;
LeftArmPartOneMap[193].x = 25;
LeftArmPartOneMap[193].y = 7;
LeftArmPartOneMap[29].x = 15;
LeftArmPartOneMap[29].y = 8;
LeftArmPartOneMap[26].x = 16;
LeftArmPartOneMap[26].y = 8;
LeftArmPartOneMap[27].x = 16;
LeftArmPartOneMap[27].y = 8;
LeftArmPartOneMap[28].x = 16;
LeftArmPartOneMap[28].y = 8;
LeftArmPartOneMap[25].x = 17;
LeftArmPartOneMap[25].y = 8;
LeftArmPartOneMap[110].x = 20;
LeftArmPartOneMap[110].y = 8;
LeftArmPartOneMap[111].x = 20;
LeftArmPartOneMap[111].y = 8;
LeftArmPartOneMap[112].x = 21;
LeftArmPartOneMap[112].y = 8;
LeftArmPartOneMap[113].x = 21;
LeftArmPartOneMap[113].y = 8;
LeftArmPartOneMap[141].x = 21;
LeftArmPartOneMap[141].y = 8;
LeftArmPartOneMap[142].x = 21;
LeftArmPartOneMap[142].y = 8;
LeftArmPartOneMap[138].x = 22;
LeftArmPartOneMap[138].y = 8;
LeftArmPartOneMap[139].x = 22;
LeftArmPartOneMap[139].y = 8;
LeftArmPartOneMap[140].x = 22;
LeftArmPartOneMap[140].y = 8;
LeftArmPartOneMap[195].x = 22;
LeftArmPartOneMap[195].y = 8;
LeftArmPartOneMap[194].x = 23;
LeftArmPartOneMap[194].y = 8;
LeftArmPartOneMap[191].x = 24;
LeftArmPartOneMap[191].y = 8;
LeftArmPartOneMap[251].x = 24;
LeftArmPartOneMap[251].y = 8;
LeftArmPartOneMap[252].x = 24;
LeftArmPartOneMap[252].y = 8;
LeftArmPartOneMap[186].x = 26;
LeftArmPartOneMap[186].y = 8;
LeftArmPartOneMap[24].x = 17;
LeftArmPartOneMap[24].y = 9;
LeftArmPartOneMap[22].x = 18;
LeftArmPartOneMap[22].y = 9;
LeftArmPartOneMap[23].x = 18;
LeftArmPartOneMap[23].y = 9;
LeftArmPartOneMap[20].x = 19;
LeftArmPartOneMap[20].y = 9;
LeftArmPartOneMap[21].x = 19;
LeftArmPartOneMap[21].y = 9;
LeftArmPartOneMap[114].x = 21;
LeftArmPartOneMap[114].y = 9;
LeftArmPartOneMap[115].x = 22;
LeftArmPartOneMap[115].y = 9;
LeftArmPartOneMap[116].x = 22;
LeftArmPartOneMap[116].y = 9;
LeftArmPartOneMap[117].x = 23;
LeftArmPartOneMap[117].y = 9;
LeftArmPartOneMap[136].x = 23;
LeftArmPartOneMap[136].y = 9;
LeftArmPartOneMap[137].x = 23;
LeftArmPartOneMap[137].y = 9;
LeftArmPartOneMap[134].x = 24;
LeftArmPartOneMap[134].y = 9;
LeftArmPartOneMap[135].x = 24;
LeftArmPartOneMap[135].y = 9;
LeftArmPartOneMap[133].x = 25;
LeftArmPartOneMap[133].y = 9;
LeftArmPartOneMap[189].x = 25;
LeftArmPartOneMap[189].y = 9;
LeftArmPartOneMap[190].x = 25;
LeftArmPartOneMap[190].y = 9;
LeftArmPartOneMap[185].x = 26;
LeftArmPartOneMap[185].y = 9;
LeftArmPartOneMap[187].x = 26;
LeftArmPartOneMap[187].y = 9;
LeftArmPartOneMap[188].x = 26;
LeftArmPartOneMap[188].y = 9;
LeftArmPartOneMap[18].x = 20;
LeftArmPartOneMap[18].y = 10;
LeftArmPartOneMap[19].x = 20;
LeftArmPartOneMap[19].y = 10;
LeftArmPartOneMap[15].x = 21;
LeftArmPartOneMap[15].y = 10;
LeftArmPartOneMap[16].x = 21;
LeftArmPartOneMap[16].y = 10;
LeftArmPartOneMap[17].x = 21;
LeftArmPartOneMap[17].y = 10;
LeftArmPartOneMap[118].x = 23;
LeftArmPartOneMap[118].y = 10;
LeftArmPartOneMap[119].x = 24;
LeftArmPartOneMap[119].y = 10;
LeftArmPartOneMap[120].x = 24;
LeftArmPartOneMap[120].y = 10;
LeftArmPartOneMap[131].x = 26;
LeftArmPartOneMap[131].y = 10;
LeftArmPartOneMap[132].x = 26;
LeftArmPartOneMap[132].y = 10;
LeftArmPartOneMap[129].x = 27;
LeftArmPartOneMap[129].y = 10;
LeftArmPartOneMap[130].x = 27;
LeftArmPartOneMap[130].y = 10;
LeftArmPartOneMap[0].x = 22;
LeftArmPartOneMap[0].y = 11;
LeftArmPartOneMap[13].x = 22;
LeftArmPartOneMap[13].y = 11;
LeftArmPartOneMap[14].x = 22;
LeftArmPartOneMap[14].y = 11;
LeftArmPartOneMap[11].x = 23;
LeftArmPartOneMap[11].y = 11;
LeftArmPartOneMap[12].x = 23;
LeftArmPartOneMap[12].y = 11;
LeftArmPartOneMap[10].x = 24;
LeftArmPartOneMap[10].y = 11;
LeftArmPartOneMap[121].x = 25;
LeftArmPartOneMap[121].y = 11;
LeftArmPartOneMap[122].x = 25;
LeftArmPartOneMap[122].y = 11;
LeftArmPartOneMap[123].x = 26;
LeftArmPartOneMap[123].y = 11;
LeftArmPartOneMap[124].x = 26;
LeftArmPartOneMap[124].y = 11;
LeftArmPartOneMap[125].x = 27;
LeftArmPartOneMap[125].y = 11;
LeftArmPartOneMap[126].x = 27;
LeftArmPartOneMap[126].y = 11;
LeftArmPartOneMap[8].x = 24;
LeftArmPartOneMap[8].y = 12;
LeftArmPartOneMap[9].x = 24;
LeftArmPartOneMap[9].y = 12;
LeftArmPartOneMap[6].x = 25;
LeftArmPartOneMap[6].y = 12;
LeftArmPartOneMap[7].x = 25;
LeftArmPartOneMap[7].y = 12;
LeftArmPartOneMap[4].x = 26;
LeftArmPartOneMap[4].y = 13;
LeftArmPartOneMap[5].x = 26;
LeftArmPartOneMap[5].y = 13;
LeftArmPartOneMap[2].x = 27;
LeftArmPartOneMap[2].y = 13;
LeftArmPartOneMap[3].x = 27;
LeftArmPartOneMap[3].y = 13;
}

