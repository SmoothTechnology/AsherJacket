int xSizeRightBack = 49;
int ySizeRightBack = 16;
int minLEDRightBack = 6400;
int maxLEDRightBack = 7075;

LEDPos RightBackMap [676];

void InitializeRightBackMap()
{
	RightBackMap[664].x = 33;
RightBackMap[664].y = 0;
RightBackMap[665].x = 33;
RightBackMap[665].y = 0;
RightBackMap[666].x = 34;
RightBackMap[666].y = 0;
RightBackMap[667].x = 35;
RightBackMap[667].y = 0;
RightBackMap[668].x = 35;
RightBackMap[668].y = 0;
RightBackMap[669].x = 36;
RightBackMap[669].y = 0;
RightBackMap[670].x = 37;
RightBackMap[670].y = 0;
RightBackMap[671].x = 38;
RightBackMap[671].y = 0;
RightBackMap[672].x = 38;
RightBackMap[672].y = 0;
RightBackMap[673].x = 39;
RightBackMap[673].y = 0;
RightBackMap[674].x = 40;
RightBackMap[674].y = 0;
RightBackMap[545].x = 41;
RightBackMap[545].y = 0;
RightBackMap[628].x = 7;
RightBackMap[628].y = 1;
RightBackMap[629].x = 8;
RightBackMap[629].y = 1;
RightBackMap[630].x = 9;
RightBackMap[630].y = 1;
RightBackMap[631].x = 9;
RightBackMap[631].y = 1;
RightBackMap[632].x = 10;
RightBackMap[632].y = 1;
RightBackMap[633].x = 11;
RightBackMap[633].y = 1;
RightBackMap[634].x = 12;
RightBackMap[634].y = 1;
RightBackMap[635].x = 12;
RightBackMap[635].y = 1;
RightBackMap[636].x = 13;
RightBackMap[636].y = 1;
RightBackMap[637].x = 14;
RightBackMap[637].y = 1;
RightBackMap[638].x = 15;
RightBackMap[638].y = 1;
RightBackMap[639].x = 15;
RightBackMap[639].y = 1;
RightBackMap[640].x = 16;
RightBackMap[640].y = 1;
RightBackMap[641].x = 17;
RightBackMap[641].y = 1;
RightBackMap[642].x = 17;
RightBackMap[642].y = 1;
RightBackMap[643].x = 18;
RightBackMap[643].y = 1;
RightBackMap[644].x = 19;
RightBackMap[644].y = 1;
RightBackMap[645].x = 20;
RightBackMap[645].y = 1;
RightBackMap[646].x = 20;
RightBackMap[646].y = 1;
RightBackMap[647].x = 21;
RightBackMap[647].y = 1;
RightBackMap[648].x = 22;
RightBackMap[648].y = 1;
RightBackMap[649].x = 22;
RightBackMap[649].y = 1;
RightBackMap[650].x = 23;
RightBackMap[650].y = 1;
RightBackMap[651].x = 24;
RightBackMap[651].y = 1;
RightBackMap[652].x = 25;
RightBackMap[652].y = 1;
RightBackMap[653].x = 25;
RightBackMap[653].y = 1;
RightBackMap[654].x = 26;
RightBackMap[654].y = 1;
RightBackMap[655].x = 27;
RightBackMap[655].y = 1;
RightBackMap[656].x = 27;
RightBackMap[656].y = 1;
RightBackMap[657].x = 28;
RightBackMap[657].y = 1;
RightBackMap[658].x = 29;
RightBackMap[658].y = 1;
RightBackMap[659].x = 29;
RightBackMap[659].y = 1;
RightBackMap[660].x = 30;
RightBackMap[660].y = 1;
RightBackMap[661].x = 31;
RightBackMap[661].y = 1;
RightBackMap[662].x = 31;
RightBackMap[662].y = 1;
RightBackMap[663].x = 32;
RightBackMap[663].y = 1;
RightBackMap[555].x = 34;
RightBackMap[555].y = 1;
RightBackMap[554].x = 35;
RightBackMap[554].y = 1;
RightBackMap[552].x = 36;
RightBackMap[552].y = 1;
RightBackMap[553].x = 36;
RightBackMap[553].y = 1;
RightBackMap[551].x = 37;
RightBackMap[551].y = 1;
RightBackMap[550].x = 38;
RightBackMap[550].y = 1;
RightBackMap[548].x = 39;
RightBackMap[548].y = 1;
RightBackMap[549].x = 39;
RightBackMap[549].y = 1;
RightBackMap[547].x = 40;
RightBackMap[547].y = 1;
RightBackMap[546].x = 41;
RightBackMap[546].y = 1;
RightBackMap[544].x = 43;
RightBackMap[544].y = 1;
RightBackMap[622].x = 3;
RightBackMap[622].y = 2;
RightBackMap[623].x = 4;
RightBackMap[623].y = 2;
RightBackMap[624].x = 5;
RightBackMap[624].y = 2;
RightBackMap[625].x = 5;
RightBackMap[625].y = 2;
RightBackMap[626].x = 6;
RightBackMap[626].y = 2;
RightBackMap[627].x = 7;
RightBackMap[627].y = 2;
RightBackMap[588].x = 11;
RightBackMap[588].y = 2;
RightBackMap[587].x = 12;
RightBackMap[587].y = 2;
RightBackMap[585].x = 13;
RightBackMap[585].y = 2;
RightBackMap[586].x = 13;
RightBackMap[586].y = 2;
RightBackMap[584].x = 14;
RightBackMap[584].y = 2;
RightBackMap[583].x = 15;
RightBackMap[583].y = 2;
RightBackMap[581].x = 16;
RightBackMap[581].y = 2;
RightBackMap[582].x = 16;
RightBackMap[582].y = 2;
RightBackMap[580].x = 17;
RightBackMap[580].y = 2;
RightBackMap[579].x = 18;
RightBackMap[579].y = 2;
RightBackMap[577].x = 19;
RightBackMap[577].y = 2;
RightBackMap[578].x = 19;
RightBackMap[578].y = 2;
RightBackMap[576].x = 20;
RightBackMap[576].y = 2;
RightBackMap[574].x = 21;
RightBackMap[574].y = 2;
RightBackMap[575].x = 21;
RightBackMap[575].y = 2;
RightBackMap[573].x = 22;
RightBackMap[573].y = 2;
RightBackMap[572].x = 23;
RightBackMap[572].y = 2;
RightBackMap[570].x = 24;
RightBackMap[570].y = 2;
RightBackMap[571].x = 24;
RightBackMap[571].y = 2;
RightBackMap[569].x = 25;
RightBackMap[569].y = 2;
RightBackMap[567].x = 26;
RightBackMap[567].y = 2;
RightBackMap[568].x = 26;
RightBackMap[568].y = 2;
RightBackMap[566].x = 27;
RightBackMap[566].y = 2;
RightBackMap[564].x = 28;
RightBackMap[564].y = 2;
RightBackMap[565].x = 28;
RightBackMap[565].y = 2;
RightBackMap[563].x = 29;
RightBackMap[563].y = 2;
RightBackMap[561].x = 30;
RightBackMap[561].y = 2;
RightBackMap[562].x = 30;
RightBackMap[562].y = 2;
RightBackMap[560].x = 31;
RightBackMap[560].y = 2;
RightBackMap[558].x = 32;
RightBackMap[558].y = 2;
RightBackMap[559].x = 32;
RightBackMap[559].y = 2;
RightBackMap[557].x = 33;
RightBackMap[557].y = 2;
RightBackMap[556].x = 34;
RightBackMap[556].y = 2;
RightBackMap[536].x = 39;
RightBackMap[536].y = 2;
RightBackMap[537].x = 39;
RightBackMap[537].y = 2;
RightBackMap[538].x = 40;
RightBackMap[538].y = 2;
RightBackMap[539].x = 41;
RightBackMap[539].y = 2;
RightBackMap[540].x = 42;
RightBackMap[540].y = 2;
RightBackMap[541].x = 42;
RightBackMap[541].y = 2;
RightBackMap[542].x = 43;
RightBackMap[542].y = 2;
RightBackMap[618].x = 1;
RightBackMap[618].y = 3;
RightBackMap[619].x = 2;
RightBackMap[619].y = 3;
RightBackMap[620].x = 2;
RightBackMap[620].y = 3;
RightBackMap[621].x = 3;
RightBackMap[621].y = 3;
RightBackMap[598].x = 4;
RightBackMap[598].y = 3;
RightBackMap[596].x = 5;
RightBackMap[596].y = 3;
RightBackMap[597].x = 5;
RightBackMap[597].y = 3;
RightBackMap[595].x = 6;
RightBackMap[595].y = 3;
RightBackMap[594].x = 7;
RightBackMap[594].y = 3;
RightBackMap[592].x = 8;
RightBackMap[592].y = 3;
RightBackMap[593].x = 8;
RightBackMap[593].y = 3;
RightBackMap[591].x = 9;
RightBackMap[591].y = 3;
RightBackMap[589].x = 10;
RightBackMap[589].y = 3;
RightBackMap[590].x = 10;
RightBackMap[590].y = 3;
RightBackMap[504].x = 16;
RightBackMap[504].y = 3;
RightBackMap[505].x = 17;
RightBackMap[505].y = 3;
RightBackMap[506].x = 18;
RightBackMap[506].y = 3;
RightBackMap[507].x = 19;
RightBackMap[507].y = 3;
RightBackMap[508].x = 19;
RightBackMap[508].y = 3;
RightBackMap[509].x = 20;
RightBackMap[509].y = 3;
RightBackMap[510].x = 21;
RightBackMap[510].y = 3;
RightBackMap[511].x = 22;
RightBackMap[511].y = 3;
RightBackMap[512].x = 22;
RightBackMap[512].y = 3;
RightBackMap[513].x = 23;
RightBackMap[513].y = 3;
RightBackMap[514].x = 24;
RightBackMap[514].y = 3;
RightBackMap[518].x = 26;
RightBackMap[518].y = 3;
RightBackMap[519].x = 27;
RightBackMap[519].y = 3;
RightBackMap[520].x = 28;
RightBackMap[520].y = 3;
RightBackMap[521].x = 28;
RightBackMap[521].y = 3;
RightBackMap[522].x = 29;
RightBackMap[522].y = 3;
RightBackMap[523].x = 30;
RightBackMap[523].y = 3;
RightBackMap[524].x = 30;
RightBackMap[524].y = 3;
RightBackMap[525].x = 31;
RightBackMap[525].y = 3;
RightBackMap[526].x = 32;
RightBackMap[526].y = 3;
RightBackMap[527].x = 32;
RightBackMap[527].y = 3;
RightBackMap[316].x = 33;
RightBackMap[316].y = 3;
RightBackMap[528].x = 33;
RightBackMap[528].y = 3;
RightBackMap[315].x = 34;
RightBackMap[315].y = 3;
RightBackMap[420].x = 34;
RightBackMap[420].y = 3;
RightBackMap[421].x = 34;
RightBackMap[421].y = 3;
RightBackMap[529].x = 34;
RightBackMap[529].y = 3;
RightBackMap[314].x = 35;
RightBackMap[314].y = 3;
RightBackMap[530].x = 35;
RightBackMap[530].y = 3;
RightBackMap[531].x = 35;
RightBackMap[531].y = 3;
RightBackMap[311].x = 36;
RightBackMap[311].y = 3;
RightBackMap[312].x = 36;
RightBackMap[312].y = 3;
RightBackMap[532].x = 36;
RightBackMap[532].y = 3;
RightBackMap[533].x = 37;
RightBackMap[533].y = 3;
RightBackMap[534].x = 37;
RightBackMap[534].y = 3;
RightBackMap[535].x = 38;
RightBackMap[535].y = 3;
RightBackMap[612].x = 0;
RightBackMap[612].y = 4;
RightBackMap[613].x = 0;
RightBackMap[613].y = 4;
RightBackMap[614].x = 0;
RightBackMap[614].y = 4;
RightBackMap[615].x = 0;
RightBackMap[615].y = 4;
RightBackMap[603].x = 1;
RightBackMap[603].y = 4;
RightBackMap[616].x = 1;
RightBackMap[616].y = 4;
RightBackMap[617].x = 1;
RightBackMap[617].y = 4;
RightBackMap[601].x = 2;
RightBackMap[601].y = 4;
RightBackMap[602].x = 2;
RightBackMap[602].y = 4;
RightBackMap[599].x = 3;
RightBackMap[599].y = 4;
RightBackMap[600].x = 3;
RightBackMap[600].y = 4;
RightBackMap[491].x = 7;
RightBackMap[491].y = 4;
RightBackMap[492].x = 8;
RightBackMap[492].y = 4;
RightBackMap[493].x = 8;
RightBackMap[493].y = 4;
RightBackMap[494].x = 9;
RightBackMap[494].y = 4;
RightBackMap[495].x = 10;
RightBackMap[495].y = 4;
RightBackMap[496].x = 10;
RightBackMap[496].y = 4;
RightBackMap[497].x = 11;
RightBackMap[497].y = 4;
RightBackMap[498].x = 12;
RightBackMap[498].y = 4;
RightBackMap[499].x = 13;
RightBackMap[499].y = 4;
RightBackMap[500].x = 13;
RightBackMap[500].y = 4;
RightBackMap[501].x = 14;
RightBackMap[501].y = 4;
RightBackMap[502].x = 15;
RightBackMap[502].y = 4;
RightBackMap[503].x = 16;
RightBackMap[503].y = 4;
RightBackMap[516].x = 25;
RightBackMap[516].y = 4;
RightBackMap[432].x = 26;
RightBackMap[432].y = 4;
RightBackMap[517].x = 26;
RightBackMap[517].y = 4;
RightBackMap[430].x = 27;
RightBackMap[430].y = 4;
RightBackMap[431].x = 27;
RightBackMap[431].y = 4;
RightBackMap[399].x = 31;
RightBackMap[399].y = 4;
RightBackMap[400].x = 31;
RightBackMap[400].y = 4;
RightBackMap[423].x = 32;
RightBackMap[423].y = 4;
RightBackMap[422].x = 33;
RightBackMap[422].y = 4;
RightBackMap[419].x = 35;
RightBackMap[419].y = 4;
RightBackMap[313].x = 36;
RightBackMap[313].y = 4;
RightBackMap[417].x = 36;
RightBackMap[417].y = 4;
RightBackMap[310].x = 37;
RightBackMap[310].y = 4;
RightBackMap[416].x = 37;
RightBackMap[416].y = 4;
RightBackMap[308].x = 38;
RightBackMap[308].y = 4;
RightBackMap[309].x = 38;
RightBackMap[309].y = 4;
RightBackMap[401].x = 38;
RightBackMap[401].y = 4;
RightBackMap[415].x = 38;
RightBackMap[415].y = 4;
RightBackMap[412].x = 39;
RightBackMap[412].y = 4;
RightBackMap[413].x = 39;
RightBackMap[413].y = 4;
RightBackMap[414].x = 39;
RightBackMap[414].y = 4;
RightBackMap[402].x = 40;
RightBackMap[402].y = 4;
RightBackMap[411].x = 40;
RightBackMap[411].y = 4;
RightBackMap[403].x = 41;
RightBackMap[403].y = 4;
RightBackMap[404].x = 41;
RightBackMap[404].y = 4;
RightBackMap[410].x = 41;
RightBackMap[410].y = 4;
RightBackMap[405].x = 42;
RightBackMap[405].y = 4;
RightBackMap[409].x = 42;
RightBackMap[409].y = 4;
RightBackMap[406].x = 43;
RightBackMap[406].y = 4;
RightBackMap[408].x = 45;
RightBackMap[408].y = 4;
RightBackMap[407].x = 48;
RightBackMap[407].y = 4;
RightBackMap[606].x = 0;
RightBackMap[606].y = 5;
RightBackMap[611].x = 0;
RightBackMap[611].y = 5;
RightBackMap[604].x = 1;
RightBackMap[604].y = 5;
RightBackMap[605].x = 1;
RightBackMap[605].y = 5;
RightBackMap[485].x = 3;
RightBackMap[485].y = 5;
RightBackMap[486].x = 3;
RightBackMap[486].y = 5;
RightBackMap[487].x = 4;
RightBackMap[487].y = 5;
RightBackMap[488].x = 5;
RightBackMap[488].y = 5;
RightBackMap[489].x = 5;
RightBackMap[489].y = 5;
RightBackMap[490].x = 6;
RightBackMap[490].y = 5;
RightBackMap[455].x = 9;
RightBackMap[455].y = 5;
RightBackMap[454].x = 10;
RightBackMap[454].y = 5;
RightBackMap[452].x = 11;
RightBackMap[452].y = 5;
RightBackMap[453].x = 11;
RightBackMap[453].y = 5;
RightBackMap[451].x = 12;
RightBackMap[451].y = 5;
RightBackMap[450].x = 13;
RightBackMap[450].y = 5;
RightBackMap[448].x = 14;
RightBackMap[448].y = 5;
RightBackMap[449].x = 14;
RightBackMap[449].y = 5;
RightBackMap[447].x = 15;
RightBackMap[447].y = 5;
RightBackMap[446].x = 16;
RightBackMap[446].y = 5;
RightBackMap[444].x = 17;
RightBackMap[444].y = 5;
RightBackMap[445].x = 17;
RightBackMap[445].y = 5;
RightBackMap[443].x = 18;
RightBackMap[443].y = 5;
RightBackMap[442].x = 19;
RightBackMap[442].y = 5;
RightBackMap[440].x = 20;
RightBackMap[440].y = 5;
RightBackMap[441].x = 20;
RightBackMap[441].y = 5;
RightBackMap[439].x = 21;
RightBackMap[439].y = 5;
RightBackMap[437].x = 22;
RightBackMap[437].y = 5;
RightBackMap[438].x = 22;
RightBackMap[438].y = 5;
RightBackMap[388].x = 23;
RightBackMap[388].y = 5;
RightBackMap[389].x = 23;
RightBackMap[389].y = 5;
RightBackMap[436].x = 23;
RightBackMap[436].y = 5;
RightBackMap[390].x = 24;
RightBackMap[390].y = 5;
RightBackMap[435].x = 24;
RightBackMap[435].y = 5;
RightBackMap[391].x = 25;
RightBackMap[391].y = 5;
RightBackMap[433].x = 25;
RightBackMap[433].y = 5;
RightBackMap[434].x = 25;
RightBackMap[434].y = 5;
RightBackMap[515].x = 25;
RightBackMap[515].y = 5;
RightBackMap[392].x = 26;
RightBackMap[392].y = 5;
RightBackMap[393].x = 26;
RightBackMap[393].y = 5;
RightBackMap[394].x = 27;
RightBackMap[394].y = 5;
RightBackMap[395].x = 28;
RightBackMap[395].y = 5;
RightBackMap[396].x = 28;
RightBackMap[396].y = 5;
RightBackMap[429].x = 28;
RightBackMap[429].y = 5;
RightBackMap[397].x = 29;
RightBackMap[397].y = 5;
RightBackMap[427].x = 29;
RightBackMap[427].y = 5;
RightBackMap[398].x = 30;
RightBackMap[398].y = 5;
RightBackMap[426].x = 30;
RightBackMap[426].y = 5;
RightBackMap[424].x = 31;
RightBackMap[424].y = 5;
RightBackMap[425].x = 31;
RightBackMap[425].y = 5;
RightBackMap[418].x = 36;
RightBackMap[418].y = 5;
RightBackMap[307].x = 39;
RightBackMap[307].y = 5;
RightBackMap[306].x = 40;
RightBackMap[306].y = 5;
RightBackMap[305].x = 41;
RightBackMap[305].y = 5;
RightBackMap[607].x = 0;
RightBackMap[607].y = 6;
RightBackMap[608].x = 0;
RightBackMap[608].y = 6;
RightBackMap[609].x = 0;
RightBackMap[609].y = 6;
RightBackMap[610].x = 0;
RightBackMap[610].y = 6;
RightBackMap[481].x = 1;
RightBackMap[481].y = 6;
RightBackMap[482].x = 1;
RightBackMap[482].y = 6;
RightBackMap[483].x = 2;
RightBackMap[483].y = 6;
RightBackMap[484].x = 2;
RightBackMap[484].y = 6;
RightBackMap[462].x = 4;
RightBackMap[462].y = 6;
RightBackMap[463].x = 4;
RightBackMap[463].y = 6;
RightBackMap[461].x = 5;
RightBackMap[461].y = 6;
RightBackMap[459].x = 6;
RightBackMap[459].y = 6;
RightBackMap[460].x = 6;
RightBackMap[460].y = 6;
RightBackMap[458].x = 7;
RightBackMap[458].y = 6;
RightBackMap[456].x = 8;
RightBackMap[456].y = 6;
RightBackMap[457].x = 8;
RightBackMap[457].y = 6;
RightBackMap[373].x = 12;
RightBackMap[373].y = 6;
RightBackMap[374].x = 13;
RightBackMap[374].y = 6;
RightBackMap[375].x = 13;
RightBackMap[375].y = 6;
RightBackMap[376].x = 14;
RightBackMap[376].y = 6;
RightBackMap[377].x = 15;
RightBackMap[377].y = 6;
RightBackMap[378].x = 16;
RightBackMap[378].y = 6;
RightBackMap[379].x = 16;
RightBackMap[379].y = 6;
RightBackMap[380].x = 17;
RightBackMap[380].y = 6;
RightBackMap[381].x = 18;
RightBackMap[381].y = 6;
RightBackMap[382].x = 19;
RightBackMap[382].y = 6;
RightBackMap[318].x = 21;
RightBackMap[318].y = 6;
RightBackMap[385].x = 21;
RightBackMap[385].y = 6;
RightBackMap[386].x = 21;
RightBackMap[386].y = 6;
RightBackMap[387].x = 22;
RightBackMap[387].y = 6;
RightBackMap[317].x = 24;
RightBackMap[317].y = 6;
RightBackMap[278].x = 26;
RightBackMap[278].y = 6;
RightBackMap[279].x = 26;
RightBackMap[279].y = 6;
RightBackMap[280].x = 27;
RightBackMap[280].y = 6;
RightBackMap[281].x = 27;
RightBackMap[281].y = 6;
RightBackMap[282].x = 28;
RightBackMap[282].y = 6;
RightBackMap[283].x = 29;
RightBackMap[283].y = 6;
RightBackMap[284].x = 29;
RightBackMap[284].y = 6;
RightBackMap[428].x = 29;
RightBackMap[428].y = 6;
RightBackMap[285].x = 30;
RightBackMap[285].y = 6;
RightBackMap[286].x = 31;
RightBackMap[286].y = 6;
RightBackMap[287].x = 31;
RightBackMap[287].y = 6;
RightBackMap[194].x = 32;
RightBackMap[194].y = 6;
RightBackMap[288].x = 32;
RightBackMap[288].y = 6;
RightBackMap[289].x = 33;
RightBackMap[289].y = 6;
RightBackMap[290].x = 33;
RightBackMap[290].y = 6;
RightBackMap[291].x = 34;
RightBackMap[291].y = 6;
RightBackMap[292].x = 35;
RightBackMap[292].y = 6;
RightBackMap[293].x = 36;
RightBackMap[293].y = 6;
RightBackMap[294].x = 36;
RightBackMap[294].y = 6;
RightBackMap[295].x = 37;
RightBackMap[295].y = 6;
RightBackMap[296].x = 37;
RightBackMap[296].y = 6;
RightBackMap[297].x = 38;
RightBackMap[297].y = 6;
RightBackMap[303].x = 42;
RightBackMap[303].y = 6;
RightBackMap[304].x = 42;
RightBackMap[304].y = 6;
RightBackMap[477].x = 0;
RightBackMap[477].y = 7;
RightBackMap[478].x = 0;
RightBackMap[478].y = 7;
RightBackMap[479].x = 0;
RightBackMap[479].y = 7;
RightBackMap[467].x = 1;
RightBackMap[467].y = 7;
RightBackMap[468].x = 1;
RightBackMap[468].y = 7;
RightBackMap[480].x = 1;
RightBackMap[480].y = 7;
RightBackMap[465].x = 2;
RightBackMap[465].y = 7;
RightBackMap[466].x = 2;
RightBackMap[466].y = 7;
RightBackMap[464].x = 3;
RightBackMap[464].y = 7;
RightBackMap[366].x = 7;
RightBackMap[366].y = 7;
RightBackMap[367].x = 8;
RightBackMap[367].y = 7;
RightBackMap[368].x = 8;
RightBackMap[368].y = 7;
RightBackMap[369].x = 9;
RightBackMap[369].y = 7;
RightBackMap[370].x = 10;
RightBackMap[370].y = 7;
RightBackMap[371].x = 11;
RightBackMap[371].y = 7;
RightBackMap[372].x = 11;
RightBackMap[372].y = 7;
RightBackMap[327].x = 15;
RightBackMap[327].y = 7;
RightBackMap[325].x = 16;
RightBackMap[325].y = 7;
RightBackMap[326].x = 16;
RightBackMap[326].y = 7;
RightBackMap[324].x = 17;
RightBackMap[324].y = 7;
RightBackMap[322].x = 18;
RightBackMap[322].y = 7;
RightBackMap[323].x = 18;
RightBackMap[323].y = 7;
RightBackMap[321].x = 19;
RightBackMap[321].y = 7;
RightBackMap[270].x = 20;
RightBackMap[270].y = 7;
RightBackMap[320].x = 20;
RightBackMap[320].y = 7;
RightBackMap[383].x = 20;
RightBackMap[383].y = 7;
RightBackMap[271].x = 21;
RightBackMap[271].y = 7;
RightBackMap[272].x = 21;
RightBackMap[272].y = 7;
RightBackMap[319].x = 21;
RightBackMap[319].y = 7;
RightBackMap[384].x = 21;
RightBackMap[384].y = 7;
RightBackMap[273].x = 22;
RightBackMap[273].y = 7;
RightBackMap[274].x = 23;
RightBackMap[274].y = 7;
RightBackMap[275].x = 24;
RightBackMap[275].y = 7;
RightBackMap[276].x = 24;
RightBackMap[276].y = 7;
RightBackMap[204].x = 25;
RightBackMap[204].y = 7;
RightBackMap[277].x = 25;
RightBackMap[277].y = 7;
RightBackMap[198].x = 29;
RightBackMap[198].y = 7;
RightBackMap[196].x = 30;
RightBackMap[196].y = 7;
RightBackMap[197].x = 30;
RightBackMap[197].y = 7;
RightBackMap[195].x = 31;
RightBackMap[195].y = 7;
RightBackMap[192].x = 32;
RightBackMap[192].y = 7;
RightBackMap[193].x = 32;
RightBackMap[193].y = 7;
RightBackMap[191].x = 33;
RightBackMap[191].y = 7;
RightBackMap[190].x = 34;
RightBackMap[190].y = 7;
RightBackMap[188].x = 35;
RightBackMap[188].y = 7;
RightBackMap[189].x = 35;
RightBackMap[189].y = 7;
RightBackMap[187].x = 36;
RightBackMap[187].y = 7;
RightBackMap[186].x = 37;
RightBackMap[186].y = 7;
RightBackMap[298].x = 39;
RightBackMap[298].y = 7;
RightBackMap[299].x = 39;
RightBackMap[299].y = 7;
RightBackMap[300].x = 40;
RightBackMap[300].y = 7;
RightBackMap[301].x = 41;
RightBackMap[301].y = 7;
RightBackMap[302].x = 41;
RightBackMap[302].y = 7;
RightBackMap[470].x = 0;
RightBackMap[470].y = 8;
RightBackMap[471].x = 0;
RightBackMap[471].y = 8;
RightBackMap[472].x = 0;
RightBackMap[472].y = 8;
RightBackMap[475].x = 0;
RightBackMap[475].y = 8;
RightBackMap[476].x = 0;
RightBackMap[476].y = 8;
RightBackMap[469].x = 1;
RightBackMap[469].y = 8;
RightBackMap[359].x = 2;
RightBackMap[359].y = 8;
RightBackMap[360].x = 3;
RightBackMap[360].y = 8;
RightBackMap[361].x = 3;
RightBackMap[361].y = 8;
RightBackMap[362].x = 4;
RightBackMap[362].y = 8;
RightBackMap[363].x = 5;
RightBackMap[363].y = 8;
RightBackMap[364].x = 6;
RightBackMap[364].y = 8;
RightBackMap[365].x = 6;
RightBackMap[365].y = 8;
RightBackMap[336].x = 8;
RightBackMap[336].y = 8;
RightBackMap[335].x = 9;
RightBackMap[335].y = 8;
RightBackMap[333].x = 10;
RightBackMap[333].y = 8;
RightBackMap[334].x = 10;
RightBackMap[334].y = 8;
RightBackMap[332].x = 11;
RightBackMap[332].y = 8;
RightBackMap[331].x = 12;
RightBackMap[331].y = 8;
RightBackMap[329].x = 13;
RightBackMap[329].y = 8;
RightBackMap[330].x = 13;
RightBackMap[330].y = 8;
RightBackMap[328].x = 14;
RightBackMap[328].y = 8;
RightBackMap[267].x = 18;
RightBackMap[267].y = 8;
RightBackMap[268].x = 19;
RightBackMap[268].y = 8;
RightBackMap[269].x = 19;
RightBackMap[269].y = 8;
RightBackMap[205].x = 24;
RightBackMap[205].y = 8;
RightBackMap[202].x = 26;
RightBackMap[202].y = 8;
RightBackMap[203].x = 26;
RightBackMap[203].y = 8;
RightBackMap[201].x = 27;
RightBackMap[201].y = 8;
RightBackMap[199].x = 28;
RightBackMap[199].y = 8;
RightBackMap[200].x = 28;
RightBackMap[200].y = 8;
RightBackMap[167].x = 34;
RightBackMap[167].y = 8;
RightBackMap[168].x = 34;
RightBackMap[168].y = 8;
RightBackMap[169].x = 35;
RightBackMap[169].y = 8;
RightBackMap[170].x = 36;
RightBackMap[170].y = 8;
RightBackMap[185].x = 37;
RightBackMap[185].y = 8;
RightBackMap[183].x = 38;
RightBackMap[183].y = 8;
RightBackMap[184].x = 38;
RightBackMap[184].y = 8;
RightBackMap[182].x = 39;
RightBackMap[182].y = 8;
RightBackMap[180].x = 40;
RightBackMap[180].y = 8;
RightBackMap[181].x = 40;
RightBackMap[181].y = 8;
RightBackMap[473].x = 0;
RightBackMap[473].y = 9;
RightBackMap[355].x = 1;
RightBackMap[355].y = 9;
RightBackMap[356].x = 1;
RightBackMap[356].y = 9;
RightBackMap[357].x = 1;
RightBackMap[357].y = 9;
RightBackMap[358].x = 2;
RightBackMap[358].y = 9;
RightBackMap[343].x = 3;
RightBackMap[343].y = 9;
RightBackMap[342].x = 4;
RightBackMap[342].y = 9;
RightBackMap[340].x = 5;
RightBackMap[340].y = 9;
RightBackMap[341].x = 5;
RightBackMap[341].y = 9;
RightBackMap[339].x = 6;
RightBackMap[339].y = 9;
RightBackMap[337].x = 7;
RightBackMap[337].y = 9;
RightBackMap[338].x = 7;
RightBackMap[338].y = 9;
RightBackMap[261].x = 14;
RightBackMap[261].y = 9;
RightBackMap[262].x = 14;
RightBackMap[262].y = 9;
RightBackMap[263].x = 15;
RightBackMap[263].y = 9;
RightBackMap[264].x = 16;
RightBackMap[264].y = 9;
RightBackMap[265].x = 17;
RightBackMap[265].y = 9;
RightBackMap[266].x = 17;
RightBackMap[266].y = 9;
RightBackMap[211].x = 20;
RightBackMap[211].y = 9;
RightBackMap[210].x = 21;
RightBackMap[210].y = 9;
RightBackMap[208].x = 22;
RightBackMap[208].y = 9;
RightBackMap[209].x = 22;
RightBackMap[209].y = 9;
RightBackMap[207].x = 23;
RightBackMap[207].y = 9;
RightBackMap[206].x = 24;
RightBackMap[206].y = 9;
RightBackMap[156].x = 27;
RightBackMap[156].y = 9;
RightBackMap[157].x = 28;
RightBackMap[157].y = 9;
RightBackMap[158].x = 28;
RightBackMap[158].y = 9;
RightBackMap[159].x = 29;
RightBackMap[159].y = 9;
RightBackMap[160].x = 29;
RightBackMap[160].y = 9;
RightBackMap[161].x = 30;
RightBackMap[161].y = 9;
RightBackMap[162].x = 31;
RightBackMap[162].y = 9;
RightBackMap[163].x = 31;
RightBackMap[163].y = 9;
RightBackMap[164].x = 32;
RightBackMap[164].y = 9;
RightBackMap[165].x = 32;
RightBackMap[165].y = 9;
RightBackMap[166].x = 33;
RightBackMap[166].y = 9;
RightBackMap[90].x = 34;
RightBackMap[90].y = 9;
RightBackMap[171].x = 36;
RightBackMap[171].y = 9;
RightBackMap[172].x = 37;
RightBackMap[172].y = 9;
RightBackMap[173].x = 38;
RightBackMap[173].y = 9;
RightBackMap[174].x = 38;
RightBackMap[174].y = 9;
RightBackMap[175].x = 39;
RightBackMap[175].y = 9;
RightBackMap[179].x = 41;
RightBackMap[179].y = 9;
RightBackMap[352].x = 0;
RightBackMap[352].y = 10;
RightBackMap[353].x = 0;
RightBackMap[353].y = 10;
RightBackMap[347].x = 1;
RightBackMap[347].y = 10;
RightBackMap[354].x = 1;
RightBackMap[354].y = 10;
RightBackMap[345].x = 2;
RightBackMap[345].y = 10;
RightBackMap[346].x = 2;
RightBackMap[346].y = 10;
RightBackMap[344].x = 3;
RightBackMap[344].y = 10;
RightBackMap[255].x = 9;
RightBackMap[255].y = 10;
RightBackMap[256].x = 10;
RightBackMap[256].y = 10;
RightBackMap[257].x = 11;
RightBackMap[257].y = 10;
RightBackMap[258].x = 11;
RightBackMap[258].y = 10;
RightBackMap[259].x = 12;
RightBackMap[259].y = 10;
RightBackMap[260].x = 13;
RightBackMap[260].y = 10;
RightBackMap[218].x = 15;
RightBackMap[218].y = 10;
RightBackMap[217].x = 16;
RightBackMap[217].y = 10;
RightBackMap[215].x = 17;
RightBackMap[215].y = 10;
RightBackMap[216].x = 17;
RightBackMap[216].y = 10;
RightBackMap[214].x = 18;
RightBackMap[214].y = 10;
RightBackMap[213].x = 19;
RightBackMap[213].y = 10;
RightBackMap[212].x = 20;
RightBackMap[212].y = 10;
RightBackMap[148].x = 21;
RightBackMap[148].y = 10;
RightBackMap[149].x = 22;
RightBackMap[149].y = 10;
RightBackMap[150].x = 23;
RightBackMap[150].y = 10;
RightBackMap[151].x = 23;
RightBackMap[151].y = 10;
RightBackMap[152].x = 24;
RightBackMap[152].y = 10;
RightBackMap[153].x = 25;
RightBackMap[153].y = 10;
RightBackMap[154].x = 26;
RightBackMap[154].y = 10;
RightBackMap[155].x = 26;
RightBackMap[155].y = 10;
RightBackMap[98].x = 29;
RightBackMap[98].y = 10;
RightBackMap[99].x = 29;
RightBackMap[99].y = 10;
RightBackMap[97].x = 30;
RightBackMap[97].y = 10;
RightBackMap[95].x = 31;
RightBackMap[95].y = 10;
RightBackMap[96].x = 31;
RightBackMap[96].y = 10;
RightBackMap[93].x = 32;
RightBackMap[93].y = 10;
RightBackMap[94].x = 32;
RightBackMap[94].y = 10;
RightBackMap[92].x = 33;
RightBackMap[92].y = 10;
RightBackMap[91].x = 34;
RightBackMap[91].y = 10;
RightBackMap[89].x = 35;
RightBackMap[89].y = 10;
RightBackMap[87].x = 36;
RightBackMap[87].y = 10;
RightBackMap[88].x = 36;
RightBackMap[88].y = 10;
RightBackMap[85].x = 37;
RightBackMap[85].y = 10;
RightBackMap[86].x = 37;
RightBackMap[86].y = 10;
RightBackMap[84].x = 38;
RightBackMap[84].y = 10;
RightBackMap[83].x = 39;
RightBackMap[83].y = 10;
RightBackMap[176].x = 39;
RightBackMap[176].y = 10;
RightBackMap[177].x = 40;
RightBackMap[177].y = 10;
RightBackMap[178].x = 41;
RightBackMap[178].y = 10;
RightBackMap[350].x = 0;
RightBackMap[350].y = 11;
RightBackMap[351].x = 0;
RightBackMap[351].y = 11;
RightBackMap[348].x = 1;
RightBackMap[348].y = 11;
RightBackMap[349].x = 1;
RightBackMap[349].y = 11;
RightBackMap[251].x = 6;
RightBackMap[251].y = 11;
RightBackMap[252].x = 7;
RightBackMap[252].y = 11;
RightBackMap[253].x = 8;
RightBackMap[253].y = 11;
RightBackMap[254].x = 8;
RightBackMap[254].y = 11;
RightBackMap[222].x = 12;
RightBackMap[222].y = 11;
RightBackMap[223].x = 12;
RightBackMap[223].y = 11;
RightBackMap[221].x = 13;
RightBackMap[221].y = 11;
RightBackMap[220].x = 14;
RightBackMap[220].y = 11;
RightBackMap[219].x = 15;
RightBackMap[219].y = 11;
RightBackMap[142].x = 17;
RightBackMap[142].y = 11;
RightBackMap[143].x = 18;
RightBackMap[143].y = 11;
RightBackMap[144].x = 19;
RightBackMap[144].y = 11;
RightBackMap[145].x = 19;
RightBackMap[145].y = 11;
RightBackMap[146].x = 20;
RightBackMap[146].y = 11;
RightBackMap[147].x = 21;
RightBackMap[147].y = 11;
RightBackMap[106].x = 24;
RightBackMap[106].y = 11;
RightBackMap[105].x = 25;
RightBackMap[105].y = 11;
RightBackMap[103].x = 26;
RightBackMap[103].y = 11;
RightBackMap[104].x = 26;
RightBackMap[104].y = 11;
RightBackMap[101].x = 27;
RightBackMap[101].y = 11;
RightBackMap[102].x = 27;
RightBackMap[102].y = 11;
RightBackMap[100].x = 28;
RightBackMap[100].y = 11;
RightBackMap[60].x = 30;
RightBackMap[60].y = 11;
RightBackMap[61].x = 31;
RightBackMap[61].y = 11;
RightBackMap[62].x = 31;
RightBackMap[62].y = 11;
RightBackMap[63].x = 32;
RightBackMap[63].y = 11;
RightBackMap[64].x = 32;
RightBackMap[64].y = 11;
RightBackMap[65].x = 33;
RightBackMap[65].y = 11;
RightBackMap[66].x = 34;
RightBackMap[66].y = 11;
RightBackMap[67].x = 35;
RightBackMap[67].y = 11;
RightBackMap[68].x = 35;
RightBackMap[68].y = 11;
RightBackMap[69].x = 35;
RightBackMap[69].y = 11;
RightBackMap[70].x = 36;
RightBackMap[70].y = 11;
RightBackMap[82].x = 39;
RightBackMap[82].y = 11;
RightBackMap[80].x = 40;
RightBackMap[80].y = 11;
RightBackMap[81].x = 40;
RightBackMap[81].y = 11;
RightBackMap[0].x = 41;
RightBackMap[0].y = 11;
RightBackMap[245].x = 2;
RightBackMap[245].y = 12;
RightBackMap[246].x = 3;
RightBackMap[246].y = 12;
RightBackMap[247].x = 4;
RightBackMap[247].y = 12;
RightBackMap[248].x = 4;
RightBackMap[248].y = 12;
RightBackMap[249].x = 5;
RightBackMap[249].y = 12;
RightBackMap[250].x = 6;
RightBackMap[250].y = 12;
RightBackMap[229].x = 7;
RightBackMap[229].y = 12;
RightBackMap[228].x = 8;
RightBackMap[228].y = 12;
RightBackMap[226].x = 9;
RightBackMap[226].y = 12;
RightBackMap[227].x = 9;
RightBackMap[227].y = 12;
RightBackMap[225].x = 10;
RightBackMap[225].y = 12;
RightBackMap[224].x = 11;
RightBackMap[224].y = 12;
RightBackMap[136].x = 13;
RightBackMap[136].y = 12;
RightBackMap[137].x = 14;
RightBackMap[137].y = 12;
RightBackMap[138].x = 14;
RightBackMap[138].y = 12;
RightBackMap[139].x = 15;
RightBackMap[139].y = 12;
RightBackMap[140].x = 16;
RightBackMap[140].y = 12;
RightBackMap[141].x = 16;
RightBackMap[141].y = 12;
RightBackMap[113].x = 19;
RightBackMap[113].y = 12;
RightBackMap[112].x = 20;
RightBackMap[112].y = 12;
RightBackMap[110].x = 21;
RightBackMap[110].y = 12;
RightBackMap[111].x = 21;
RightBackMap[111].y = 12;
RightBackMap[109].x = 22;
RightBackMap[109].y = 12;
RightBackMap[107].x = 23;
RightBackMap[107].y = 12;
RightBackMap[108].x = 23;
RightBackMap[108].y = 12;
RightBackMap[54].x = 26;
RightBackMap[54].y = 12;
RightBackMap[55].x = 27;
RightBackMap[55].y = 12;
RightBackMap[56].x = 27;
RightBackMap[56].y = 12;
RightBackMap[57].x = 28;
RightBackMap[57].y = 12;
RightBackMap[58].x = 29;
RightBackMap[58].y = 12;
RightBackMap[59].x = 29;
RightBackMap[59].y = 12;
RightBackMap[20].x = 30;
RightBackMap[20].y = 12;
RightBackMap[19].x = 31;
RightBackMap[19].y = 12;
RightBackMap[18].x = 32;
RightBackMap[18].y = 12;
RightBackMap[17].x = 33;
RightBackMap[17].y = 12;
RightBackMap[13].x = 34;
RightBackMap[13].y = 12;
RightBackMap[14].x = 34;
RightBackMap[14].y = 12;
RightBackMap[15].x = 34;
RightBackMap[15].y = 12;
RightBackMap[16].x = 34;
RightBackMap[16].y = 12;
RightBackMap[11].x = 35;
RightBackMap[11].y = 12;
RightBackMap[12].x = 35;
RightBackMap[12].y = 12;
RightBackMap[9].x = 36;
RightBackMap[9].y = 12;
RightBackMap[10].x = 36;
RightBackMap[10].y = 12;
RightBackMap[7].x = 37;
RightBackMap[7].y = 12;
RightBackMap[8].x = 37;
RightBackMap[8].y = 12;
RightBackMap[71].x = 38;
RightBackMap[71].y = 12;
RightBackMap[72].x = 38;
RightBackMap[72].y = 12;
RightBackMap[73].x = 38;
RightBackMap[73].y = 12;
RightBackMap[74].x = 38;
RightBackMap[74].y = 12;
RightBackMap[75].x = 39;
RightBackMap[75].y = 12;
RightBackMap[76].x = 40;
RightBackMap[76].y = 12;
RightBackMap[77].x = 40;
RightBackMap[77].y = 12;
RightBackMap[79].x = 41;
RightBackMap[79].y = 12;
RightBackMap[240].x = 0;
RightBackMap[240].y = 13;
RightBackMap[241].x = 0;
RightBackMap[241].y = 13;
RightBackMap[242].x = 1;
RightBackMap[242].y = 13;
RightBackMap[243].x = 1;
RightBackMap[243].y = 13;
RightBackMap[244].x = 2;
RightBackMap[244].y = 13;
RightBackMap[235].x = 3;
RightBackMap[235].y = 13;
RightBackMap[234].x = 4;
RightBackMap[234].y = 13;
RightBackMap[232].x = 5;
RightBackMap[232].y = 13;
RightBackMap[233].x = 5;
RightBackMap[233].y = 13;
RightBackMap[231].x = 6;
RightBackMap[231].y = 13;
RightBackMap[230].x = 7;
RightBackMap[230].y = 13;
RightBackMap[132].x = 10;
RightBackMap[132].y = 13;
RightBackMap[133].x = 11;
RightBackMap[133].y = 13;
RightBackMap[134].x = 11;
RightBackMap[134].y = 13;
RightBackMap[135].x = 12;
RightBackMap[135].y = 13;
RightBackMap[118].x = 15;
RightBackMap[118].y = 13;
RightBackMap[117].x = 16;
RightBackMap[117].y = 13;
RightBackMap[116].x = 17;
RightBackMap[116].y = 13;
RightBackMap[115].x = 18;
RightBackMap[115].y = 13;
RightBackMap[114].x = 19;
RightBackMap[114].y = 13;
RightBackMap[45].x = 20;
RightBackMap[45].y = 13;
RightBackMap[46].x = 21;
RightBackMap[46].y = 13;
RightBackMap[47].x = 21;
RightBackMap[47].y = 13;
RightBackMap[48].x = 22;
RightBackMap[48].y = 13;
RightBackMap[49].x = 23;
RightBackMap[49].y = 13;
RightBackMap[50].x = 23;
RightBackMap[50].y = 13;
RightBackMap[51].x = 24;
RightBackMap[51].y = 13;
RightBackMap[52].x = 25;
RightBackMap[52].y = 13;
RightBackMap[53].x = 25;
RightBackMap[53].y = 13;
RightBackMap[25].x = 27;
RightBackMap[25].y = 13;
RightBackMap[23].x = 28;
RightBackMap[23].y = 13;
RightBackMap[24].x = 28;
RightBackMap[24].y = 13;
RightBackMap[22].x = 29;
RightBackMap[22].y = 13;
RightBackMap[21].x = 30;
RightBackMap[21].y = 13;
RightBackMap[6].x = 38;
RightBackMap[6].y = 13;
RightBackMap[4].x = 39;
RightBackMap[4].y = 13;
RightBackMap[5].x = 39;
RightBackMap[5].y = 13;
RightBackMap[3].x = 40;
RightBackMap[3].y = 13;
RightBackMap[78].x = 41;
RightBackMap[78].y = 13;
RightBackMap[239].x = 1;
RightBackMap[239].y = 14;
RightBackMap[237].x = 2;
RightBackMap[237].y = 14;
RightBackMap[238].x = 2;
RightBackMap[238].y = 14;
RightBackMap[236].x = 3;
RightBackMap[236].y = 14;
RightBackMap[126].x = 6;
RightBackMap[126].y = 14;
RightBackMap[127].x = 6;
RightBackMap[127].y = 14;
RightBackMap[128].x = 7;
RightBackMap[128].y = 14;
RightBackMap[129].x = 8;
RightBackMap[129].y = 14;
RightBackMap[130].x = 9;
RightBackMap[130].y = 14;
RightBackMap[131].x = 9;
RightBackMap[131].y = 14;
RightBackMap[119].x = 1;
RightBackMap[119].y = 14;
RightBackMap[43].x = 18;
RightBackMap[43].y = 14;
RightBackMap[36].x = 19;
RightBackMap[36].y = 14;
RightBackMap[37].x = 19;
RightBackMap[37].y = 14;
RightBackMap[38].x = 19;
RightBackMap[38].y = 14;
RightBackMap[39].x = 19;
RightBackMap[39].y = 14;
RightBackMap[44].x = 19;
RightBackMap[44].y = 14;
RightBackMap[35].x = 20;
RightBackMap[35].y = 14;
RightBackMap[34].x = 21;
RightBackMap[34].y = 14;
RightBackMap[32].x = 22;
RightBackMap[32].y = 14;
RightBackMap[33].x = 22;
RightBackMap[33].y = 14;
RightBackMap[31].x = 23;
RightBackMap[31].y = 14;
RightBackMap[30].x = 24;
RightBackMap[30].y = 14;
RightBackMap[28].x = 25;
RightBackMap[28].y = 14;
RightBackMap[29].x = 25;
RightBackMap[29].y = 14;
RightBackMap[27].x = 26;
RightBackMap[27].y = 14;
RightBackMap[26].x = 27;
RightBackMap[26].y = 14;
RightBackMap[2].x = 40;
RightBackMap[2].y = 14;
RightBackMap[1].x = 41;
RightBackMap[1].y = 14;
RightBackMap[122].x = 3;
RightBackMap[122].y = 15;
RightBackMap[123].x = 4;
RightBackMap[123].y = 15;
RightBackMap[124].x = 4;
RightBackMap[124].y = 15;
RightBackMap[125].x = 5;
RightBackMap[125].y = 15;
RightBackMap[121].x = 2;
RightBackMap[121].y = 15;
RightBackMap[120].x = 2;
RightBackMap[120].y = 15;
RightBackMap[41].x = 17;
RightBackMap[41].y = 15;
RightBackMap[40].x = 18;
RightBackMap[40].y = 15;
}

