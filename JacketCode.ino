/*  OctoWS2811 BasicTest.ino - Basic RGB LED Test
    http://www.pjrc.com/teensy/td_libs_OctoWS2811.html
    Copyright (c) 2013 Paul Stoffregen, PJRC.COM, LLC

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.

  Required Connections
  --------------------
    pin 2:  LED Strip #1    OctoWS2811 drives 8 LED Strips.
    pin 14: LED strip #2    All 8 are the same length.
    pin 7:  LED strip #3
    pin 8:  LED strip #4    A 100 ohm resistor should used
    pin 6:  LED strip #5    between each Teensy pin and the
    pin 20: LED strip #6    wire to the LED strip, to minimize
    pin 21: LED strip #7    high frequency ringining & noise.
    pin 5:  LED strip #8
    pin 15 & 16 - Connect together, but do not use
    pin 4 - Do not use
    pin 3 - Do not use as PWM.  Normal use is ok.

  This test is useful for checking if your LED strips work, and which
  color config (WS2811_RGB, WS2811_GRB, etc) they require.
*/

#include <OctoWS2811.h>
#include "MatrixDraw.h"
#include "LeftArmBackMap.h"
#include "LeftArmFrontPartTwoMap.h"
#include "LeftArmFrontPtOneMap.h"
#include "LeftBackMap.h"
#include "LeftChestMap.h"
#include "RightArmBackMap.h"
#include "RightArmFrontPartOneMap.h"
#include "RightArmFrontPartTwoMap.h"
#include "RightBackMap.h"
#include "RightChestMap.h"

const int ledsPerStrip = 1280;

DMAMEM int displayMemory[ledsPerStrip*6];
int drawingMemory[ledsPerStrip*6];

const int config = WS2811_GRB | WS2811_800kHz;

OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);

MatrixDraw LeftArmBackCanvas            (xSizeLeftArmBack, ySizeLeftArmBack);
MatrixDraw LeftArmFrontPartTwoCanvas    (xSizeLeftArmPartTwo, ySizeLeftArmPartTwo);
MatrixDraw LeftArmFrontPartOneCanvas    (xSizeLeftArmFrontPartOne, ySizeLeftArmFrontPartOne);
MatrixDraw LeftBackCanvas               (xSizeLeftArmBack, ySizeLeftArmBack);
MatrixDraw LeftChestCanvas              (xSizeLeftChest, ySizeLeftChest);
MatrixDraw RightArmBackCanvas           (xSizeRightArmBack, ySizeRightArmBack);
MatrixDraw RightArmFrontPartOneCanvas   (xSizeRightArmPartOne, ySizeRightArmPartOne);
MatrixDraw RightArmFrontPartTwoCanvas   (xSizeRightArmPartTwo, ySizeRightArmPartTwo);
MatrixDraw RightBackCanvas              (xSizeRightBack, ySizeRightBack);
MatrixDraw RightChestCanvas             (xSizeRightChest, ySizeRightChest);

void InitializeMatrices()
{
  LeftArmBackCanvas.ClearMatrix();      
  LeftArmFrontPartTwoCanvas.ClearMatrix();  
  LeftArmFrontPartOneCanvas.ClearMatrix();   
  LeftBackCanvas.ClearMatrix();              
  LeftChestCanvas.ClearMatrix();             
  RightArmBackCanvas.ClearMatrix();          
  RightArmFrontPartOneCanvas.ClearMatrix();  
  RightArmFrontPartTwoCanvas.ClearMatrix();  
  RightBackCanvas.ClearMatrix();             
  RightChestCanvas.ClearMatrix();            
}


struct XYPos{
  int x;
  int y;
};

#define RED    0xFF0000
#define GREEN  0x00AA00
#define BLUE   0x0000FF
#define YELLOW 0xFFFF00
#define PINK   0xFF1088
#define ORANGE 0xE05800
#define WHITE  0xFFFFFF

int xSize = 185;
int ySize = 109;
int minLED = 4094;
int maxLED = 4680;
XYPos LEDMap [586];
MatrixDraw OurCanvas(xSize, ySize);

void DrawMatrix()
{
  for(int i = 4096; i < 4680; i++)
  {
    XYPos curPos = LEDMap[i - minLED];
    int value = OurCanvas.GetValueAt(curPos.x, curPos.y);
  }
}

void InitializeAllMaps()
{
  InitializeLeftArmBackMap();
  InitializeLeftArmFrontPartTwoMap();
  InitializeLeftArmFrontPartOneMap();
  InitializeLeftBackMap();
  InitializeLeftChestMap();
  InitializeRightArmMap();
  InitializeRightArmPartOneMap();
  InitializeRightArmPartTwoMap();
  InitializeRightBackMap();
  InitializeRightChestMap();
}

void setup() {

  InitializeAllMaps();
  InitializeMatrices();

  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  leds.begin();
  leds.show();

  OurCanvas.ClearMatrix();

  lightAll(GREEN);

}


// Less intense...
/*
#define RED    0x160000
#define GREEN  0x001600
#define BLUE   0x000016
#define YELLOW 0x101400
#define PINK   0x120009
#define ORANGE 0x100400
#define WHITE  0x101010
*/


void loop() {
  int microsec = 0;  // change them all in 2 seconds

  // uncomment for voltage controlled speed
  // millisec = analogRead(A9) / 40;
  //colorWipe(GREEN, microsec);



  if(Serial.available() > 2)
  {
      for(int i = 0; i < leds.numPixels(); i++)
      {
          leds.setPixel(i, 0x000000);
      }

      int led2Light = Serial.parseInt();
      Serial.println("In Here");
      Serial.println(led2Light);

      leds.setPixel(led2Light, GREEN);
      leds.show();
  }

  delay(5); 


}

void lightAll(int color)
{
  for(int i = 0; i < leds.numPixels(); i++)
  {
    leds.setPixel(i, color);
  }

  leds.show();
}

