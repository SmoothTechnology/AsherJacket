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
#include "ShoulderLeftMap.h"
#include "ShoulderRightMap.h"

const int ledsPerStrip = 1280;

DMAMEM int displayMemory[ledsPerStrip*8];
int drawingMemory[ledsPerStrip*8];

const int config = WS2811_GRB | WS2811_800kHz;

OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);

MatrixDraw LeftArmBackCanvas            (xSizeLeftArmBack, ySizeLeftArmBack);
MatrixDraw LeftArmFrontPartTwoCanvas    (xSizeLeftArmPartTwo, ySizeLeftArmPartTwo);
MatrixDraw LeftArmFrontPartOneCanvas    (xSizeLeftArmFrontPartOne, ySizeLeftArmFrontPartOne);
MatrixDraw LeftBackCanvas               (xSizeLeftBack, ySizeLeftBack, 3);
MatrixDraw LeftChestCanvas              (xSizeLeftChest, ySizeLeftChest, 3);
MatrixDraw RightArmBackCanvas           (xSizeRightArmBack, ySizeRightArmBack);
MatrixDraw RightArmFrontPartOneCanvas   (xSizeRightArmPartOne, ySizeRightArmPartOne);
MatrixDraw RightArmFrontPartTwoCanvas   (xSizeRightArmPartTwo, ySizeRightArmPartTwo);
MatrixDraw RightBackCanvas              (xSizeRightBack, ySizeRightBack, 3);
MatrixDraw RightChestCanvas             (xSizeRightChest, ySizeRightChest, 3);
MatrixDraw RightShoulderCanvas          (xSizeRightShoulder, ySizeRightShoulder);
MatrixDraw LeftShoulderCanvas           (xSizeLeftShoulder, ySizeLeftShoulder);

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {

    uint8_t r = 255 - WheelPos *3;
    uint8_t g = 0;
    uint8_t b = WheelPos*3;

    return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
  }

  if(WheelPos < 170) {

    WheelPos -= 85;
    uint8_t r = 0;
    uint8_t g = WheelPos*3;
    uint8_t b = 255-WheelPos*3;
    
    return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
  }

  WheelPos -= 170;
  uint8_t r = WheelPos*3; 
  uint8_t g = 255-WheelPos*3;
  uint8_t b = 0;

  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

static const int8_t PROGMEM sinetab[256] = {
     0,   2,   5,   8,  11,  15,  18,  21,
    24,  27,  30,  33,  36,  39,  42,  45,
    48,  51,  54,  56,  59,  62,  65,  67,
    70,  72,  75,  77,  80,  82,  85,  87,
    89,  91,  93,  96,  98, 100, 101, 103,
   105, 107, 108, 110, 111, 113, 114, 116,
   117, 118, 119, 120, 121, 122, 123, 123,
   124, 125, 125, 126, 126, 126, 126, 126,
   127, 126, 126, 126, 126, 126, 125, 125,
   124, 123, 123, 122, 121, 120, 119, 118,
   117, 116, 114, 113, 111, 110, 108, 107,
   105, 103, 101, 100,  98,  96,  93,  91,
    89,  87,  85,  82,  80,  77,  75,  72,
    70,  67,  65,  62,  59,  56,  54,  51,
    48,  45,  42,  39,  36,  33,  30,  27,
    24,  21,  18,  15,  11,   8,   5,   2,
     0,  -3,  -6,  -9, -12, -16, -19, -22,
   -25, -28, -31, -34, -37, -40, -43, -46,
   -49, -52, -55, -57, -60, -63, -66, -68,
   -71, -73, -76, -78, -81, -83, -86, -88,
   -90, -92, -94, -97, -99,-101,-102,-104,
  -106,-108,-109,-111,-112,-114,-115,-117,
  -118,-119,-120,-121,-122,-123,-124,-124,
  -125,-126,-126,-127,-127,-127,-127,-127,
  -128,-127,-127,-127,-127,-127,-126,-126,
  -125,-124,-124,-123,-122,-121,-120,-119,
  -118,-117,-115,-114,-112,-111,-109,-108,
  -106,-104,-102,-101, -99, -97, -94, -92,
   -90, -88, -86, -83, -81, -78, -76, -73,
   -71, -68, -66, -63, -60, -57, -55, -52,
   -49, -46, -43, -40, -37, -34, -31, -28,
   -25, -22, -19, -16, -12,  -9,  -6,  -3
};

