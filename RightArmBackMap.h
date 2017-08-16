int xSizeRightArmBack = 52;
int ySizeRightArmBack = 18;
int minLEDRightArmBack = 229;
int maxLEDRightArmBack = 853;

LEDPos RightArmBackMap [624];

void InitializeRightArmMap()
{
	RightArmBackMap[183].x = 7;
RightArmBackMap[183].y = 0;
RightArmBackMap[184].x = 7;
RightArmBackMap[184].y = 0;
RightArmBackMap[182].x = 10;
RightArmBackMap[182].y = 0;
RightArmBackMap[59].x = 11;
RightArmBackMap[59].y = 0;
RightArmBackMap[180].x = 11;
RightArmBackMap[180].y = 0;
RightArmBackMap[181].x = 11;
RightArmBackMap[181].y = 0;
RightArmBackMap[57].x = 12;
RightArmBackMap[57].y = 0;
RightArmBackMap[60].x = 12;
RightArmBackMap[60].y = 0;
RightArmBackMap[61].x = 12;
RightArmBackMap[61].y = 0;
RightArmBackMap[178].x = 12;
RightArmBackMap[178].y = 0;
RightArmBackMap[179].x = 12;
RightArmBackMap[179].y = 0;
RightArmBackMap[57].x = 12;
RightArmBackMap[57].y = 0;
RightArmBackMap[58].x = 12;
RightArmBackMap[58].y = 0;
RightArmBackMap[55].x = 13;
RightArmBackMap[55].y = 0;
RightArmBackMap[62].x = 13;
RightArmBackMap[62].y = 0;
RightArmBackMap[53].x = 14;
RightArmBackMap[53].y = 0;
RightArmBackMap[54].x = 14;
RightArmBackMap[54].y = 0;
RightArmBackMap[63].x = 14;
RightArmBackMap[63].y = 0;
RightArmBackMap[64].x = 14;
RightArmBackMap[64].y = 0;
RightArmBackMap[52].x = 15;
RightArmBackMap[52].y = 0;
RightArmBackMap[65].x = 15;
RightArmBackMap[65].y = 0;
RightArmBackMap[50].x = 16;
RightArmBackMap[50].y = 0;
RightArmBackMap[51].x = 16;
RightArmBackMap[51].y = 0;
RightArmBackMap[66].x = 16;
RightArmBackMap[66].y = 0;
RightArmBackMap[49].x = 17;
RightArmBackMap[49].y = 0;
RightArmBackMap[47].x = 18;
RightArmBackMap[47].y = 0;
RightArmBackMap[48].x = 18;
RightArmBackMap[48].y = 0;
RightArmBackMap[323].x = 3;
RightArmBackMap[323].y = 1;
RightArmBackMap[321].x = 4;
RightArmBackMap[321].y = 1;
RightArmBackMap[322].x = 4;
RightArmBackMap[322].y = 1;
RightArmBackMap[185].x = 8;
RightArmBackMap[185].y = 1;
RightArmBackMap[186].x = 8;
RightArmBackMap[186].y = 1;
RightArmBackMap[187].x = 9;
RightArmBackMap[187].y = 1;
RightArmBackMap[188].x = 9;
RightArmBackMap[188].y = 1;
RightArmBackMap[189].x = 10;
RightArmBackMap[189].y = 1;
RightArmBackMap[177].x = 13;
RightArmBackMap[177].y = 1;
RightArmBackMap[176].x = 14;
RightArmBackMap[176].y = 1;
RightArmBackMap[174].x = 15;
RightArmBackMap[174].y = 1;
RightArmBackMap[175].x = 15;
RightArmBackMap[175].y = 1;
RightArmBackMap[173].x = 16;
RightArmBackMap[173].y = 1;
RightArmBackMap[67].x = 17;
RightArmBackMap[67].y = 1;
RightArmBackMap[68].x = 17;
RightArmBackMap[68].y = 1;
RightArmBackMap[172].x = 17;
RightArmBackMap[172].y = 1;
RightArmBackMap[69].x = 18;
RightArmBackMap[69].y = 1;
RightArmBackMap[70].x = 18;
RightArmBackMap[70].y = 1;
RightArmBackMap[70].x = 18;
RightArmBackMap[70].y = 1;
RightArmBackMap[46].x = 19;
RightArmBackMap[46].y = 1;
RightArmBackMap[71].x = 19;
RightArmBackMap[71].y = 1;
RightArmBackMap[44].x = 20;
RightArmBackMap[44].y = 1;
RightArmBackMap[45].x = 20;
RightArmBackMap[45].y = 1;
RightArmBackMap[43].x = 21;
RightArmBackMap[43].y = 1;
RightArmBackMap[325].x = 1;
RightArmBackMap[325].y = 2;
RightArmBackMap[324].x = 2;
RightArmBackMap[324].y = 2;
RightArmBackMap[326].x = 2;
RightArmBackMap[326].y = 2;
RightArmBackMap[320].x = 5;
RightArmBackMap[320].y = 2;
RightArmBackMap[319].x = 6;
RightArmBackMap[319].y = 2;
RightArmBackMap[318].x = 7;
RightArmBackMap[318].y = 2;
RightArmBackMap[316].x = 8;
RightArmBackMap[316].y = 2;
RightArmBackMap[317].x = 8;
RightArmBackMap[317].y = 2;
RightArmBackMap[190].x = 11;
RightArmBackMap[190].y = 2;
RightArmBackMap[191].x = 12;
RightArmBackMap[191].y = 2;
RightArmBackMap[192].x = 12;
RightArmBackMap[192].y = 2;
RightArmBackMap[193].x = 13;
RightArmBackMap[193].y = 2;
RightArmBackMap[194].x = 14;
RightArmBackMap[194].y = 2;
RightArmBackMap[195].x = 15;
RightArmBackMap[195].y = 2;
RightArmBackMap[196].x = 15;
RightArmBackMap[196].y = 2;
RightArmBackMap[171].x = 18;
RightArmBackMap[171].y = 2;
RightArmBackMap[169].x = 19;
RightArmBackMap[169].y = 2;
RightArmBackMap[170].x = 19;
RightArmBackMap[170].y = 2;
RightArmBackMap[72].x = 20;
RightArmBackMap[72].y = 2;
RightArmBackMap[167].x = 20;
RightArmBackMap[167].y = 2;
RightArmBackMap[168].x = 20;
RightArmBackMap[168].y = 2;
RightArmBackMap[73].x = 21;
RightArmBackMap[73].y = 2;
RightArmBackMap[74].x = 21;
RightArmBackMap[74].y = 2;
RightArmBackMap[41].x = 22;
RightArmBackMap[41].y = 2;
RightArmBackMap[42].x = 22;
RightArmBackMap[42].y = 2;
RightArmBackMap[75].x = 22;
RightArmBackMap[75].y = 2;
RightArmBackMap[39].x = 23;
RightArmBackMap[39].y = 2;
RightArmBackMap[40].x = 23;
RightArmBackMap[40].y = 2;
RightArmBackMap[76].x = 23;
RightArmBackMap[76].y = 2;
RightArmBackMap[77].x = 23;
RightArmBackMap[77].y = 2;
RightArmBackMap[38].x = 24;
RightArmBackMap[38].y = 2;
RightArmBackMap[78].x = 24;
RightArmBackMap[78].y = 2;
RightArmBackMap[36].x = 25;
RightArmBackMap[36].y = 2;
RightArmBackMap[37].x = 25;
RightArmBackMap[37].y = 2;
RightArmBackMap[79].x = 25;
RightArmBackMap[79].y = 2;
RightArmBackMap[327].x = 3;
RightArmBackMap[327].y = 3;
RightArmBackMap[328].x = 4;
RightArmBackMap[328].y = 3;
RightArmBackMap[329].x = 4;
RightArmBackMap[329].y = 3;
RightArmBackMap[315].x = 9;
RightArmBackMap[315].y = 3;
RightArmBackMap[314].x = 10;
RightArmBackMap[314].y = 3;
RightArmBackMap[312].x = 11;
RightArmBackMap[312].y = 3;
RightArmBackMap[313].x = 11;
RightArmBackMap[313].y = 3;
RightArmBackMap[311].x = 12;
RightArmBackMap[311].y = 3;
RightArmBackMap[197].x = 16;
RightArmBackMap[197].y = 3;
RightArmBackMap[198].x = 17;
RightArmBackMap[198].y = 3;
RightArmBackMap[199].x = 17;
RightArmBackMap[199].y = 3;
RightArmBackMap[200].x = 18;
RightArmBackMap[200].y = 3;
RightArmBackMap[201].x = 19;
RightArmBackMap[201].y = 3;
RightArmBackMap[166].x = 21;
RightArmBackMap[166].y = 3;
RightArmBackMap[164].x = 22;
RightArmBackMap[164].y = 3;
RightArmBackMap[165].x = 22;
RightArmBackMap[165].y = 3;
RightArmBackMap[163].x = 23;
RightArmBackMap[163].y = 3;
RightArmBackMap[161].x = 24;
RightArmBackMap[161].y = 3;
RightArmBackMap[162].x = 24;
RightArmBackMap[162].y = 3;
RightArmBackMap[80].x = 25;
RightArmBackMap[80].y = 3;
RightArmBackMap[35].x = 26;
RightArmBackMap[35].y = 3;
RightArmBackMap[81].x = 26;
RightArmBackMap[81].y = 3;
RightArmBackMap[33].x = 27;
RightArmBackMap[33].y = 3;
RightArmBackMap[34].x = 27;
RightArmBackMap[34].y = 3;
RightArmBackMap[82].x = 27;
RightArmBackMap[82].y = 3;
RightArmBackMap[83].x = 27;
RightArmBackMap[83].y = 3;
RightArmBackMap[32].x = 28;
RightArmBackMap[32].y = 3;
RightArmBackMap[84].x = 28;
RightArmBackMap[84].y = 3;
RightArmBackMap[30].x = 29;
RightArmBackMap[30].y = 3;
RightArmBackMap[31].x = 29;
RightArmBackMap[31].y = 3;
RightArmBackMap[85].x = 29;
RightArmBackMap[85].y = 3;
RightArmBackMap[86].x = 29;
RightArmBackMap[86].y = 3;
RightArmBackMap[29].x = 30;
RightArmBackMap[29].y = 3;
RightArmBackMap[87].x = 30;
RightArmBackMap[87].y = 3;
RightArmBackMap[27].x = 31;
RightArmBackMap[27].y = 3;
RightArmBackMap[28].x = 31;
RightArmBackMap[28].y = 3;
RightArmBackMap[88].x = 31;
RightArmBackMap[88].y = 3;
RightArmBackMap[26].x = 32;
RightArmBackMap[26].y = 3;
RightArmBackMap[466].x = 0;
RightArmBackMap[466].y = 4;
RightArmBackMap[465].x = 1;
RightArmBackMap[465].y = 4;
RightArmBackMap[464].x = 2;
RightArmBackMap[464].y = 4;
RightArmBackMap[463].x = 3;
RightArmBackMap[463].y = 4;
RightArmBackMap[461].x = 4;
RightArmBackMap[461].y = 4;
RightArmBackMap[330].x = 5;
RightArmBackMap[330].y = 4;
RightArmBackMap[331].x = 6;
RightArmBackMap[331].y = 4;
RightArmBackMap[332].x = 6;
RightArmBackMap[332].y = 4;
RightArmBackMap[333].x = 7;
RightArmBackMap[333].y = 4;
RightArmBackMap[334].x = 8;
RightArmBackMap[334].y = 4;
RightArmBackMap[335].x = 9;
RightArmBackMap[335].y = 4;
RightArmBackMap[336].x = 10;
RightArmBackMap[336].y = 4;
RightArmBackMap[337].x = 10;
RightArmBackMap[337].y = 4;
RightArmBackMap[309].x = 13;
RightArmBackMap[309].y = 4;
RightArmBackMap[310].x = 13;
RightArmBackMap[310].y = 4;
RightArmBackMap[308].x = 14;
RightArmBackMap[308].y = 4;
RightArmBackMap[307].x = 15;
RightArmBackMap[307].y = 4;
RightArmBackMap[304].x = 16;
RightArmBackMap[304].y = 4;
RightArmBackMap[305].x = 16;
RightArmBackMap[305].y = 4;
RightArmBackMap[306].x = 16;
RightArmBackMap[306].y = 4;
RightArmBackMap[202].x = 19;
RightArmBackMap[202].y = 4;
RightArmBackMap[203].x = 20;
RightArmBackMap[203].y = 4;
RightArmBackMap[204].x = 21;
RightArmBackMap[204].y = 4;
RightArmBackMap[205].x = 22;
RightArmBackMap[205].y = 4;
RightArmBackMap[206].x = 22;
RightArmBackMap[206].y = 4;
RightArmBackMap[207].x = 23;
RightArmBackMap[207].y = 4;
RightArmBackMap[160].x = 25;
RightArmBackMap[160].y = 4;
RightArmBackMap[158].x = 26;
RightArmBackMap[158].y = 4;
RightArmBackMap[159].x = 26;
RightArmBackMap[159].y = 4;
RightArmBackMap[157].x = 27;
RightArmBackMap[157].y = 4;
RightArmBackMap[155].x = 28;
RightArmBackMap[155].y = 4;
RightArmBackMap[156].x = 28;
RightArmBackMap[156].y = 4;
RightArmBackMap[154].x = 29;
RightArmBackMap[154].y = 4;
RightArmBackMap[89].x = 31;
RightArmBackMap[89].y = 4;
RightArmBackMap[90].x = 32;
RightArmBackMap[90].y = 4;
RightArmBackMap[24].x = 33;
RightArmBackMap[24].y = 4;
RightArmBackMap[25].x = 33;
RightArmBackMap[25].y = 4;
RightArmBackMap[91].x = 33;
RightArmBackMap[91].y = 4;
RightArmBackMap[92].x = 33;
RightArmBackMap[92].y = 4;
RightArmBackMap[23].x = 34;
RightArmBackMap[23].y = 4;
RightArmBackMap[93].x = 34;
RightArmBackMap[93].y = 4;
RightArmBackMap[21].x = 35;
RightArmBackMap[21].y = 4;
RightArmBackMap[22].x = 35;
RightArmBackMap[22].y = 4;
RightArmBackMap[94].x = 35;
RightArmBackMap[94].y = 4;
RightArmBackMap[19].x = 36;
RightArmBackMap[19].y = 4;
RightArmBackMap[20].x = 36;
RightArmBackMap[20].y = 4;
RightArmBackMap[18].x = 37;
RightArmBackMap[18].y = 4;
RightArmBackMap[17].x = 38;
RightArmBackMap[17].y = 4;
RightArmBackMap[0].x = 40;
RightArmBackMap[0].y = 4;
RightArmBackMap[462].x = 3;
RightArmBackMap[462].y = 5;
RightArmBackMap[458].x = 6;
RightArmBackMap[458].y = 5;
RightArmBackMap[459].x = 6;
RightArmBackMap[459].y = 5;
RightArmBackMap[460].x = 6;
RightArmBackMap[460].y = 5;
RightArmBackMap[457].x = 7;
RightArmBackMap[457].y = 5;
RightArmBackMap[338].x = 11;
RightArmBackMap[338].y = 5;
RightArmBackMap[339].x = 12;
RightArmBackMap[339].y = 5;
RightArmBackMap[340].x = 12;
RightArmBackMap[340].y = 5;
RightArmBackMap[341].x = 13;
RightArmBackMap[341].y = 5;
RightArmBackMap[342].x = 14;
RightArmBackMap[342].y = 5;
RightArmBackMap[343].x = 15;
RightArmBackMap[343].y = 5;
RightArmBackMap[344].x = 15;
RightArmBackMap[344].y = 5;
RightArmBackMap[303].x = 17;
RightArmBackMap[303].y = 5;
RightArmBackMap[302].x = 18;
RightArmBackMap[302].y = 5;
RightArmBackMap[300].x = 19;
RightArmBackMap[300].y = 5;
RightArmBackMap[301].x = 19;
RightArmBackMap[301].y = 5;
RightArmBackMap[299].x = 20;
RightArmBackMap[299].y = 5;
RightArmBackMap[298].x = 21;
RightArmBackMap[298].y = 5;
RightArmBackMap[208].x = 24;
RightArmBackMap[208].y = 5;
RightArmBackMap[209].x = 24;
RightArmBackMap[209].y = 5;
RightArmBackMap[210].x = 25;
RightArmBackMap[210].y = 5;
RightArmBackMap[211].x = 26;
RightArmBackMap[211].y = 5;
RightArmBackMap[212].x = 26;
RightArmBackMap[212].y = 5;
RightArmBackMap[213].x = 27;
RightArmBackMap[213].y = 5;
RightArmBackMap[152].x = 30;
RightArmBackMap[152].y = 5;
RightArmBackMap[153].x = 30;
RightArmBackMap[153].y = 5;
RightArmBackMap[151].x = 31;
RightArmBackMap[151].y = 5;
RightArmBackMap[149].x = 32;
RightArmBackMap[149].y = 5;
RightArmBackMap[150].x = 32;
RightArmBackMap[150].y = 5;
RightArmBackMap[148].x = 33;
RightArmBackMap[148].y = 5;
RightArmBackMap[147].x = 34;
RightArmBackMap[147].y = 5;
RightArmBackMap[95].x = 35;
RightArmBackMap[95].y = 5;
RightArmBackMap[96].x = 36;
RightArmBackMap[96].y = 5;
RightArmBackMap[97].x = 37;
RightArmBackMap[97].y = 5;
RightArmBackMap[98].x = 37;
RightArmBackMap[98].y = 5;
RightArmBackMap[16].x = 38;
RightArmBackMap[16].y = 5;
RightArmBackMap[99].x = 38;
RightArmBackMap[99].y = 5;
RightArmBackMap[14].x = 39;
RightArmBackMap[14].y = 5;
RightArmBackMap[15].x = 39;
RightArmBackMap[15].y = 5;
RightArmBackMap[100].x = 39;
RightArmBackMap[100].y = 5;
RightArmBackMap[101].x = 39;
RightArmBackMap[101].y = 5;
RightArmBackMap[13].x = 40;
RightArmBackMap[13].y = 5;
RightArmBackMap[11].x = 41;
RightArmBackMap[11].y = 5;
RightArmBackMap[12].x = 41;
RightArmBackMap[12].y = 5;
RightArmBackMap[10].x = 42;
RightArmBackMap[10].y = 5;
RightArmBackMap[8].x = 43;
RightArmBackMap[8].y = 5;
RightArmBackMap[9].x = 43;
RightArmBackMap[9].y = 5;
RightArmBackMap[1].x = 46;
RightArmBackMap[1].y = 5;
RightArmBackMap[2].x = 46;
RightArmBackMap[2].y = 5;
RightArmBackMap[3].x = 47;
RightArmBackMap[3].y = 5;
RightArmBackMap[468].x = 1;
RightArmBackMap[468].y = 6;
RightArmBackMap[574].x = 1;
RightArmBackMap[574].y = 6;
RightArmBackMap[469].x = 2;
RightArmBackMap[469].y = 6;
RightArmBackMap[470].x = 3;
RightArmBackMap[470].y = 6;
RightArmBackMap[471].x = 3;
RightArmBackMap[471].y = 6;
RightArmBackMap[472].x = 4;
RightArmBackMap[472].y = 6;
RightArmBackMap[473].x = 5;
RightArmBackMap[473].y = 6;
RightArmBackMap[475].x = 6;
RightArmBackMap[475].y = 6;
RightArmBackMap[456].x = 8;
RightArmBackMap[456].y = 6;
RightArmBackMap[454].x = 9;
RightArmBackMap[454].y = 6;
RightArmBackMap[455].x = 9;
RightArmBackMap[455].y = 6;
RightArmBackMap[453].x = 10;
RightArmBackMap[453].y = 6;
RightArmBackMap[451].x = 11;
RightArmBackMap[451].y = 6;
RightArmBackMap[452].x = 11;
RightArmBackMap[452].y = 6;
RightArmBackMap[450].x = 12;
RightArmBackMap[450].y = 6;
RightArmBackMap[449].x = 13;
RightArmBackMap[449].y = 6;
RightArmBackMap[345].x = 16;
RightArmBackMap[345].y = 6;
RightArmBackMap[346].x = 16;
RightArmBackMap[346].y = 6;
RightArmBackMap[347].x = 17;
RightArmBackMap[347].y = 6;
RightArmBackMap[348].x = 18;
RightArmBackMap[348].y = 6;
RightArmBackMap[296].x = 22;
RightArmBackMap[296].y = 6;
RightArmBackMap[297].x = 22;
RightArmBackMap[297].y = 6;
RightArmBackMap[295].x = 23;
RightArmBackMap[295].y = 6;
RightArmBackMap[293].x = 24;
RightArmBackMap[293].y = 6;
RightArmBackMap[294].x = 24;
RightArmBackMap[294].y = 6;
RightArmBackMap[292].x = 25;
RightArmBackMap[292].y = 6;
RightArmBackMap[214].x = 28;
RightArmBackMap[214].y = 6;
RightArmBackMap[215].x = 28;
RightArmBackMap[215].y = 6;
RightArmBackMap[216].x = 29;
RightArmBackMap[216].y = 6;
RightArmBackMap[217].x = 30;
RightArmBackMap[217].y = 6;
RightArmBackMap[218].x = 30;
RightArmBackMap[218].y = 6;
RightArmBackMap[219].x = 31;
RightArmBackMap[219].y = 6;
RightArmBackMap[220].x = 31;
RightArmBackMap[220].y = 6;
RightArmBackMap[146].x = 34;
RightArmBackMap[146].y = 6;
RightArmBackMap[145].x = 35;
RightArmBackMap[145].y = 6;
RightArmBackMap[143].x = 36;
RightArmBackMap[143].y = 6;
RightArmBackMap[144].x = 36;
RightArmBackMap[144].y = 6;
RightArmBackMap[141].x = 37;
RightArmBackMap[141].y = 6;
RightArmBackMap[142].x = 37;
RightArmBackMap[142].y = 6;
RightArmBackMap[140].x = 38;
RightArmBackMap[140].y = 6;
RightArmBackMap[102].x = 40;
RightArmBackMap[102].y = 6;
RightArmBackMap[103].x = 40;
RightArmBackMap[103].y = 6;
RightArmBackMap[104].x = 41;
RightArmBackMap[104].y = 6;
RightArmBackMap[105].x = 42;
RightArmBackMap[105].y = 6;
RightArmBackMap[106].x = 43;
RightArmBackMap[106].y = 6;
RightArmBackMap[6].x = 44;
RightArmBackMap[6].y = 6;
RightArmBackMap[7].x = 44;
RightArmBackMap[7].y = 6;
RightArmBackMap[5].x = 45;
RightArmBackMap[5].y = 6;
RightArmBackMap[4].x = 46;
RightArmBackMap[4].y = 6;
RightArmBackMap[573].x = 2;
RightArmBackMap[573].y = 7;
RightArmBackMap[575].x = 2;
RightArmBackMap[575].y = 7;
RightArmBackMap[571].x = 3;
RightArmBackMap[571].y = 7;
RightArmBackMap[572].x = 3;
RightArmBackMap[572].y = 7;
RightArmBackMap[570].x = 4;
RightArmBackMap[570].y = 7;
RightArmBackMap[568].x = 5;
RightArmBackMap[568].y = 7;
RightArmBackMap[569].x = 5;
RightArmBackMap[569].y = 7;
RightArmBackMap[474].x = 6;
RightArmBackMap[474].y = 7;
RightArmBackMap[567].x = 6;
RightArmBackMap[567].y = 7;
RightArmBackMap[476].x = 7;
RightArmBackMap[476].y = 7;
RightArmBackMap[566].x = 7;
RightArmBackMap[566].y = 7;
RightArmBackMap[477].x = 8;
RightArmBackMap[477].y = 7;
RightArmBackMap[564].x = 8;
RightArmBackMap[564].y = 7;
RightArmBackMap[565].x = 8;
RightArmBackMap[565].y = 7;
RightArmBackMap[478].x = 9;
RightArmBackMap[478].y = 7;
RightArmBackMap[479].x = 9;
RightArmBackMap[479].y = 7;
RightArmBackMap[563].x = 9;
RightArmBackMap[563].y = 7;
RightArmBackMap[480].x = 10;
RightArmBackMap[480].y = 7;
RightArmBackMap[481].x = 11;
RightArmBackMap[481].y = 7;
RightArmBackMap[482].x = 11;
RightArmBackMap[482].y = 7;
RightArmBackMap[483].x = 12;
RightArmBackMap[483].y = 7;
RightArmBackMap[447].x = 14;
RightArmBackMap[447].y = 7;
RightArmBackMap[448].x = 14;
RightArmBackMap[448].y = 7;
RightArmBackMap[446].x = 15;
RightArmBackMap[446].y = 7;
RightArmBackMap[444].x = 16;
RightArmBackMap[444].y = 7;
RightArmBackMap[445].x = 16;
RightArmBackMap[445].y = 7;
RightArmBackMap[349].x = 19;
RightArmBackMap[349].y = 7;
RightArmBackMap[350].x = 19;
RightArmBackMap[350].y = 7;
RightArmBackMap[351].x = 20;
RightArmBackMap[351].y = 7;
RightArmBackMap[352].x = 21;
RightArmBackMap[352].y = 7;
RightArmBackMap[353].x = 22;
RightArmBackMap[353].y = 7;
RightArmBackMap[290].x = 26;
RightArmBackMap[290].y = 7;
RightArmBackMap[291].x = 26;
RightArmBackMap[291].y = 7;
RightArmBackMap[289].x = 27;
RightArmBackMap[289].y = 7;
RightArmBackMap[287].x = 28;
RightArmBackMap[287].y = 7;
RightArmBackMap[288].x = 28;
RightArmBackMap[288].y = 7;
RightArmBackMap[286].x = 29;
RightArmBackMap[286].y = 7;
RightArmBackMap[285].x = 30;
RightArmBackMap[285].y = 7;
RightArmBackMap[221].x = 32;
RightArmBackMap[221].y = 7;
RightArmBackMap[222].x = 33;
RightArmBackMap[222].y = 7;
RightArmBackMap[223].x = 34;
RightArmBackMap[223].y = 7;
RightArmBackMap[224].x = 34;
RightArmBackMap[224].y = 7;
RightArmBackMap[225].x = 35;
RightArmBackMap[225].y = 7;
RightArmBackMap[226].x = 36;
RightArmBackMap[226].y = 7;
RightArmBackMap[227].x = 36;
RightArmBackMap[227].y = 7;
RightArmBackMap[138].x = 39;
RightArmBackMap[138].y = 7;
RightArmBackMap[139].x = 39;
RightArmBackMap[139].y = 7;
RightArmBackMap[137].x = 40;
RightArmBackMap[137].y = 7;
RightArmBackMap[135].x = 41;
RightArmBackMap[135].y = 7;
RightArmBackMap[136].x = 41;
RightArmBackMap[136].y = 7;
RightArmBackMap[134].x = 42;
RightArmBackMap[134].y = 7;
RightArmBackMap[107].x = 43;
RightArmBackMap[107].y = 7;
RightArmBackMap[132].x = 43;
RightArmBackMap[132].y = 7;
RightArmBackMap[133].x = 43;
RightArmBackMap[133].y = 7;
RightArmBackMap[108].x = 44;
RightArmBackMap[108].y = 7;
RightArmBackMap[109].x = 44;
RightArmBackMap[109].y = 7;
RightArmBackMap[110].x = 45;
RightArmBackMap[110].y = 7;
RightArmBackMap[111].x = 46;
RightArmBackMap[111].y = 7;
RightArmBackMap[112].x = 46;
RightArmBackMap[112].y = 7;
RightArmBackMap[113].x = 47;
RightArmBackMap[113].y = 7;
RightArmBackMap[114].x = 47;
RightArmBackMap[114].y = 7;
RightArmBackMap[115].x = 48;
RightArmBackMap[115].y = 7;
RightArmBackMap[116].x = 49;
RightArmBackMap[116].y = 7;
RightArmBackMap[117].x = 50;
RightArmBackMap[117].y = 7;
RightArmBackMap[118].x = 50;
RightArmBackMap[118].y = 7;
RightArmBackMap[576].x = 2;
RightArmBackMap[576].y = 8;
RightArmBackMap[577].x = 3;
RightArmBackMap[577].y = 8;
RightArmBackMap[578].x = 4;
RightArmBackMap[578].y = 8;
RightArmBackMap[579].x = 5;
RightArmBackMap[579].y = 8;
RightArmBackMap[580].x = 5;
RightArmBackMap[580].y = 8;
RightArmBackMap[581].x = 6;
RightArmBackMap[581].y = 8;
RightArmBackMap[623].x = 6;
RightArmBackMap[623].y = 8;
RightArmBackMap[624].x = 6;
RightArmBackMap[624].y = 8;
RightArmBackMap[582].x = 7;
RightArmBackMap[582].y = 8;
RightArmBackMap[622].x = 7;
RightArmBackMap[622].y = 8;
RightArmBackMap[621].x = 7;
RightArmBackMap[621].y = 8;
RightArmBackMap[583].x = 8;
RightArmBackMap[583].y = 8;
RightArmBackMap[584].x = 8;
RightArmBackMap[584].y = 8;
RightArmBackMap[620].x = 8;
RightArmBackMap[620].y = 8;
RightArmBackMap[585].x = 9;
RightArmBackMap[585].y = 8;
RightArmBackMap[618].x = 9;
RightArmBackMap[618].y = 8;
RightArmBackMap[618].x = 9;
RightArmBackMap[618].y = 8;
RightArmBackMap[619].x = 9;
RightArmBackMap[619].y = 8;
RightArmBackMap[562].x = 10;
RightArmBackMap[562].y = 8;
RightArmBackMap[586].x = 10;
RightArmBackMap[586].y = 8;
RightArmBackMap[587].x = 10;
RightArmBackMap[587].y = 8;
RightArmBackMap[617].x = 10;
RightArmBackMap[617].y = 8;
RightArmBackMap[560].x = 11;
RightArmBackMap[560].y = 8;
RightArmBackMap[561].x = 11;
RightArmBackMap[561].y = 8;
RightArmBackMap[588].x = 11;
RightArmBackMap[588].y = 8;
RightArmBackMap[616].x = 11;
RightArmBackMap[616].y = 8;
RightArmBackMap[558].x = 12;
RightArmBackMap[558].y = 8;
RightArmBackMap[559].x = 12;
RightArmBackMap[559].y = 8;
RightArmBackMap[589].x = 12;
RightArmBackMap[589].y = 8;
RightArmBackMap[484].x = 13;
RightArmBackMap[484].y = 8;
RightArmBackMap[485].x = 13;
RightArmBackMap[485].y = 8;
RightArmBackMap[486].x = 14;
RightArmBackMap[486].y = 8;
RightArmBackMap[487].x = 15;
RightArmBackMap[487].y = 8;
RightArmBackMap[442].x = 17;
RightArmBackMap[442].y = 8;
RightArmBackMap[443].x = 17;
RightArmBackMap[443].y = 8;
RightArmBackMap[441].x = 18;
RightArmBackMap[441].y = 8;
RightArmBackMap[440].x = 19;
RightArmBackMap[440].y = 8;
RightArmBackMap[439].x = 20;
RightArmBackMap[439].y = 8;
RightArmBackMap[354].x = 22;
RightArmBackMap[354].y = 8;
RightArmBackMap[355].x = 23;
RightArmBackMap[355].y = 8;
RightArmBackMap[356].x = 24;
RightArmBackMap[356].y = 8;
RightArmBackMap[357].x = 24;
RightArmBackMap[357].y = 8;
RightArmBackMap[358].x = 25;
RightArmBackMap[358].y = 8;
RightArmBackMap[359].x = 26;
RightArmBackMap[359].y = 8;
RightArmBackMap[360].x = 26;
RightArmBackMap[360].y = 8;
RightArmBackMap[361].x = 27;
RightArmBackMap[361].y = 8;
RightArmBackMap[284].x = 30;
RightArmBackMap[284].y = 8;
RightArmBackMap[283].x = 31;
RightArmBackMap[283].y = 8;
RightArmBackMap[281].x = 32;
RightArmBackMap[281].y = 8;
RightArmBackMap[282].x = 32;
RightArmBackMap[282].y = 8;
RightArmBackMap[280].x = 33;
RightArmBackMap[280].y = 8;
RightArmBackMap[279].x = 34;
RightArmBackMap[279].y = 8;
RightArmBackMap[228].x = 37;
RightArmBackMap[228].y = 8;
RightArmBackMap[229].x = 38;
RightArmBackMap[229].y = 8;
RightArmBackMap[230].x = 38;
RightArmBackMap[230].y = 8;
RightArmBackMap[231].x = 39;
RightArmBackMap[231].y = 8;
RightArmBackMap[232].x = 39;
RightArmBackMap[232].y = 8;
RightArmBackMap[233].x = 40;
RightArmBackMap[233].y = 8;
RightArmBackMap[131].x = 44;
RightArmBackMap[131].y = 8;
RightArmBackMap[129].x = 45;
RightArmBackMap[129].y = 8;
RightArmBackMap[130].x = 45;
RightArmBackMap[130].y = 8;
RightArmBackMap[128].x = 46;
RightArmBackMap[128].y = 8;
RightArmBackMap[126].x = 47;
RightArmBackMap[126].y = 8;
RightArmBackMap[127].x = 47;
RightArmBackMap[127].y = 8;
RightArmBackMap[125].x = 48;
RightArmBackMap[125].y = 8;
RightArmBackMap[124].x = 49;
RightArmBackMap[124].y = 8;
RightArmBackMap[590].x = 12;
RightArmBackMap[590].y = 9;
RightArmBackMap[615].x = 12;
RightArmBackMap[615].y = 9;
RightArmBackMap[557].x = 13;
RightArmBackMap[557].y = 9;
RightArmBackMap[591].x = 13;
RightArmBackMap[591].y = 9;
RightArmBackMap[613].x = 13;
RightArmBackMap[613].y = 9;
RightArmBackMap[614].x = 13;
RightArmBackMap[614].y = 9;
RightArmBackMap[614].x = 13;
RightArmBackMap[614].y = 9;
RightArmBackMap[555].x = 14;
RightArmBackMap[555].y = 9;
RightArmBackMap[556].x = 14;
RightArmBackMap[556].y = 9;
RightArmBackMap[592].x = 14;
RightArmBackMap[592].y = 9;
RightArmBackMap[593].x = 14;
RightArmBackMap[593].y = 9;
RightArmBackMap[611].x = 14;
RightArmBackMap[611].y = 9;
RightArmBackMap[612].x = 14;
RightArmBackMap[612].y = 9;
RightArmBackMap[488].x = 15;
RightArmBackMap[488].y = 9;
RightArmBackMap[554].x = 15;
RightArmBackMap[554].y = 9;
RightArmBackMap[610].x = 15;
RightArmBackMap[610].y = 9;
RightArmBackMap[489].x = 16;
RightArmBackMap[489].y = 9;
RightArmBackMap[553].x = 16;
RightArmBackMap[553].y = 9;
RightArmBackMap[609].x = 16;
RightArmBackMap[609].y = 9;
RightArmBackMap[490].x = 17;
RightArmBackMap[490].y = 9;
RightArmBackMap[491].x = 17;
RightArmBackMap[491].y = 9;
RightArmBackMap[492].x = 18;
RightArmBackMap[492].y = 9;
RightArmBackMap[438].x = 20;
RightArmBackMap[438].y = 9;
RightArmBackMap[437].x = 21;
RightArmBackMap[437].y = 9;
RightArmBackMap[435].x = 22;
RightArmBackMap[435].y = 9;
RightArmBackMap[436].x = 22;
RightArmBackMap[436].y = 9;
RightArmBackMap[434].x = 23;
RightArmBackMap[434].y = 9;
RightArmBackMap[432].x = 24;
RightArmBackMap[432].y = 9;
RightArmBackMap[433].x = 24;
RightArmBackMap[433].y = 9;
RightArmBackMap[431].x = 25;
RightArmBackMap[431].y = 9;
RightArmBackMap[362].x = 28;
RightArmBackMap[362].y = 9;
RightArmBackMap[363].x = 28;
RightArmBackMap[363].y = 9;
RightArmBackMap[364].x = 29;
RightArmBackMap[364].y = 9;
RightArmBackMap[365].x = 30;
RightArmBackMap[365].y = 9;
RightArmBackMap[366].x = 30;
RightArmBackMap[366].y = 9;
RightArmBackMap[367].x = 31;
RightArmBackMap[367].y = 9;
RightArmBackMap[278].x = 34;
RightArmBackMap[278].y = 9;
RightArmBackMap[277].x = 35;
RightArmBackMap[277].y = 9;
RightArmBackMap[275].x = 36;
RightArmBackMap[275].y = 9;
RightArmBackMap[276].x = 36;
RightArmBackMap[276].y = 9;
RightArmBackMap[274].x = 37;
RightArmBackMap[274].y = 9;
RightArmBackMap[272].x = 38;
RightArmBackMap[272].y = 9;
RightArmBackMap[273].x = 38;
RightArmBackMap[273].y = 9;
RightArmBackMap[234].x = 41;
RightArmBackMap[234].y = 9;
RightArmBackMap[235].x = 41;
RightArmBackMap[235].y = 9;
RightArmBackMap[236].x = 42;
RightArmBackMap[236].y = 9;
RightArmBackMap[237].x = 43;
RightArmBackMap[237].y = 9;
RightArmBackMap[238].x = 43;
RightArmBackMap[238].y = 9;
RightArmBackMap[239].x = 44;
RightArmBackMap[239].y = 9;
RightArmBackMap[240].x = 45;
RightArmBackMap[240].y = 9;
RightArmBackMap[123].x = 49;
RightArmBackMap[123].y = 9;
RightArmBackMap[121].x = 50;
RightArmBackMap[121].y = 9;
RightArmBackMap[122].x = 50;
RightArmBackMap[122].y = 9;
RightArmBackMap[120].x = 51;
RightArmBackMap[120].y = 9;
RightArmBackMap[251].x = 51;
RightArmBackMap[251].y = 9;
RightArmBackMap[594].x = 15;
RightArmBackMap[594].y = 10;
RightArmBackMap[595].x = 15;
RightArmBackMap[595].y = 10;
RightArmBackMap[596].x = 16;
RightArmBackMap[596].y = 10;
RightArmBackMap[608].x = 16;
RightArmBackMap[608].y = 10;
RightArmBackMap[552].x = 17;
RightArmBackMap[552].y = 10;
RightArmBackMap[548].x = 19;
RightArmBackMap[548].y = 10;
RightArmBackMap[603].x = 19;
RightArmBackMap[603].y = 10;
RightArmBackMap[495].x = 20;
RightArmBackMap[495].y = 10;
RightArmBackMap[547].x = 20;
RightArmBackMap[547].y = 10;
RightArmBackMap[496].x = 21;
RightArmBackMap[496].y = 10;
RightArmBackMap[546].x = 21;
RightArmBackMap[546].y = 10;
RightArmBackMap[497].x = 22;
RightArmBackMap[497].y = 10;
RightArmBackMap[498].x = 22;
RightArmBackMap[498].y = 10;
RightArmBackMap[544].x = 22;
RightArmBackMap[544].y = 10;
RightArmBackMap[545].x = 22;
RightArmBackMap[545].y = 10;
RightArmBackMap[499].x = 23;
RightArmBackMap[499].y = 10;
RightArmBackMap[542].x = 23;
RightArmBackMap[542].y = 10;
RightArmBackMap[543].x = 23;
RightArmBackMap[543].y = 10;
RightArmBackMap[500].x = 24;
RightArmBackMap[500].y = 10;
RightArmBackMap[501].x = 24;
RightArmBackMap[501].y = 10;
RightArmBackMap[541].x = 24;
RightArmBackMap[541].y = 10;
RightArmBackMap[502].x = 25;
RightArmBackMap[502].y = 10;
RightArmBackMap[429].x = 26;
RightArmBackMap[429].y = 10;
RightArmBackMap[430].x = 26;
RightArmBackMap[430].y = 10;
RightArmBackMap[428].x = 27;
RightArmBackMap[428].y = 10;
RightArmBackMap[426].x = 28;
RightArmBackMap[426].y = 10;
RightArmBackMap[427].x = 28;
RightArmBackMap[427].y = 10;
RightArmBackMap[368].x = 32;
RightArmBackMap[368].y = 10;
RightArmBackMap[369].x = 32;
RightArmBackMap[369].y = 10;
RightArmBackMap[370].x = 33;
RightArmBackMap[370].y = 10;
RightArmBackMap[371].x = 34;
RightArmBackMap[371].y = 10;
RightArmBackMap[372].x = 34;
RightArmBackMap[372].y = 10;
RightArmBackMap[373].x = 35;
RightArmBackMap[373].y = 10;
RightArmBackMap[374].x = 35;
RightArmBackMap[374].y = 10;
RightArmBackMap[375].x = 36;
RightArmBackMap[375].y = 10;
RightArmBackMap[376].x = 37;
RightArmBackMap[376].y = 10;
RightArmBackMap[270].x = 39;
RightArmBackMap[270].y = 10;
RightArmBackMap[271].x = 39;
RightArmBackMap[271].y = 10;
RightArmBackMap[269].x = 40;
RightArmBackMap[269].y = 10;
RightArmBackMap[267].x = 41;
RightArmBackMap[267].y = 10;
RightArmBackMap[268].x = 41;
RightArmBackMap[268].y = 10;
RightArmBackMap[266].x = 42;
RightArmBackMap[266].y = 10;
RightArmBackMap[264].x = 43;
RightArmBackMap[264].y = 10;
RightArmBackMap[265].x = 43;
RightArmBackMap[265].y = 10;
RightArmBackMap[241].x = 45;
RightArmBackMap[241].y = 10;
RightArmBackMap[242].x = 46;
RightArmBackMap[242].y = 10;
RightArmBackMap[243].x = 47;
RightArmBackMap[243].y = 10;
RightArmBackMap[244].x = 47;
RightArmBackMap[244].y = 10;
RightArmBackMap[245].x = 48;
RightArmBackMap[245].y = 10;
RightArmBackMap[246].x = 48;
RightArmBackMap[246].y = 10;
RightArmBackMap[247].x = 49;
RightArmBackMap[247].y = 10;
RightArmBackMap[248].x = 50;
RightArmBackMap[248].y = 10;
RightArmBackMap[119].x = 51;
RightArmBackMap[119].y = 10;
RightArmBackMap[597].x = 17;
RightArmBackMap[597].y = 11;
RightArmBackMap[598].x = 17;
RightArmBackMap[598].y = 11;
RightArmBackMap[550].x = 18;
RightArmBackMap[550].y = 11;
RightArmBackMap[606].x = 18;
RightArmBackMap[606].y = 11;
RightArmBackMap[549].x = 19;
RightArmBackMap[549].y = 11;
RightArmBackMap[551].x = 19;
RightArmBackMap[551].y = 11;
RightArmBackMap[604].x = 19;
RightArmBackMap[604].y = 11;
RightArmBackMap[605].x = 19;
RightArmBackMap[605].y = 11;
RightArmBackMap[607].x = 19;
RightArmBackMap[607].y = 11;
RightArmBackMap[493].x = 20;
RightArmBackMap[493].y = 11;
RightArmBackMap[494].x = 20;
RightArmBackMap[494].y = 11;
RightArmBackMap[599].x = 20;
RightArmBackMap[599].y = 11;
RightArmBackMap[602].x = 20;
RightArmBackMap[602].y = 11;
RightArmBackMap[600].x = 21;
RightArmBackMap[600].y = 11;
RightArmBackMap[601].x = 21;
RightArmBackMap[601].y = 11;
RightArmBackMap[539].x = 25;
RightArmBackMap[539].y = 11;
RightArmBackMap[540].x = 25;
RightArmBackMap[540].y = 11;
RightArmBackMap[503].x = 26;
RightArmBackMap[503].y = 11;
RightArmBackMap[538].x = 26;
RightArmBackMap[538].y = 11;
RightArmBackMap[506].x = 28;
RightArmBackMap[506].y = 11;
RightArmBackMap[509].x = 29;
RightArmBackMap[509].y = 11;
RightArmBackMap[423].x = 30;
RightArmBackMap[423].y = 11;
RightArmBackMap[424].x = 30;
RightArmBackMap[424].y = 11;
RightArmBackMap[510].x = 30;
RightArmBackMap[510].y = 11;
RightArmBackMap[421].x = 31;
RightArmBackMap[421].y = 11;
RightArmBackMap[422].x = 31;
RightArmBackMap[422].y = 11;
RightArmBackMap[511].x = 31;
RightArmBackMap[511].y = 11;
RightArmBackMap[420].x = 32;
RightArmBackMap[420].y = 11;
RightArmBackMap[418].x = 33;
RightArmBackMap[418].y = 11;
RightArmBackMap[419].x = 33;
RightArmBackMap[419].y = 11;
RightArmBackMap[417].x = 34;
RightArmBackMap[417].y = 11;
RightArmBackMap[377].x = 37;
RightArmBackMap[377].y = 11;
RightArmBackMap[378].x = 38;
RightArmBackMap[378].y = 11;
RightArmBackMap[379].x = 38;
RightArmBackMap[379].y = 11;
RightArmBackMap[380].x = 39;
RightArmBackMap[380].y = 11;
RightArmBackMap[381].x = 40;
RightArmBackMap[381].y = 11;
RightArmBackMap[382].x = 40;
RightArmBackMap[382].y = 11;
RightArmBackMap[262].x = 44;
RightArmBackMap[262].y = 11;
RightArmBackMap[263].x = 44;
RightArmBackMap[263].y = 11;
RightArmBackMap[261].x = 45;
RightArmBackMap[261].y = 11;
RightArmBackMap[259].x = 46;
RightArmBackMap[259].y = 11;
RightArmBackMap[260].x = 46;
RightArmBackMap[260].y = 11;
RightArmBackMap[257].x = 47;
RightArmBackMap[257].y = 11;
RightArmBackMap[258].x = 47;
RightArmBackMap[258].y = 11;
RightArmBackMap[256].x = 48;
RightArmBackMap[256].y = 11;
RightArmBackMap[254].x = 49;
RightArmBackMap[254].y = 11;
RightArmBackMap[255].x = 49;
RightArmBackMap[255].y = 11;
RightArmBackMap[249].x = 50;
RightArmBackMap[249].y = 11;
RightArmBackMap[252].x = 50;
RightArmBackMap[252].y = 11;
RightArmBackMap[253].x = 50;
RightArmBackMap[253].y = 11;
RightArmBackMap[504].x = 28;
RightArmBackMap[504].y = 12;
RightArmBackMap[505].x = 28;
RightArmBackMap[505].y = 12;
RightArmBackMap[507].x = 28;
RightArmBackMap[507].y = 12;
RightArmBackMap[508].x = 29;
RightArmBackMap[508].y = 12;
RightArmBackMap[537].x = 30;
RightArmBackMap[537].y = 12;
RightArmBackMap[513].x = 32;
RightArmBackMap[513].y = 12;
RightArmBackMap[514].x = 32;
RightArmBackMap[514].y = 12;
RightArmBackMap[515].x = 33;
RightArmBackMap[515].y = 12;
RightArmBackMap[415].x = 35;
RightArmBackMap[415].y = 12;
RightArmBackMap[416].x = 35;
RightArmBackMap[416].y = 12;
RightArmBackMap[517].x = 35;
RightArmBackMap[517].y = 12;
RightArmBackMap[518].x = 35;
RightArmBackMap[518].y = 12;
RightArmBackMap[414].x = 36;
RightArmBackMap[414].y = 12;
RightArmBackMap[519].x = 36;
RightArmBackMap[519].y = 12;
RightArmBackMap[520].x = 36;
RightArmBackMap[520].y = 12;
RightArmBackMap[412].x = 37;
RightArmBackMap[412].y = 12;
RightArmBackMap[413].x = 37;
RightArmBackMap[413].y = 12;
RightArmBackMap[521].x = 37;
RightArmBackMap[521].y = 12;
RightArmBackMap[411].x = 38;
RightArmBackMap[411].y = 12;
RightArmBackMap[522].x = 38;
RightArmBackMap[522].y = 12;
RightArmBackMap[523].x = 38;
RightArmBackMap[523].y = 12;
RightArmBackMap[409].x = 39;
RightArmBackMap[409].y = 12;
RightArmBackMap[408].x = 40;
RightArmBackMap[408].y = 12;
RightArmBackMap[383].x = 41;
RightArmBackMap[383].y = 12;
RightArmBackMap[384].x = 41;
RightArmBackMap[384].y = 12;
RightArmBackMap[385].x = 42;
RightArmBackMap[385].y = 12;
RightArmBackMap[404].x = 42;
RightArmBackMap[404].y = 12;
RightArmBackMap[386].x = 43;
RightArmBackMap[386].y = 12;
RightArmBackMap[387].x = 43;
RightArmBackMap[387].y = 12;
RightArmBackMap[388].x = 44;
RightArmBackMap[388].y = 12;
RightArmBackMap[389].x = 44;
RightArmBackMap[389].y = 12;
RightArmBackMap[390].x = 45;
RightArmBackMap[390].y = 12;
RightArmBackMap[391].x = 46;
RightArmBackMap[391].y = 12;
RightArmBackMap[392].x = 46;
RightArmBackMap[392].y = 12;
RightArmBackMap[393].x = 47;
RightArmBackMap[393].y = 12;
RightArmBackMap[425].x = 30;
RightArmBackMap[425].y = 13;
RightArmBackMap[512].x = 31;
RightArmBackMap[512].y = 13;
RightArmBackMap[410].x = 38;
RightArmBackMap[410].y = 13;
RightArmBackMap[524].x = 39;
RightArmBackMap[524].y = 13;
RightArmBackMap[407].x = 40;
RightArmBackMap[407].y = 13;
RightArmBackMap[525].x = 40;
RightArmBackMap[525].y = 13;
RightArmBackMap[406].x = 41;
RightArmBackMap[406].y = 13;
RightArmBackMap[527].x = 41;
RightArmBackMap[527].y = 13;
RightArmBackMap[528].x = 41;
RightArmBackMap[528].y = 13;
RightArmBackMap[405].x = 42;
RightArmBackMap[405].y = 13;
RightArmBackMap[530].x = 42;
RightArmBackMap[530].y = 13;
RightArmBackMap[399].x = 44;
RightArmBackMap[399].y = 13;
RightArmBackMap[400].x = 44;
RightArmBackMap[400].y = 13;
RightArmBackMap[397].x = 45;
RightArmBackMap[397].y = 13;
RightArmBackMap[398].x = 45;
RightArmBackMap[398].y = 13;
RightArmBackMap[396].x = 46;
RightArmBackMap[396].y = 13;
RightArmBackMap[394].x = 48;
RightArmBackMap[394].y = 13;
RightArmBackMap[395].x = 48;
RightArmBackMap[395].y = 13;
RightArmBackMap[526].x = 40;
RightArmBackMap[526].y = 14;
RightArmBackMap[529].x = 41;
RightArmBackMap[529].y = 14;
RightArmBackMap[403].x = 42;
RightArmBackMap[403].y = 14;
RightArmBackMap[401].x = 43;
RightArmBackMap[401].y = 14;
RightArmBackMap[402].x = 43;
RightArmBackMap[402].y = 14;
RightArmBackMap[532].x = 43;
RightArmBackMap[532].y = 14;
RightArmBackMap[516].x = 35;
RightArmBackMap[516].y = 15;
RightArmBackMap[531].x = 43;
RightArmBackMap[531].y = 15;
RightArmBackMap[533].x = 44;
RightArmBackMap[533].y = 15;
RightArmBackMap[534].x = 44;
RightArmBackMap[534].y = 15;
RightArmBackMap[536].x = 45;
RightArmBackMap[536].y = 17;
}