void colorWipe(int color, int wait)
{
  for (int i=0; i < leds.numPixels(); i++) {
    leds.setPixel(i, color);
    leds.show();
    delayMicroseconds(wait);
  }
}
//int xSize = 185;
//int ySize = 109;
//int minLED = 4094;
//int maxLED = 4680;
//XYPos LEDMap [586];

void MakeMap()
{
  LEDMap[404].x = 149;
LEDMap[404].y = 0;
LEDMap[403].x = 147;
LEDMap[403].y = 2;
LEDMap[402].x = 145;
LEDMap[402].y = 3;
LEDMap[401].x = 143;
LEDMap[401].y = 4;
LEDMap[400].x = 142;
LEDMap[400].y = 5;
LEDMap[264].x = 148;
LEDMap[264].y = 5;
LEDMap[263].x = 149;
LEDMap[263].y = 5;
LEDMap[262].x = 152;
LEDMap[262].y = 5;
LEDMap[399].x = 140;
LEDMap[399].y = 6;
LEDMap[406].x = 130;
LEDMap[406].y = 7;
LEDMap[398].x = 139;
LEDMap[398].y = 7;
LEDMap[266].x = 144;
LEDMap[266].y = 7;
LEDMap[265].x = 146;
LEDMap[265].y = 7;
LEDMap[260].x = 154;
LEDMap[260].y = 7;
LEDMap[261].x = 155;
LEDMap[261].y = 7;
LEDMap[518].x = 109;
LEDMap[518].y = 8;
LEDMap[397].x = 137;
LEDMap[397].y = 8;
LEDMap[407].x = 123;
LEDMap[407].y = 9;
LEDMap[396].x = 135;
LEDMap[396].y = 9;
LEDMap[267].x = 142;
LEDMap[267].y = 9;
LEDMap[258].x = 150;
LEDMap[258].y = 9;
LEDMap[259].x = 152;
LEDMap[259].y = 9;
LEDMap[408].x = 121;
LEDMap[408].y = 10;
LEDMap[393].x = 129;
LEDMap[393].y = 10;
LEDMap[395].x = 132;
LEDMap[395].y = 10;
LEDMap[268].x = 141;
LEDMap[268].y = 10;
LEDMap[257].x = 148;
LEDMap[257].y = 10;
LEDMap[517].x = 110;
LEDMap[517].y = 11;
LEDMap[411].x = 115;
LEDMap[411].y = 11;
LEDMap[409].x = 120;
LEDMap[409].y = 11;
LEDMap[391].x = 126;
LEDMap[391].y = 11;
LEDMap[392].x = 128;
LEDMap[392].y = 11;
LEDMap[394].x = 131;
LEDMap[394].y = 11;
LEDMap[270].x = 137;
LEDMap[270].y = 11;
LEDMap[269].x = 139;
LEDMap[269].y = 11;
LEDMap[256].x = 146;
LEDMap[256].y = 11;
LEDMap[515].x = 106;
LEDMap[515].y = 12;
LEDMap[516].x = 108;
LEDMap[516].y = 12;
LEDMap[410].x = 118;
LEDMap[410].y = 12;
LEDMap[271].x = 134;
LEDMap[271].y = 12;
LEDMap[255].x = 145;
LEDMap[255].y = 12;
LEDMap[509].x = 96;
LEDMap[509].y = 13;
LEDMap[519].x = 96;
LEDMap[519].y = 13;
LEDMap[514].x = 104;
LEDMap[514].y = 13;
LEDMap[413].x = 112;
LEDMap[413].y = 13;
LEDMap[412].x = 113;
LEDMap[412].y = 13;
LEDMap[390].x = 124;
LEDMap[390].y = 13;
LEDMap[272].x = 132;
LEDMap[272].y = 13;
LEDMap[254].x = 143;
LEDMap[254].y = 13;
LEDMap[414].x = 110;
LEDMap[414].y = 14;
LEDMap[388].x = 121;
LEDMap[388].y = 14;
LEDMap[389].x = 122;
LEDMap[389].y = 14;
LEDMap[273].x = 131;
LEDMap[273].y = 14;
LEDMap[253].x = 141;
LEDMap[253].y = 14;
LEDMap[126].x = 150;
LEDMap[126].y = 14;
LEDMap[125].x = 152;
LEDMap[125].y = 14;
LEDMap[124].x = 154;
LEDMap[124].y = 14;
LEDMap[520].x = 91;
LEDMap[520].y = 15;
LEDMap[513].x = 103;
LEDMap[513].y = 15;
LEDMap[415].x = 108;
LEDMap[415].y = 15;
LEDMap[387].x = 119;
LEDMap[387].y = 15;
LEDMap[275].x = 128;
LEDMap[275].y = 15;
LEDMap[274].x = 130;
LEDMap[274].y = 15;
LEDMap[251].x = 137;
LEDMap[251].y = 15;
LEDMap[252].x = 139;
LEDMap[252].y = 15;
LEDMap[127].x = 148;
LEDMap[127].y = 15;
LEDMap[521].x = 90;
LEDMap[521].y = 16;
LEDMap[510].x = 98;
LEDMap[510].y = 16;
LEDMap[511].x = 99;
LEDMap[511].y = 16;
LEDMap[512].x = 101;
LEDMap[512].y = 16;
LEDMap[417].x = 104;
LEDMap[417].y = 16;
LEDMap[416].x = 106;
LEDMap[416].y = 16;
LEDMap[386].x = 117;
LEDMap[386].y = 16;
LEDMap[276].x = 126;
LEDMap[276].y = 16;
LEDMap[250].x = 135;
LEDMap[250].y = 16;
LEDMap[128].x = 146;
LEDMap[128].y = 16;
LEDMap[522].x = 88;
LEDMap[522].y = 17;
LEDMap[418].x = 103;
LEDMap[418].y = 17;
LEDMap[384].x = 113;
LEDMap[384].y = 17;
LEDMap[385].x = 115;
LEDMap[385].y = 17;
LEDMap[278].x = 123;
LEDMap[278].y = 17;
LEDMap[277].x = 124;
LEDMap[277].y = 17;
LEDMap[249].x = 133;
LEDMap[249].y = 17;
LEDMap[129].x = 144;
LEDMap[129].y = 17;
LEDMap[523].x = 86;
LEDMap[523].y = 18;
LEDMap[508].x = 94;
LEDMap[508].y = 18;
LEDMap[419].x = 101;
LEDMap[419].y = 18;
LEDMap[383].x = 111;
LEDMap[383].y = 18;
LEDMap[279].x = 121;
LEDMap[279].y = 18;
LEDMap[248].x = 132;
LEDMap[248].y = 18;
LEDMap[131].x = 141;
LEDMap[131].y = 18;
LEDMap[130].x = 142;
LEDMap[130].y = 18;
LEDMap[122].x = 150;
LEDMap[122].y = 18;
LEDMap[123].x = 152;
LEDMap[123].y = 18;
LEDMap[524].x = 84;
LEDMap[524].y = 19;
LEDMap[506].x = 90;
LEDMap[506].y = 19;
LEDMap[507].x = 92;
LEDMap[507].y = 19;
LEDMap[420].x = 99;
LEDMap[420].y = 19;
LEDMap[382].x = 109;
LEDMap[382].y = 19;
LEDMap[280].x = 119;
LEDMap[280].y = 19;
LEDMap[247].x = 130;
LEDMap[247].y = 19;
LEDMap[132].x = 139;
LEDMap[132].y = 19;
LEDMap[121].x = 149;
LEDMap[121].y = 19;
LEDMap[525].x = 82;
LEDMap[525].y = 20;
LEDMap[504].x = 86;
LEDMap[504].y = 20;
LEDMap[505].x = 88;
LEDMap[505].y = 20;
LEDMap[421].x = 97;
LEDMap[421].y = 20;
LEDMap[381].x = 107;
LEDMap[381].y = 20;
LEDMap[281].x = 117;
LEDMap[281].y = 20;
LEDMap[245].x = 126;
LEDMap[245].y = 20;
LEDMap[246].x = 128;
LEDMap[246].y = 20;
LEDMap[133].x = 137;
LEDMap[133].y = 20;
LEDMap[120].x = 146;
LEDMap[120].y = 20;
LEDMap[527].x = 79;
LEDMap[527].y = 21;
LEDMap[526].x = 81;
LEDMap[526].y = 21;
LEDMap[503].x = 84;
LEDMap[503].y = 21;
LEDMap[423].x = 93;
LEDMap[423].y = 21;
LEDMap[422].x = 95;
LEDMap[422].y = 21;
LEDMap[379].x = 104;
LEDMap[379].y = 21;
LEDMap[380].x = 106;
LEDMap[380].y = 21;
LEDMap[282].x = 115;
LEDMap[282].y = 21;
LEDMap[244].x = 125;
LEDMap[244].y = 21;
LEDMap[134].x = 135;
LEDMap[134].y = 21;
LEDMap[118].x = 143;
LEDMap[118].y = 21;
LEDMap[119].x = 144;
LEDMap[119].y = 21;
LEDMap[528].x = 77;
LEDMap[528].y = 22;
LEDMap[502].x = 82;
LEDMap[502].y = 22;
LEDMap[424].x = 92;
LEDMap[424].y = 22;
LEDMap[378].x = 102;
LEDMap[378].y = 22;
LEDMap[284].x = 112;
LEDMap[284].y = 22;
LEDMap[283].x = 113;
LEDMap[283].y = 22;
LEDMap[243].x = 123;
LEDMap[243].y = 22;
LEDMap[135].x = 133;
LEDMap[135].y = 22;
LEDMap[117].x = 141;
LEDMap[117].y = 22;
LEDMap[529].x = 75;
LEDMap[529].y = 23;
LEDMap[501].x = 80;
LEDMap[501].y = 23;
LEDMap[426].x = 88;
LEDMap[426].y = 23;
LEDMap[425].x = 90;
LEDMap[425].y = 23;
LEDMap[377].x = 100;
LEDMap[377].y = 23;
LEDMap[285].x = 109;
LEDMap[285].y = 23;
LEDMap[242].x = 121;
LEDMap[242].y = 23;
LEDMap[137].x = 130;
LEDMap[137].y = 23;
LEDMap[136].x = 131;
LEDMap[136].y = 23;
LEDMap[116].x = 139;
LEDMap[116].y = 23;
LEDMap[7].x = 143;
LEDMap[7].y = 23;
LEDMap[6].x = 145;
LEDMap[6].y = 23;
LEDMap[530].x = 73;
LEDMap[530].y = 24;
LEDMap[500].x = 78;
LEDMap[500].y = 24;
LEDMap[427].x = 86;
LEDMap[427].y = 24;
LEDMap[375].x = 96;
LEDMap[375].y = 24;
LEDMap[376].x = 98;
LEDMap[376].y = 24;
LEDMap[286].x = 108;
LEDMap[286].y = 24;
LEDMap[241].x = 119;
LEDMap[241].y = 24;
LEDMap[138].x = 128;
LEDMap[138].y = 24;
LEDMap[114].x = 135;
LEDMap[114].y = 24;
LEDMap[115].x = 137;
LEDMap[115].y = 24;
LEDMap[8].x = 142;
LEDMap[8].y = 24;
LEDMap[536].x = 63;
LEDMap[536].y = 25;
LEDMap[532].x = 68;
LEDMap[532].y = 25;
LEDMap[531].x = 71;
LEDMap[531].y = 25;
LEDMap[499].x = 77;
LEDMap[499].y = 25;
LEDMap[428].x = 84;
LEDMap[428].y = 25;
LEDMap[374].x = 94;
LEDMap[374].y = 25;
LEDMap[287].x = 106;
LEDMap[287].y = 25;
LEDMap[239].x = 115;
LEDMap[239].y = 25;
LEDMap[240].x = 117;
LEDMap[240].y = 25;
LEDMap[139].x = 126;
LEDMap[139].y = 25;
LEDMap[112].x = 131;
LEDMap[112].y = 25;
LEDMap[113].x = 133;
LEDMap[113].y = 25;
LEDMap[10].x = 138;
LEDMap[10].y = 25;
LEDMap[9].x = 140;
LEDMap[9].y = 25;
LEDMap[1].x = 143;
LEDMap[1].y = 25;
LEDMap[535].x = 64;
LEDMap[535].y = 26;
LEDMap[534].x = 66;
LEDMap[534].y = 26;
LEDMap[533].x = 67;
LEDMap[533].y = 26;
LEDMap[498].x = 75;
LEDMap[498].y = 26;
LEDMap[429].x = 82;
LEDMap[429].y = 26;
LEDMap[373].x = 92;
LEDMap[373].y = 26;
LEDMap[288].x = 104;
LEDMap[288].y = 26;
LEDMap[238].x = 114;
LEDMap[238].y = 26;
LEDMap[140].x = 124;
LEDMap[140].y = 26;
LEDMap[111].x = 129;
LEDMap[111].y = 26;
LEDMap[13].x = 133;
LEDMap[13].y = 26;
LEDMap[12].x = 135;
LEDMap[12].y = 26;
LEDMap[11].x = 136;
LEDMap[11].y = 26;
LEDMap[2].x = 145;
LEDMap[2].y = 26;
LEDMap[497].x = 73;
LEDMap[497].y = 27;
LEDMap[430].x = 80;
LEDMap[430].y = 27;
LEDMap[371].x = 89;
LEDMap[371].y = 27;
LEDMap[372].x = 91;
LEDMap[372].y = 27;
LEDMap[290].x = 100;
LEDMap[290].y = 27;
LEDMap[289].x = 102;
LEDMap[289].y = 27;
LEDMap[237].x = 112;
LEDMap[237].y = 27;
LEDMap[141].x = 123;
LEDMap[141].y = 27;
LEDMap[110].x = 128;
LEDMap[110].y = 27;
LEDMap[537].x = 60;
LEDMap[537].y = 28;
LEDMap[495].x = 69;
LEDMap[495].y = 28;
LEDMap[496].x = 71;
LEDMap[496].y = 28;
LEDMap[431].x = 78;
LEDMap[431].y = 28;
LEDMap[370].x = 87;
LEDMap[370].y = 28;
LEDMap[291].x = 99;
LEDMap[291].y = 28;
LEDMap[236].x = 110;
LEDMap[236].y = 28;
LEDMap[142].x = 121;
LEDMap[142].y = 28;
LEDMap[109].x = 126;
LEDMap[109].y = 28;
LEDMap[16].x = 128;
LEDMap[16].y = 28;
LEDMap[15].x = 130;
LEDMap[15].y = 28;
LEDMap[14].x = 131;
LEDMap[14].y = 28;
LEDMap[540].x = 53;
LEDMap[540].y = 29;
LEDMap[539].x = 55;
LEDMap[539].y = 29;
LEDMap[538].x = 57;
LEDMap[538].y = 29;
LEDMap[494].x = 67;
LEDMap[494].y = 29;
LEDMap[433].x = 75;
LEDMap[433].y = 29;
LEDMap[432].x = 77;
LEDMap[432].y = 29;
LEDMap[369].x = 85;
LEDMap[369].y = 29;
LEDMap[292].x = 97;
LEDMap[292].y = 29;
LEDMap[235].x = 108;
LEDMap[235].y = 29;
LEDMap[144].x = 117;
LEDMap[144].y = 29;
LEDMap[143].x = 118;
LEDMap[143].y = 29;
LEDMap[108].x = 124;
LEDMap[108].y = 29;
LEDMap[17].x = 126;
LEDMap[17].y = 29;
LEDMap[0].x = 134;
LEDMap[0].y = 29;
LEDMap[542].x = 50;
LEDMap[542].y = 30;
LEDMap[541].x = 51;
LEDMap[541].y = 30;
LEDMap[492].x = 63;
LEDMap[492].y = 30;
LEDMap[493].x = 65;
LEDMap[493].y = 30;
LEDMap[368].x = 83;
LEDMap[368].y = 30;
LEDMap[293].x = 95;
LEDMap[293].y = 30;
LEDMap[234].x = 106;
LEDMap[234].y = 30;
LEDMap[145].x = 115;
LEDMap[145].y = 30;
LEDMap[107].x = 122;
LEDMap[107].y = 30;
LEDMap[18].x = 125;
LEDMap[18].y = 30;
LEDMap[543].x = 48;
LEDMap[543].y = 31;
LEDMap[491].x = 61;
LEDMap[491].y = 31;
LEDMap[435].x = 71;
LEDMap[435].y = 31;
LEDMap[434].x = 72;
LEDMap[434].y = 31;
LEDMap[367].x = 80;
LEDMap[367].y = 31;
LEDMap[294].x = 93;
LEDMap[294].y = 31;
LEDMap[232].x = 102;
LEDMap[232].y = 31;
LEDMap[233].x = 104;
LEDMap[233].y = 31;
LEDMap[146].x = 113;
LEDMap[146].y = 31;
LEDMap[105].x = 118;
LEDMap[105].y = 31;
LEDMap[106].x = 120;
LEDMap[106].y = 31;
LEDMap[19].x = 123;
LEDMap[19].y = 31;
LEDMap[586].x = 44;
LEDMap[586].y = 32;
LEDMap[544].x = 46;
LEDMap[544].y = 32;
LEDMap[489].x = 57;
LEDMap[489].y = 32;
LEDMap[490].x = 59;
LEDMap[490].y = 32;
LEDMap[436].x = 69;
LEDMap[436].y = 32;
LEDMap[365].x = 77;
LEDMap[365].y = 32;
LEDMap[366].x = 79;
LEDMap[366].y = 32;
LEDMap[296].x = 89;
LEDMap[296].y = 32;
LEDMap[295].x = 91;
LEDMap[295].y = 32;
LEDMap[231].x = 101;
LEDMap[231].y = 32;
LEDMap[147].x = 111;
LEDMap[147].y = 32;
LEDMap[104].x = 117;
LEDMap[104].y = 32;
LEDMap[21].x = 119;
LEDMap[21].y = 32;
LEDMap[20].x = 121;
LEDMap[20].y = 32;
LEDMap[585].x = 42;
LEDMap[585].y = 33;
LEDMap[488].x = 55;
LEDMap[488].y = 33;
LEDMap[438].x = 65;
LEDMap[438].y = 33;
LEDMap[437].x = 67;
LEDMap[437].y = 33;
LEDMap[364].x = 75;
LEDMap[364].y = 33;
LEDMap[297].x = 87;
LEDMap[297].y = 33;
LEDMap[230].x = 99;
LEDMap[230].y = 33;
LEDMap[149].x = 107;
LEDMap[149].y = 33;
LEDMap[148].x = 109;
LEDMap[148].y = 33;
LEDMap[103].x = 115;
LEDMap[103].y = 33;
LEDMap[22].x = 117;
LEDMap[22].y = 33;
LEDMap[584].x = 40;
LEDMap[584].y = 34;
LEDMap[545].x = 44;
LEDMap[545].y = 34;
LEDMap[487].x = 53;
LEDMap[487].y = 34;
LEDMap[439].x = 63;
LEDMap[439].y = 34;
LEDMap[363].x = 73;
LEDMap[363].y = 34;
LEDMap[298].x = 85;
LEDMap[298].y = 34;
LEDMap[229].x = 97;
LEDMap[229].y = 34;
LEDMap[150].x = 106;
LEDMap[150].y = 34;
LEDMap[102].x = 113;
LEDMap[102].y = 34;
LEDMap[23].x = 116;
LEDMap[23].y = 34;
LEDMap[582].x = 36;
LEDMap[582].y = 35;
LEDMap[583].x = 38;
LEDMap[583].y = 35;
LEDMap[546].x = 43;
LEDMap[546].y = 35;
LEDMap[486].x = 51;
LEDMap[486].y = 35;
LEDMap[440].x = 61;
LEDMap[440].y = 35;
LEDMap[362].x = 71;
LEDMap[362].y = 35;
LEDMap[299].x = 83;
LEDMap[299].y = 35;
LEDMap[228].x = 95;
LEDMap[228].y = 35;
LEDMap[151].x = 104;
LEDMap[151].y = 35;
LEDMap[101].x = 111;
LEDMap[101].y = 35;
LEDMap[24].x = 114;
LEDMap[24].y = 35;
LEDMap[581].x = 34;
LEDMap[581].y = 36;
LEDMap[547].x = 41;
LEDMap[547].y = 36;
LEDMap[485].x = 50;
LEDMap[485].y = 36;
LEDMap[441].x = 59;
LEDMap[441].y = 36;
LEDMap[361].x = 69;
LEDMap[361].y = 36;
LEDMap[301].x = 80;
LEDMap[301].y = 36;
LEDMap[300].x = 82;
LEDMap[300].y = 36;
LEDMap[226].x = 91;
LEDMap[226].y = 36;
LEDMap[227].x = 93;
LEDMap[227].y = 36;
LEDMap[152].x = 102;
LEDMap[152].y = 36;
LEDMap[99].x = 108;
LEDMap[99].y = 36;
LEDMap[100].x = 109;
LEDMap[100].y = 36;
LEDMap[25].x = 112;
LEDMap[25].y = 36;
LEDMap[580].x = 32;
LEDMap[580].y = 37;
LEDMap[549].x = 37;
LEDMap[549].y = 37;
LEDMap[548].x = 38;
LEDMap[548].y = 37;
LEDMap[483].x = 46;
LEDMap[483].y = 37;
LEDMap[484].x = 48;
LEDMap[484].y = 37;
LEDMap[443].x = 55;
LEDMap[443].y = 37;
LEDMap[442].x = 57;
LEDMap[442].y = 37;
LEDMap[360].x = 67;
LEDMap[360].y = 37;
LEDMap[302].x = 78;
LEDMap[302].y = 37;
LEDMap[225].x = 89;
LEDMap[225].y = 37;
LEDMap[153].x = 100;
LEDMap[153].y = 37;
LEDMap[98].x = 106;
LEDMap[98].y = 37;
LEDMap[27].x = 108;
LEDMap[27].y = 37;
LEDMap[26].x = 110;
LEDMap[26].y = 37;
LEDMap[579].x = 30;
LEDMap[579].y = 38;
LEDMap[550].x = 34;
LEDMap[550].y = 38;
LEDMap[482].x = 44;
LEDMap[482].y = 38;
LEDMap[444].x = 54;
LEDMap[444].y = 38;
LEDMap[359].x = 66;
LEDMap[359].y = 38;
LEDMap[303].x = 76;
LEDMap[303].y = 38;
LEDMap[224].x = 87;
LEDMap[224].y = 38;
LEDMap[155].x = 96;
LEDMap[155].y = 38;
LEDMap[154].x = 98;
LEDMap[154].y = 38;
LEDMap[97].x = 104;
LEDMap[97].y = 38;
LEDMap[28].x = 107;
LEDMap[28].y = 38;
LEDMap[578].x = 29;
LEDMap[578].y = 39;
LEDMap[551].x = 32;
LEDMap[551].y = 39;
LEDMap[481].x = 42;
LEDMap[481].y = 39;
LEDMap[445].x = 52;
LEDMap[445].y = 39;
LEDMap[357].x = 62;
LEDMap[357].y = 39;
LEDMap[358].x = 63;
LEDMap[358].y = 39;
LEDMap[304].x = 74;
LEDMap[304].y = 39;
LEDMap[223].x = 86;
LEDMap[223].y = 39;
LEDMap[156].x = 94;
LEDMap[156].y = 39;
LEDMap[95].x = 100;
LEDMap[95].y = 39;
LEDMap[96].x = 102;
LEDMap[96].y = 39;
LEDMap[30].x = 103;
LEDMap[30].y = 39;
LEDMap[29].x = 105;
LEDMap[29].y = 39;
LEDMap[577].x = 27;
LEDMap[577].y = 40;
LEDMap[552].x = 30;
LEDMap[552].y = 40;
LEDMap[479].x = 38;
LEDMap[479].y = 40;
LEDMap[480].x = 40;
LEDMap[480].y = 40;
LEDMap[446].x = 50;
LEDMap[446].y = 40;
LEDMap[356].x = 60;
LEDMap[356].y = 40;
LEDMap[305].x = 72;
LEDMap[305].y = 40;
LEDMap[222].x = 84;
LEDMap[222].y = 40;
LEDMap[157].x = 92;
LEDMap[157].y = 40;
LEDMap[94].x = 98;
LEDMap[94].y = 40;
LEDMap[31].x = 101;
LEDMap[31].y = 40;
LEDMap[576].x = 25;
LEDMap[576].y = 41;
LEDMap[553].x = 29;
LEDMap[553].y = 41;
LEDMap[478].x = 35;
LEDMap[478].y = 41;
LEDMap[447].x = 48;
LEDMap[447].y = 41;
LEDMap[355].x = 58;
LEDMap[355].y = 41;
LEDMap[306].x = 70;
LEDMap[306].y = 41;
LEDMap[220].x = 80;
LEDMap[220].y = 41;
LEDMap[221].x = 82;
LEDMap[221].y = 41;
LEDMap[158].x = 91;
LEDMap[158].y = 41;
LEDMap[93].x = 97;
LEDMap[93].y = 41;
LEDMap[32].x = 99;
LEDMap[32].y = 41;
LEDMap[574].x = 21;
LEDMap[574].y = 42;
LEDMap[575].x = 23;
LEDMap[575].y = 42;
LEDMap[554].x = 27;
LEDMap[554].y = 42;
LEDMap[477].x = 33;
LEDMap[477].y = 42;
LEDMap[449].x = 44;
LEDMap[449].y = 42;
LEDMap[448].x = 46;
LEDMap[448].y = 42;
LEDMap[354].x = 56;
LEDMap[354].y = 42;
LEDMap[308].x = 66;
LEDMap[308].y = 42;
LEDMap[307].x = 68;
LEDMap[307].y = 42;
LEDMap[219].x = 78;
LEDMap[219].y = 42;
LEDMap[159].x = 89;
LEDMap[159].y = 42;
LEDMap[92].x = 95;
LEDMap[92].y = 42;
LEDMap[33].x = 97;
LEDMap[33].y = 42;
LEDMap[573].x = 19;
LEDMap[573].y = 43;
LEDMap[555].x = 25;
LEDMap[555].y = 43;
LEDMap[476].x = 32;
LEDMap[476].y = 43;
LEDMap[450].x = 42;
LEDMap[450].y = 43;
LEDMap[353].x = 54;
LEDMap[353].y = 43;
LEDMap[309].x = 64;
LEDMap[309].y = 43;
LEDMap[218].x = 76;
LEDMap[218].y = 43;
LEDMap[161].x = 85;
LEDMap[161].y = 43;
LEDMap[160].x = 87;
LEDMap[160].y = 43;
LEDMap[90].x = 91;
LEDMap[90].y = 43;
LEDMap[91].x = 93;
LEDMap[91].y = 43;
LEDMap[34].x = 96;
LEDMap[34].y = 43;
LEDMap[571].x = 15;
LEDMap[571].y = 44;
LEDMap[572].x = 17;
LEDMap[572].y = 44;
LEDMap[557].x = 21;
LEDMap[557].y = 44;
LEDMap[556].x = 23;
LEDMap[556].y = 44;
LEDMap[475].x = 30;
LEDMap[475].y = 44;
LEDMap[451].x = 40;
LEDMap[451].y = 44;
LEDMap[351].x = 50;
LEDMap[351].y = 44;
LEDMap[352].x = 52;
LEDMap[352].y = 44;
LEDMap[310].x = 62;
LEDMap[310].y = 44;
LEDMap[217].x = 74;
LEDMap[217].y = 44;
LEDMap[162].x = 83;
LEDMap[162].y = 44;
LEDMap[89].x = 89;
LEDMap[89].y = 44;
LEDMap[36].x = 92;
LEDMap[36].y = 44;
LEDMap[35].x = 94;
LEDMap[35].y = 44;
LEDMap[3].x = 151;
LEDMap[3].y = 44;
LEDMap[568].x = 8;
LEDMap[568].y = 45;
LEDMap[569].x = 11;
LEDMap[569].y = 45;
LEDMap[570].x = 13;
LEDMap[570].y = 45;
LEDMap[558].x = 19;
LEDMap[558].y = 45;
LEDMap[474].x = 28;
LEDMap[474].y = 45;
LEDMap[452].x = 38;
LEDMap[452].y = 45;
LEDMap[350].x = 49;
LEDMap[350].y = 45;
LEDMap[311].x = 60;
LEDMap[311].y = 45;
LEDMap[216].x = 72;
LEDMap[216].y = 45;
LEDMap[163].x = 81;
LEDMap[163].y = 45;
LEDMap[87].x = 85;
LEDMap[87].y = 45;
LEDMap[88].x = 87;
LEDMap[88].y = 45;
LEDMap[37].x = 90;
LEDMap[37].y = 45;
LEDMap[565].x = 2;
LEDMap[565].y = 46;
LEDMap[566].x = 4;
LEDMap[566].y = 46;
LEDMap[567].x = 6;
LEDMap[567].y = 46;
LEDMap[559].x = 17;
LEDMap[559].y = 46;
LEDMap[473].x = 26;
LEDMap[473].y = 46;
LEDMap[453].x = 36;
LEDMap[453].y = 46;
LEDMap[349].x = 46;
LEDMap[349].y = 46;
LEDMap[312].x = 58;
LEDMap[312].y = 46;
LEDMap[214].x = 68;
LEDMap[214].y = 46;
LEDMap[215].x = 70;
LEDMap[215].y = 46;
LEDMap[165].x = 77;
LEDMap[165].y = 46;
LEDMap[164].x = 79;
LEDMap[164].y = 46;
LEDMap[86].x = 83;
LEDMap[86].y = 46;
LEDMap[39].x = 86;
LEDMap[39].y = 46;
LEDMap[38].x = 88;
LEDMap[38].y = 46;
LEDMap[561].x = 13;
LEDMap[561].y = 47;
LEDMap[560].x = 15;
LEDMap[560].y = 47;
LEDMap[472].x = 24;
LEDMap[472].y = 47;
LEDMap[454].x = 34;
LEDMap[454].y = 47;
LEDMap[348].x = 45;
LEDMap[348].y = 47;
LEDMap[314].x = 54;
LEDMap[314].y = 47;
LEDMap[313].x = 56;
LEDMap[313].y = 47;
LEDMap[213].x = 66;
LEDMap[213].y = 47;
LEDMap[166].x = 75;
LEDMap[166].y = 47;
LEDMap[85].x = 81;
LEDMap[85].y = 47;
LEDMap[41].x = 82;
LEDMap[41].y = 47;
LEDMap[40].x = 84;
LEDMap[40].y = 47;
LEDMap[563].x = 0;
LEDMap[563].y = 48;
LEDMap[562].x = 10;
LEDMap[562].y = 48;
LEDMap[470].x = 20;
LEDMap[470].y = 48;
LEDMap[471].x = 22;
LEDMap[471].y = 48;
LEDMap[456].x = 30;
LEDMap[456].y = 48;
LEDMap[455].x = 32;
LEDMap[455].y = 48;
LEDMap[347].x = 43;
LEDMap[347].y = 48;
LEDMap[315].x = 53;
LEDMap[315].y = 48;
LEDMap[212].x = 64;
LEDMap[212].y = 48;
LEDMap[167].x = 73;
LEDMap[167].y = 48;
LEDMap[83].x = 77;
LEDMap[83].y = 48;
LEDMap[43].x = 79;
LEDMap[43].y = 48;
LEDMap[84].x = 79;
LEDMap[84].y = 48;
LEDMap[42].x = 81;
LEDMap[42].y = 48;
LEDMap[469].x = 18;
LEDMap[469].y = 49;
LEDMap[457].x = 28;
LEDMap[457].y = 49;
LEDMap[316].x = 51;
LEDMap[316].y = 49;
LEDMap[210].x = 61;
LEDMap[210].y = 49;
LEDMap[211].x = 62;
LEDMap[211].y = 49;
LEDMap[169].x = 70;
LEDMap[169].y = 49;
LEDMap[168].x = 72;
LEDMap[168].y = 49;
LEDMap[82].x = 75;
LEDMap[82].y = 49;
LEDMap[44].x = 77;
LEDMap[44].y = 49;
LEDMap[468].x = 16;
LEDMap[468].y = 50;
LEDMap[346].x = 41;
LEDMap[346].y = 50;
LEDMap[317].x = 49;
LEDMap[317].y = 50;
LEDMap[209].x = 59;
LEDMap[209].y = 50;
LEDMap[170].x = 68;
LEDMap[170].y = 50;
LEDMap[81].x = 74;
LEDMap[81].y = 50;
LEDMap[45].x = 75;
LEDMap[45].y = 50;
LEDMap[467].x = 14;
LEDMap[467].y = 51;
LEDMap[459].x = 24;
LEDMap[459].y = 51;
LEDMap[458].x = 26;
LEDMap[458].y = 51;
LEDMap[318].x = 47;
LEDMap[318].y = 51;
LEDMap[208].x = 57;
LEDMap[208].y = 51;
LEDMap[171].x = 66;
LEDMap[171].y = 51;
LEDMap[79].x = 70;
LEDMap[79].y = 51;
LEDMap[47].x = 71;
LEDMap[47].y = 51;
LEDMap[80].x = 72;
LEDMap[80].y = 51;
LEDMap[46].x = 73;
LEDMap[46].y = 51;
LEDMap[466].x = 12;
LEDMap[466].y = 52;
LEDMap[342].x = 33;
LEDMap[342].y = 52;
LEDMap[343].x = 34;
LEDMap[343].y = 52;
LEDMap[319].x = 45;
LEDMap[319].y = 52;
LEDMap[207].x = 55;
LEDMap[207].y = 52;
LEDMap[172].x = 64;
LEDMap[172].y = 52;
LEDMap[78].x = 68;
LEDMap[78].y = 52;
LEDMap[48].x = 70;
LEDMap[48].y = 52;
LEDMap[461].x = 20;
LEDMap[461].y = 53;
LEDMap[460].x = 22;
LEDMap[460].y = 53;
LEDMap[341].x = 31;
LEDMap[341].y = 53;
LEDMap[321].x = 41;
LEDMap[321].y = 53;
LEDMap[320].x = 43;
LEDMap[320].y = 53;
LEDMap[206].x = 53;
LEDMap[206].y = 53;
LEDMap[174].x = 60;
LEDMap[174].y = 53;
LEDMap[173].x = 62;
LEDMap[173].y = 53;
LEDMap[77].x = 66;
LEDMap[77].y = 53;
LEDMap[49].x = 68;
LEDMap[49].y = 53;
LEDMap[462].x = 18;
LEDMap[462].y = 54;
LEDMap[340].x = 29;
LEDMap[340].y = 54;
LEDMap[344].x = 38;
LEDMap[344].y = 54;
LEDMap[322].x = 39;
LEDMap[322].y = 54;
LEDMap[345].x = 40;
LEDMap[345].y = 54;
LEDMap[205].x = 51;
LEDMap[205].y = 54;
LEDMap[175].x = 58;
LEDMap[175].y = 54;
LEDMap[76].x = 65;
LEDMap[76].y = 54;
LEDMap[50].x = 66;
LEDMap[50].y = 54;
LEDMap[464].x = 14;
LEDMap[464].y = 55;
LEDMap[463].x = 16;
LEDMap[463].y = 55;
LEDMap[338].x = 25;
LEDMap[338].y = 55;
LEDMap[339].x = 27;
LEDMap[339].y = 55;
LEDMap[323].x = 37;
LEDMap[323].y = 55;
LEDMap[203].x = 48;
LEDMap[203].y = 55;
LEDMap[204].x = 49;
LEDMap[204].y = 55;
LEDMap[176].x = 56;
LEDMap[176].y = 55;
LEDMap[75].x = 63;
LEDMap[75].y = 55;
LEDMap[51].x = 64;
LEDMap[51].y = 55;
LEDMap[465].x = 12;
LEDMap[465].y = 56;
LEDMap[337].x = 23;
LEDMap[337].y = 56;
LEDMap[324].x = 35;
LEDMap[324].y = 56;
LEDMap[202].x = 45;
LEDMap[202].y = 56;
LEDMap[177].x = 54;
LEDMap[177].y = 56;
LEDMap[74].x = 61;
LEDMap[74].y = 56;
LEDMap[52].x = 62;
LEDMap[52].y = 56;
LEDMap[336].x = 21;
LEDMap[336].y = 57;
LEDMap[325].x = 33;
LEDMap[325].y = 57;
LEDMap[179].x = 50;
LEDMap[179].y = 57;
LEDMap[178].x = 53;
LEDMap[178].y = 57;
LEDMap[72].x = 57;
LEDMap[72].y = 57;
LEDMap[73].x = 59;
LEDMap[73].y = 57;
LEDMap[53].x = 60;
LEDMap[53].y = 57;
LEDMap[335].x = 18;
LEDMap[335].y = 58;
LEDMap[326].x = 31;
LEDMap[326].y = 58;
LEDMap[201].x = 43;
LEDMap[201].y = 58;
LEDMap[180].x = 49;
LEDMap[180].y = 58;
LEDMap[71].x = 55;
LEDMap[71].y = 58;
LEDMap[55].x = 57;
LEDMap[55].y = 58;
LEDMap[54].x = 59;
LEDMap[54].y = 58;
LEDMap[327].x = 30;
LEDMap[327].y = 59;
LEDMap[198].x = 38;
LEDMap[198].y = 59;
LEDMap[199].x = 40;
LEDMap[199].y = 59;
LEDMap[200].x = 40;
LEDMap[200].y = 59;
LEDMap[200].x = 40;
LEDMap[200].y = 59;
LEDMap[181].x = 47;
LEDMap[181].y = 59;
LEDMap[69].x = 52;
LEDMap[69].y = 59;
LEDMap[70].x = 53;
LEDMap[70].y = 59;
LEDMap[56].x = 55;
LEDMap[56].y = 59;
LEDMap[334].x = 17;
LEDMap[334].y = 60;
LEDMap[328].x = 27;
LEDMap[328].y = 60;
LEDMap[182].x = 45;
LEDMap[182].y = 60;
LEDMap[330].x = 24;
LEDMap[330].y = 61;
LEDMap[329].x = 25;
LEDMap[329].y = 61;
LEDMap[183].x = 43;
LEDMap[183].y = 61;
LEDMap[68].x = 49;
LEDMap[68].y = 61;
LEDMap[57].x = 52;
LEDMap[57].y = 61;
LEDMap[331].x = 21;
LEDMap[331].y = 62;
LEDMap[197].x = 36;
LEDMap[197].y = 62;
LEDMap[184].x = 41;
LEDMap[184].y = 62;
LEDMap[66].x = 46;
LEDMap[66].y = 62;
LEDMap[59].x = 48;
LEDMap[59].y = 62;
LEDMap[60].x = 48;
LEDMap[60].y = 62;
LEDMap[61].x = 48;
LEDMap[61].y = 62;
LEDMap[67].x = 48;
LEDMap[67].y = 62;
LEDMap[58].x = 49;
LEDMap[58].y = 62;
LEDMap[333].x = 18;
LEDMap[333].y = 63;
LEDMap[332].x = 19;
LEDMap[332].y = 63;
LEDMap[65].x = 44;
LEDMap[65].y = 63;
LEDMap[63].x = 43;
LEDMap[63].y = 64;
LEDMap[64].x = 43;
LEDMap[64].y = 64;
LEDMap[62].x = 45;
LEDMap[62].y = 64;
LEDMap[188].x = 34;
LEDMap[188].y = 65;
LEDMap[187].x = 35;
LEDMap[187].y = 65;
LEDMap[186].x = 37;
LEDMap[186].y = 65;
LEDMap[185].x = 38;
LEDMap[185].y = 65;
LEDMap[191].x = 25;
LEDMap[191].y = 66;
LEDMap[194].x = 31;
LEDMap[194].y = 66;
LEDMap[195].x = 32;
LEDMap[195].y = 66;
LEDMap[189].x = 33;
LEDMap[189].y = 67;
LEDMap[196].x = 33;
LEDMap[196].y = 67;
LEDMap[192].x = 29;
LEDMap[192].y = 69;
LEDMap[193].x = 31;
LEDMap[193].y = 70;
LEDMap[190].x = 28;
LEDMap[190].y = 71;
LEDMap[5].x = 169;
LEDMap[5].y = 74;
}