const float radius1  = 16.3, radius2  = 23.0, radius3  = 40.8, radius4  = 44.2,
            centerx1 = 16.1, centerx2 = 11.6, centerx3 = 23.4, centerx4 =  4.1, 
            centery1 =  8.7, centery2 =  6.5, centery3 = 14.0, centery4 = -2.9;
float       angle1   =  0.0, angle2   =  0.0, angle3   =  0.0, angle4   =  0.0;
long        hueShift =  0;

void DrawPlasma() {
  int           x1, x2, x3, x4, y1, y2, y3, y4, sx1, sx2, sx3, sx4;
  unsigned char x, y;
  long          value;

  sx1 = (int)(cos(angle1) * radius1 + centerx1);
  sx2 = (int)(cos(angle2) * radius2 + centerx2);
  sx3 = (int)(cos(angle3) * radius3 + centerx3);
  sx4 = (int)(cos(angle4) * radius4 + centerx4);
  y1  = (int)(sin(angle1) * radius1 + centery1);
  y2  = (int)(sin(angle2) * radius2 + centery2);
  y3  = (int)(sin(angle3) * radius3 + centery3);
  y4  = (int)(sin(angle4) * radius4 + centery4);

  for(y=0; y< ySizeRightChest; y++) {
    x1 = sx1; x2 = sx2; x3 = sx3; x4 = sx4;
    for(x=0; x<xSizeRightChest; x++) {
      value = hueShift
        + (int8_t)pgm_read_byte(sinetab + (uint8_t)((x1 * x1 + y1 * y1) >> 2))
        + (int8_t)pgm_read_byte(sinetab + (uint8_t)((x2 * x2 + y2 * y2) >> 2))
        + (int8_t)pgm_read_byte(sinetab + (uint8_t)((x3 * x3 + y3 * y3) >> 3))
        + (int8_t)pgm_read_byte(sinetab + (uint8_t)((x4 * x4 + y4 * y4) >> 3));

        value %= 1536; 
        byte byteValue = map(value, -1536, 1536, 0, 255);
        value = Wheel(byteValue);
        RightChestCanvas.SetPixelAt(x, y, value);

      x1--; x2--; x3--; x4--;
    }
    y1--; y2--; y3--; y4--;
  }

  angle1 += 0.03;
  angle2 -= 0.07;
  angle3 += 0.13;
  angle4 -= 0.15;
  hueShift += 2;

  DrawAllMatrices();
}



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
  RightShoulderCanvas.ClearMatrix();
  LeftShoulderCanvas.ClearMatrix();           
}

#define RED    0xFF0000
#define GREEN  0x00AA00
#define BLUE   0x0000FF
#define YELLOW 0xFFFF00
#define PINK   0xFF1088
#define ORANGE 0xE05800
#define WHITE  0xFFFFFF

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
  InitializeRightShoulderMap();
  InitializeLeftShoulderMap();
}

void DrawLeftArmBackMatrix()
{
  for(int i = minLEDLeftArmBack; i < maxLEDLeftArmBack+1; i++)
  {
    LEDPos curPos = LeftArmBackMap[i - minLEDLeftArmBack];
    int value = LeftArmBackCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawLeftArmFrontPartTwoMatrix()
{
  for(int i = minLEDLeftArmPartTwo; i < maxLEDLeftArmPartTwo+1; i++)
  {
    LEDPos curPos = LeftArmPartTwoMap[i - minLEDLeftArmPartTwo];
    int value = LeftArmFrontPartTwoCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawLeftArmFrontPartOneMatrix()
{
  for(int i = minLEDLeftArmFrontPartOne; i < maxLEDLeftArmFrontPartOne+1; i++)
  {
    LEDPos curPos = LeftArmPartOneMap[i - minLEDLeftArmFrontPartOne];
    int value = LeftArmFrontPartOneCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawLeftBackMatrix()
{
  for(int i = minLEDLeftBack; i < maxLEDLeftBack+1; i++)
  {
    LEDPos curPos = LeftBackMap[i - minLEDLeftBack];
    int value = LeftBackCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawLeftChestMatrix()
{

  for(int i = minLEDLeftChest; i < maxLEDLeftChest+1; i++)
  {
    LEDPos curPos = LeftChestMap[i - minLEDLeftChest];
    int value = LeftChestCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawRightArmBackMatrix()
{
  for(int i = minLEDRightArmBack; i < maxLEDRightArmBack+1; i++)
  {
    LEDPos curPos = RightArmBackMap[i - minLEDRightArmBack];
    int value = RightArmBackCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawRightArmFrontPartOneMatrix()
{
  for(int i = minLEDRightArmPartOne; i < maxLEDRightArmPartOne+1; i++)
  {
    LEDPos curPos = RightArmPartOneMap[i - minLEDRightArmPartOne];
    int value = RightArmFrontPartOneCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawRightArmFrontPartTwoMatrix()
{
  for(int i = minLEDRightArmPartTwo; i < maxLEDRightArmPartTwo+1; i++)
  {
    LEDPos curPos = RightArmPartTwoMap[i - minLEDRightArmPartTwo];
    int value = RightArmFrontPartTwoCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawRightBackMatrix()
{
  for(int i = minLEDRightBack; i < maxLEDRightBack+1; i++)
  {
    LEDPos curPos = RightBackMap[i - minLEDRightBack];
    int value = RightBackCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawRightChestMatrix()
{
  for(int i = minLEDRightChest; i < maxLEDRightChest+1; i++)
  {
    LEDPos curPos = RightChestMap[i - minLEDRightChest];
    int value = RightChestCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawRightShoulderMatrix()
{
  for(int i = minLEDRightShoulder; i < maxLEDRightShoulder+1; i++)
  {
    LEDPos curPos = RightShoulderMap[i - minLEDRightShoulder];
    int value = RightShoulderCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawLeftShoulderMatrix()
{
  for(int i = minLEDLeftShoulder; i < maxLEDLeftShoulder+1; i++)
  {
    LEDPos curPos = LeftShoulderMap[i - minLEDLeftShoulder];
    int value = LeftShoulderCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawAllMatrices()
{

  DrawLeftArmBackMatrix();
  DrawLeftArmFrontPartTwoMatrix();
  DrawLeftArmFrontPartOneMatrix();
  DrawLeftBackMatrix();
  DrawLeftChestMatrix();
//
  DrawRightArmBackMatrix();
  DrawRightArmFrontPartTwoMatrix();
  DrawRightArmFrontPartOneMatrix();
  
  DrawRightBackMatrix();
  DrawRightChestMatrix();

 DrawRightShoulderMatrix();
 DrawLeftShoulderMatrix();

  leds.show();
}

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  leds.begin();
  leds.show();

  delay(1000);
  Serial.println("Starting up Now");

  InitializeAllMaps();
  InitializeMatrices();

  Serial.println("Past initializations");

  //lightAll(GREEN);

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

void CenterOut()
{
  int maxFrames = 20;
  int armTrigger = maxFrames;
  int fadeTrigger = maxFrames;
  for(int i = maxFrames; i > 0; i--)
  {
    int rightChestPositionY = map(i, 0, maxFrames, 10, ySizeRightChest-1);
    int leftChestPositionY = map(i, maxFrames, 0, 10, ySizeLeftChest-1);

    int blobSize = map(i, maxFrames, 0, 2, 10);

    RightChestCanvas.DrawRectangle(xSizeRightChest/2 - blobSize, rightChestPositionY-10, xSizeRightChest/2 + blobSize, rightChestPositionY, 0x008800);
    RightChestCanvas.Fill(xSizeRightChest/2, rightChestPositionY-blobSize/2, 0x008800);
    RightChestCanvas.MeanFilter(3);
    LeftChestCanvas.DrawRectangle(xSizeLeftChest/2 - blobSize, leftChestPositionY-10, xSizeLeftChest/2 + blobSize, leftChestPositionY, 0x008800);
    LeftChestCanvas.Fill(xSizeLeftChest/2, leftChestPositionY-blobSize/2, 0x008800);
    LeftChestCanvas.MeanFilter(3);


    if(i < armTrigger)
    {
      // Right Arms
      int rightArmBackPos = map(i, armTrigger, 0, 5, xSizeRightArmBack-1);
      RightArmBackCanvas.DrawRectangle(rightArmBackPos - 5, 0, rightArmBackPos, ySizeRightArmBack-1, 0xFFAA00);
      RightArmBackCanvas.Fill(rightArmBackPos-2, ySizeRightArmBack/2, 0xFFAA00);

      int rightArmFrontPartTwoPos = map(i, armTrigger, 0, 5, xSizeRightArmPartTwo-1);
      RightArmFrontPartTwoCanvas.DrawRectangle(rightArmFrontPartTwoPos-5, 0, rightArmFrontPartTwoPos-1, ySizeRightArmPartTwo-1, 0xFFAA00);
      RightArmFrontPartTwoCanvas.Fill(rightArmFrontPartTwoPos-2, ySizeRightArmPartTwo/2, 0xFFAA00);

      int rightArmFrontPartOnePos = map(i, armTrigger, 0, 5, xSizeRightArmPartOne-1);
      RightArmFrontPartOneCanvas.DrawRectangle(rightArmFrontPartOnePos-5, 0, rightArmFrontPartOnePos-1, ySizeRightArmPartOne-1, 0xFFAA00);
      RightArmFrontPartOneCanvas.Fill(rightArmFrontPartOnePos-2, ySizeRightArmPartOne/2, 0xFFAA00);


      // Left Arms
      int leftArmBackPos = map(i, armTrigger, 0, 5, xSizeLeftArmBack-1);
      LeftArmBackCanvas.DrawRectangle(leftArmBackPos - 5, 0, leftArmBackPos, ySizeLeftArmBack-1, 0xFFAA00);
      LeftArmBackCanvas.Fill(leftArmBackPos-2, ySizeLeftArmBack/2, 0xFFAA00);

      int leftArmFrontPartTwoPos = map(i, armTrigger, 0, 5, xSizeLeftArmPartTwo-1);
      LeftArmFrontPartTwoCanvas.DrawRectangle(leftArmFrontPartTwoPos-5, 0, leftArmFrontPartTwoPos-1, ySizeLeftArmPartTwo-1, 0xFFAA00);
      LeftArmFrontPartTwoCanvas.Fill(leftArmFrontPartTwoPos-2, ySizeLeftArmPartTwo/2, 0xFFAA00);

      int leftArmFrontPartOnePos = map(i, armTrigger, 0, 5, xSizeLeftArmFrontPartOne-1);
      LeftArmFrontPartOneCanvas.DrawRectangle(leftArmFrontPartOnePos-5, 0, leftArmFrontPartOnePos-1, ySizeLeftArmFrontPartOne-1, 0xFFAA00);
      LeftArmFrontPartOneCanvas.Fill(leftArmFrontPartOnePos-2, ySizeLeftArmFrontPartOne/2, 0xFFAA00);
    }

    if(i < fadeTrigger)
    {
      int glowLevel = map(i, 0, fadeTrigger, 0, 100);
      int redLevel = map(glowLevel, 0, 100, 0, 70);
      int greenLevel = map(glowLevel, 0, 100, 0, 40);
      int color = redLevel << 16;
      color += greenLevel << 8;
      color = color & 0xFFFF00;

      RightBackCanvas.Fill(5,5, color);
      LeftBackCanvas.Fill(5,5, color);
    }


    DrawAllMatrices();
    InitializeMatrices();

    Serial.print("On Frame: ");
    Serial.print(i);
    Serial.print(" Right Chest Position: ");
    Serial.println(rightChestPositionY);
  }
  
}

void TurnLeft()
{

  int maxFrames = 20;
  int armTrigger = maxFrames;
  int fadeTrigger = maxFrames;

  for(int i = maxFrames; i > 0; i--)
  {
    int leftChestPositionY = map(i, maxFrames, 0, 10, ySizeLeftChest-1);

    int blobSize = map(i, maxFrames, 0, 2, 10);

    LeftChestCanvas.DrawRectangle(xSizeLeftChest/2 - blobSize, leftChestPositionY-10, xSizeLeftChest/2 + blobSize, leftChestPositionY, 0x008800);
    LeftChestCanvas.Fill(xSizeLeftChest/2, leftChestPositionY-blobSize/2, 0x008800);
    LeftChestCanvas.MeanFilter(3);

    if(i < armTrigger)
    {
      // Left Arms
      int leftArmBackPos = map(i, armTrigger, 0, 5, xSizeLeftArmBack-1);
      LeftArmBackCanvas.DrawRectangle(leftArmBackPos - 5, 0, leftArmBackPos, ySizeLeftArmBack-1, 0xFFAA00);
      LeftArmBackCanvas.Fill(leftArmBackPos-2, ySizeLeftArmBack/2, 0xFFAA00);

      int leftArmFrontPartTwoPos = map(i, armTrigger, 0, 5, xSizeLeftArmPartTwo-1);
      LeftArmFrontPartTwoCanvas.DrawRectangle(leftArmFrontPartTwoPos-5, 0, leftArmFrontPartTwoPos-1, ySizeLeftArmPartTwo-1, 0xFFAA00);
      LeftArmFrontPartTwoCanvas.Fill(leftArmFrontPartTwoPos-2, ySizeLeftArmPartTwo/2, 0xFFAA00);

      int leftArmFrontPartOnePos = map(i, armTrigger, 0, 5, xSizeLeftArmFrontPartOne-1);
      LeftArmFrontPartOneCanvas.DrawRectangle(leftArmFrontPartOnePos-5, 0, leftArmFrontPartOnePos-1, ySizeLeftArmFrontPartOne-1, 0xFFAA00);
      LeftArmFrontPartOneCanvas.Fill(leftArmFrontPartOnePos-2, ySizeLeftArmFrontPartOne/2, 0xFFAA00);
    }

    if(i < fadeTrigger)
    {
      int glowLevel = map(i, 0, fadeTrigger, 0, 100);
      int redLevel = map(glowLevel, 0, 100, 0, 70);
      int greenLevel = map(glowLevel, 0, 100, 0, 40);
      int color = redLevel << 16;
      color += greenLevel << 8;
      color = color & 0xFFFF00;

      LeftBackCanvas.Fill(5,5, color);
    }

    DrawAllMatrices();
    InitializeMatrices();

    Serial.print("On Frame: ");
    Serial.print(i);
    Serial.print(" Left Chest Position: ");
    Serial.println(leftChestPositionY);
  }
}

void TurnRight()
{

  int maxFrames = 20;
  int armTrigger = maxFrames;
  int fadeTrigger = maxFrames;

  for(int i = maxFrames; i > 0; i--)
  {
    int rightChestPositionY = map(i, 0, maxFrames, 10, ySizeRightChest-1);

    int blobSize = map(i, maxFrames, 0, 2, 10);

    RightChestCanvas.DrawRectangle(xSizeRightChest/2 - blobSize, rightChestPositionY-10, xSizeRightChest/2 + blobSize, rightChestPositionY, 0x008800);
    RightChestCanvas.Fill(xSizeRightChest/2, rightChestPositionY-blobSize/2, 0x008800);
    RightChestCanvas.MeanFilter(3);

    if(i < armTrigger)
    {
      // Right Arms
      int rightArmBackPos = map(i, armTrigger, 0, 5, xSizeRightArmBack-1);
      RightArmBackCanvas.DrawRectangle(rightArmBackPos - 5, 0, rightArmBackPos, ySizeRightArmBack-1, 0xFFAA00);
      RightArmBackCanvas.Fill(rightArmBackPos-2, ySizeRightArmBack/2, 0xFFAA00);

      int rightArmFrontPartTwoPos = map(i, armTrigger, 0, 5, xSizeRightArmPartTwo-1);
      RightArmFrontPartTwoCanvas.DrawRectangle(rightArmFrontPartTwoPos-5, 0, rightArmFrontPartTwoPos-1, ySizeRightArmPartTwo-1, 0xFFAA00);
      RightArmFrontPartTwoCanvas.Fill(rightArmFrontPartTwoPos-2, ySizeRightArmPartTwo/2, 0xFFAA00);

      int rightArmFrontPartOnePos = map(i, armTrigger, 0, 5, xSizeRightArmPartOne-1);
      RightArmFrontPartOneCanvas.DrawRectangle(rightArmFrontPartOnePos-5, 0, rightArmFrontPartOnePos-1, ySizeRightArmPartOne-1, 0xFFAA00);
      RightArmFrontPartOneCanvas.Fill(rightArmFrontPartOnePos-2, ySizeRightArmPartOne/2, 0xFFAA00);
    }

    if(i < fadeTrigger)
    {
      int glowLevel = map(i, 0, fadeTrigger, 0, 100);
      int redLevel = map(glowLevel, 0, 100, 0, 70);
      int greenLevel = map(glowLevel, 0, 100, 0, 40);
      int color = redLevel << 16;
      color += greenLevel << 8;
      color = color & 0xFFFF00;

      RightBackCanvas.Fill(5,5, color);
    }

    DrawAllMatrices();
    InitializeMatrices();

    Serial.print("On Frame: ");
    Serial.print(i);
    Serial.print(" Right Chest Position: ");
    Serial.println(rightChestPositionY);
  }
}

void DrawWings()
{
  //for(int i = 0; i < 13; i++)
  //{
  //  RightBackCanvas.DrawLine(0,ySizeRightBack/2, xSizeRightBack-1, i, 0x00FF00);
  //  //LeftBackCanvas.DrawLine(0, ySizeLeftBack/2, xSizeLeftBack-1, i, 0x00FF00);
  //  DrawAllMatrices();
  //  RightBackCanvas.ClearMatrix();
  //  //LeftBackCanvas.ClearMatrix();
  //  delay(100);
  //  Serial.println("Drawing Wings 1");
  //}
  
  for(int i = 0; i < 20; i++)
  {
    RightBackCanvas.DrawLine(xSizeRightBack/2, 0, i, ySizeRightBack-1, 0x00FF00);
    RightBackCanvas.DrawLine(xSizeRightBack/2, 0, i+1, ySizeRightBack-1, 0x00FF00);
    RightBackCanvas.DrawLine(xSizeRightBack/2, 0, i+2, ySizeRightBack-1, 0x00FF00);
    RightBackCanvas.DrawLine(xSizeRightBack/2, 0, i+3, ySizeRightBack-1, 0x00FF00);
    RightBackCanvas.DrawLine(xSizeRightBack/2, 0, i+4, ySizeRightBack-1, 0x00FF00);
    RightBackCanvas.DrawLine(xSizeRightBack/2, 0, i+5, ySizeRightBack-1, 0x00FF00);

    LeftBackCanvas.DrawLine(i  ,  0, xSizeLeftBack/2, ySizeLeftBack-1, 0x00FF00);
    LeftBackCanvas.DrawLine(i+1,  0, xSizeLeftBack/2, ySizeLeftBack-1, 0x00FF00);
    LeftBackCanvas.DrawLine(i+2,  0, xSizeLeftBack/2, ySizeLeftBack-1, 0x00FF00);
    LeftBackCanvas.DrawLine(i+3,  0, xSizeLeftBack/2, ySizeLeftBack-1, 0x00FF00);
    LeftBackCanvas.DrawLine(i+4,  0, xSizeLeftBack/2, ySizeLeftBack-1, 0x00FF00);
    LeftBackCanvas.DrawLine(i+5,  0, xSizeLeftBack/2, ySizeLeftBack-1, 0x00FF00);

    int glowLevel = map(i, 0, 20, 0, 50);
    RightChestCanvas.Fill(5, 5, glowLevel);
    LeftChestCanvas.Fill(5, 5, glowLevel);
    RightArmFrontPartOneCanvas.Fill(5, 5, glowLevel);
    RightArmFrontPartTwoCanvas.Fill(5, 5, glowLevel);
    RightArmBackCanvas.Fill(5,5,glowLevel);
    LeftArmFrontPartOneCanvas.Fill(5,5, glowLevel);
    LeftArmFrontPartTwoCanvas.Fill(5,5,glowLevel);
    LeftArmBackCanvas.Fill(5,5,glowLevel);

    //RightBackCanvas.Fill(30, 5, 0xFF0000);
    LeftBackCanvas.MeanFilter(3);
    RightBackCanvas.MeanFilter(3);
    //RightBackCanvas.Fill(5,5, 0xAA00AA);
    //RightBackCanvas.Fill(5, 5, 0xFF00FF);
    
    //LeftBackCanvas.DrawLine(xSizeLeftBack/2, 0, i, i, 0x00FF00);
    DrawAllMatrices();
    InitializeMatrices();
    delay(20);
//  
  Serial.print(i);
  Serial.print(" ");
    Serial.println("Drawing Wings");
  }

  for(int i = 20; i > 0; i--)
  {

    RightBackCanvas.DrawLine(xSizeRightBack/2, 0, i, ySizeRightBack-1, 0x00FF00);
    RightBackCanvas.DrawLine(xSizeRightBack/2, 0, i+1, ySizeRightBack-1, 0x00FF00);
    RightBackCanvas.DrawLine(xSizeRightBack/2, 0, i+2, ySizeRightBack-1, 0x00FF00);
    RightBackCanvas.DrawLine(xSizeRightBack/2, 0, i+3, ySizeRightBack-1, 0x00FF00);
    RightBackCanvas.DrawLine(xSizeRightBack/2, 0, i+4, ySizeRightBack-1, 0x00FF00);
    RightBackCanvas.DrawLine(xSizeRightBack/2, 0, i+5, ySizeRightBack-1, 0x00FF00);

    LeftBackCanvas.DrawLine(i  ,  0, xSizeLeftBack/2, ySizeLeftBack-1, 0x00FF00);
    LeftBackCanvas.DrawLine(i+1,  0, xSizeLeftBack/2, ySizeLeftBack-1, 0x00FF00);
    LeftBackCanvas.DrawLine(i+2,  0, xSizeLeftBack/2, ySizeLeftBack-1, 0x00FF00);
    LeftBackCanvas.DrawLine(i+3,  0, xSizeLeftBack/2, ySizeLeftBack-1, 0x00FF00);
    LeftBackCanvas.DrawLine(i+4,  0, xSizeLeftBack/2, ySizeLeftBack-1, 0x00FF00);
    LeftBackCanvas.DrawLine(i+5,  0, xSizeLeftBack/2, ySizeLeftBack-1, 0x00FF00);

    int glowLevel = map(i, 0, 20, 0, 50);
    RightChestCanvas.Fill(5, 5, glowLevel);
    LeftChestCanvas.Fill(5, 5, glowLevel);
    RightArmFrontPartOneCanvas.Fill(5, 5, glowLevel);
    RightArmFrontPartTwoCanvas.Fill(5, 5, glowLevel);
    RightArmBackCanvas.Fill(5,5,glowLevel);
    LeftArmFrontPartOneCanvas.Fill(5,5, glowLevel);
    LeftArmFrontPartTwoCanvas.Fill(5,5,glowLevel);
    LeftArmBackCanvas.Fill(5,5,glowLevel);

    //RightBackCanvas.Fill(30, 5, 0xFF0000);
    LeftBackCanvas.MeanFilter(3);
    RightBackCanvas.MeanFilter(3);
    //RightBackCanvas.Fill(5, 5, 0xFF00FF);
    
    //LeftBackCanvas.DrawLine(xSizeLeftBack/2, 0, i, i, 0x00FF00);
    DrawAllMatrices();
    InitializeMatrices();
    delay(20);
//  
  Serial.print(i);
  Serial.print(" ");
    Serial.println("Drawing Wings");
  }
}

void LightUpAllCanvases()
{
  LeftArmBackCanvas.Fill(5, 5, 0xAA0000);      
  LeftArmFrontPartTwoCanvas.Fill(5, 5, 0x00AA00);  
  LeftArmFrontPartOneCanvas.Fill(5, 5, 0x0000AA);   
  LeftBackCanvas.Fill(5, 5, 0xAA00AA);              
  LeftChestCanvas.Fill(5, 5, 0xAAAA00);             
  RightArmBackCanvas.Fill(5, 5, 0xAAAAAA);          
  RightArmFrontPartOneCanvas.Fill(5, 5, 0xAA0000);  
  RightArmFrontPartTwoCanvas.Fill(5, 5, 0x00AA00);  
  RightBackCanvas.Fill(5, 5, 0xAA00AA);             
  RightChestCanvas.Fill(5, 5, 0xAAAA00);

  DrawAllMatrices();
}

void StopLight()
{


  for(int i = 0; i < 10; i++)
  {
    int glowLevel = map(i, 0, 10, 0, 0x11);

    int colorValue = glowLevel << 16;
    colorValue = colorValue & 0xFF0000;

    LeftArmBackCanvas.Fill(5, 5, colorValue);      
    LeftArmFrontPartTwoCanvas.Fill(5, 5, colorValue);  
    LeftArmFrontPartOneCanvas.Fill(5, 5, colorValue);   
    LeftBackCanvas.Fill(5, 5, colorValue);              
    LeftChestCanvas.Fill(5, 5, colorValue);             
    RightArmBackCanvas.Fill(5, 5, colorValue);          
    RightArmFrontPartOneCanvas.Fill(5, 5, colorValue);  
    RightArmFrontPartTwoCanvas.Fill(5, 5, colorValue);  
    RightBackCanvas.Fill(5, 5, colorValue);             
    RightChestCanvas.Fill(5, 5, colorValue);

    DrawAllMatrices();

    InitializeMatrices();
  }

  delay(1000);

  for(int i = 0; i < 10; i++)
  {
    int glowLevel = map(i, 10, 0, 0, 0x11);

    int colorValue = glowLevel << 16;
    colorValue = colorValue & 0xFF0000;

    LeftArmBackCanvas.Fill(5, 5, colorValue);      
    LeftArmFrontPartTwoCanvas.Fill(5, 5, colorValue);  
    LeftArmFrontPartOneCanvas.Fill(5, 5, colorValue);   
    LeftBackCanvas.Fill(5, 5, colorValue);              
    LeftChestCanvas.Fill(5, 5, colorValue);             
    RightArmBackCanvas.Fill(5, 5, colorValue);          
    RightArmFrontPartOneCanvas.Fill(5, 5, colorValue);  
    RightArmFrontPartTwoCanvas.Fill(5, 5, colorValue);  
    RightBackCanvas.Fill(5, 5, colorValue);             
    RightChestCanvas.Fill(5, 5, colorValue);

    DrawAllMatrices();

    InitializeMatrices();
  }

  
}

void loop() {
  //int microsec = 0;  // change them all in 2 seconds
//
  //// uncomment for voltage controlled speed
  //// millisec = analogRead(A9) / 40;
  ////colorWipe(GREEN, microsec);
//
//
//
  //if(Serial.available() > 2)
  //{
  //    for(int i = 0; i < leds.numPixels(); i++)
  //    {
  //        leds.setPixel(i, 0x000000);
  //    }
//
  //    int led2Light = Serial.parseInt();
  //    Serial.println("In Here");
  //    Serial.println(led2Light);
//
  //    leds.setPixel(led2Light, GREEN);
  //    leds.show();
  //}
//
  //delay(5); 

  //for(int i = 0; i < 22; i++)
  //{
  //  RightArmFrontPartOneCanvas.DrawRectangle(i, 0, i+10, 10, 0x990000);
  //  RightArmFrontPartOneCanvas.Fill(i+4, 5, 0x009900);
  //  RightArmFrontPartTwoCanvas.DrawRectangle(i, 0, i+10, 10, 0x990000);
  //  RightArmFrontPartTwoCanvas.Fill(i+4, 5, 0x009900);
  //  DrawAllMatrices();
  //  RightArmFrontPartOneCanvas.ClearMatrix();
  //  RightArmFrontPartTwoCanvas.ClearMatrix();
  //  Serial.println("Good to go");
  //  delay(100);
  //}

  //DrawWings();
  
  //LightUpAllCanvases();

 //for(int i = 0; i < 4; i++)
 //{
 //  CenterOut();
 //}
 //InitializeMatrices();
 //
 //for(int i = 0; i < 4; i++)
 //{
 //  TurnRight();
 //}
 //InitializeMatrices();
 //
 //for(int i = 0; i < 4; i++)
 //{
 //  TurnLeft();
 //}
 //InitializeMatrices();
 //
 //for(int i = 0; i < 4; i++)
 //{
 //  DrawWings();
 //}
 //InitializeMatrices();
 //
 //StopLight();
 //InitializeMatrices();

  DrawPlasma();
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

