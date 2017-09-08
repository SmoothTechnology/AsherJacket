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

#define RELAY_PIN 0

int turnSignals = 0;

int plasmaState = 0;
// 0 - Normal
// 1 - Stop

const int ledsPerStrip = 1280;

DMAMEM int displayMemory[ledsPerStrip*8];
int drawingMemory[ledsPerStrip*8];

double curBrightness = 0;
double maxBrightness = 0.1;
double brightnessChangeVal = 0.005;

const int config = WS2811_GRB | WS2813_800kHz;

OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);

MatrixDraw LeftArmBackCanvas            (xSizeLeftArmBack, ySizeLeftArmBack);
MatrixDraw LeftArmFrontPartTwoCanvas    (xSizeLeftArmPartTwo, ySizeLeftArmPartTwo);
MatrixDraw LeftArmFrontPartOneCanvas    (xSizeLeftArmFrontPartOne, ySizeLeftArmFrontPartOne);
MatrixDraw LeftBackCanvas               (xSizeLeftBack, ySizeLeftBack);
MatrixDraw LeftChestCanvas              (xSizeLeftChest, ySizeLeftChest);
MatrixDraw RightArmBackCanvas           (xSizeRightArmBack, ySizeRightArmBack);
MatrixDraw RightArmFrontPartOneCanvas   (xSizeRightArmPartOne, ySizeRightArmPartOne);
MatrixDraw RightArmFrontPartTwoCanvas   (xSizeRightArmPartTwo, ySizeRightArmPartTwo);
MatrixDraw RightBackCanvas              (xSizeRightBack, ySizeRightBack);
MatrixDraw RightChestCanvas             (xSizeRightChest, ySizeRightChest);
MatrixDraw RightShoulderCanvas          (xSizeRightShoulder, ySizeRightShoulder, 3);
MatrixDraw LeftShoulderCanvas           (xSizeLeftShoulder, ySizeLeftShoulder, 3);

int masterFrame = 0;

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

  for(y=0; y< 60; y++) {
    x1 = sx1; x2 = sx2; x3 = sx3; x4 = sx4;
    for(x=0; x<60; x++) {
      value = hueShift
        + (int8_t)pgm_read_byte(sinetab + (uint8_t)((x1 * x1 + y1 * y1) >> 2))
        + (int8_t)pgm_read_byte(sinetab + (uint8_t)((x2 * x2 + y2 * y2) >> 2))
        + (int8_t)pgm_read_byte(sinetab + (uint8_t)((x3 * x3 + y3 * y3) >> 3))
        + (int8_t)pgm_read_byte(sinetab + (uint8_t)((x4 * x4 + y4 * y4) >> 3));

        value %= 1536; 

        //double multiplier = value / 1536.0;
//
        //int eachValue = 255 * multiplier;
        //value << eachValue

        byte byteValue = map(value, -1536, 1536, 0, 255);
        value = Wheel(byteValue);

        if(x < xSizeRightChest && y < ySizeRightChest)
        {
          RightChestCanvas.SetPixelAt(x, y, value);
        }

        if(x < xSizeLeftChest && y < ySizeLeftChest)
        {
          LeftChestCanvas.SetPixelAt(x, y, value);
        }
        
        if(x < xSizeLeftArmBack && y < ySizeLeftArmBack)
        {
          LeftArmBackCanvas.SetPixelAt(x,y,value);
        }

        if(x < xSizeLeftArmPartTwo && y < ySizeLeftArmPartTwo)
        {
          LeftArmFrontPartTwoCanvas.SetPixelAt(x, y, value);
        }

        if(x < xSizeLeftArmFrontPartOne && y < ySizeLeftArmFrontPartOne)
        {
          LeftArmFrontPartOneCanvas.SetPixelAt(x, y, value);
        }

        if(x < xSizeLeftBack && y < ySizeLeftBack)
        {
          LeftBackCanvas.SetPixelAt(x, y, value);
        }

        if(x < xSizeRightBack && y < ySizeRightBack)
        {
          RightBackCanvas.SetPixelAt(x, y, value);
        }

        if(x < xSizeRightArmBack && y < ySizeRightArmBack)
        {
          RightArmBackCanvas.SetPixelAt(x, y, value);
        }

        if(x < xSizeRightArmPartOne && y < ySizeRightArmPartOne)
        {
          RightArmFrontPartOneCanvas.SetPixelAt(x, y, value);
        }

        if(x < xSizeRightArmPartTwo && y < ySizeRightArmPartTwo)
        {
          RightArmFrontPartTwoCanvas.SetPixelAt(x, y, value);
        }

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
 
uint8_t const cos_wave_Fast[256] PROGMEM =  
{0,0,0,0,1,1,1,2,2,3,4,5,6,6,8,9,10,11,12,14,15,17,18,20,22,23,25,27,29,31,33,35,38,40,42,
45,47,49,52,54,57,60,62,65,68,71,73,76,79,82,85,88,91,94,97,100,103,106,109,113,116,119,
122,125,128,131,135,138,141,144,147,150,153,156,159,162,165,168,171,174,177,180,183,186,
189,191,194,197,199,202,204,207,209,212,214,216,218,221,223,225,227,229,231,232,234,236,
238,239,241,242,243,245,246,247,248,249,250,251,252,252,253,253,254,254,255,255,255,255,
255,255,255,255,254,254,253,253,252,252,251,250,249,248,247,246,245,243,242,241,239,238,
236,234,232,231,229,227,225,223,221,218,216,214,212,209,207,204,202,199,197,194,191,189,
186,183,180,177,174,171,168,165,162,159,156,153,150,147,144,141,138,135,131,128,125,122,
119,116,113,109,106,103,100,97,94,91,88,85,82,79,76,73,71,68,65,62,60,57,54,52,49,47,45,
42,40,38,35,33,31,29,27,25,23,22,20,18,17,15,14,12,11,10,9,8,6,6,5,4,3,2,2,1,1,1,0,0,0,0
};

uint8_t const cos_wave[256] PROGMEM = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,5,7,10,13,15,18,20,23,26,28,31,33,36,38,41,43,46,48,51,53,56,58,61,63,65,68,70,72,74,77,79,81,83,86,88,90,92,94,96,98,100,102,104,106,107,109,111,113,114,116,118,119,121,122,124,125,127,128,129,131,132,133,134,135,137,138,139,140,140,141,142,143,144,144,145,146,146,147,147,148,148,148,149,149,149,149,149,149,150,149,149,149,149,149,149,148,148,148,147,147,146,146,145,144,144,143,142,141,140,140,139,138,137,135,134,133,132,131,129,128,127,125,124,122,121,119,118,116,114,113,111,109,107,106,104,102,100,98,96,94,92,90,88,86,83,81,79,77,74,72,70,68,65,63,61,58,56,53,51,48,46,43,41,38,36,33,31,28,26,23,20,18,15,13,10,7,5,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

inline uint8_t fastCosineCalcMovement( uint16_t preWrapVal)
{
  uint8_t wrapVal = (preWrapVal % 255);
  if (wrapVal<0) wrapVal=255+wrapVal;
  return (pgm_read_byte_near(cos_wave_Fast+wrapVal)); 
} 

inline uint8_t fastCosineCalc( uint16_t preWrapVal)
{
  uint8_t wrapVal = (preWrapVal % 255);
  if (wrapVal<0) wrapVal=255+wrapVal;
  return (pgm_read_byte_near(cos_wave+wrapVal)); 
}
 
void drawPlasma2(int frameCount) {
    uint16_t t = fastCosineCalcMovement((92 * frameCount)/100);  //time displacement - fiddle with these til it looks good...
    uint16_t t2 = fastCosineCalcMovement((55 * frameCount)/100); 
    uint16_t t3 = fastCosineCalcMovement((83 * frameCount)/100);
    for (uint8_t y = 0; y <= 60; y++)
    {
       for (uint8_t x = 0; x <= 60; x++) 
       {
          uint8_t r = fastCosineCalc(((x << 3) + (t >> 1) + fastCosineCalc((t2 + (y << 3)))));  //Calculate 3 seperate plasma waves, one for each color channel
          uint8_t g = fastCosineCalc(((y << 3) + t + fastCosineCalc(((t3 >> 2) + (x << 3)))));
          uint8_t b = fastCosineCalc(((y << 3) + t2 + fastCosineCalc((t + x + (g >> 2)))));
          //uncomment the following to enable gamma correction
         // r=pgm_read_byte_near(exp_gamma+r);  
         // g=pgm_read_byte_near(exp_gamma+g);
         // b=pgm_read_byte_near(exp_gamma+b);
         // drawPixel(x,y,CRGB(r,g,b));  // Is this the fastest method to update the draw buffer with colors? 

         //r = r*0.01;
         //r = r*100;

         int value = 0;

         // Purple
         if(plasmaState == 0)
         {
            uint8_t blue = r;
            r = r*0.4;
            value = r << 16 | r << 8 | blue;
            value = value & 0xFF00FF;
         }
         

         // Red
         if(plasmaState == 1)
         {
            r = r*0.4;
            value = r << 16 | r << 8 | r;
            value = value & 0xFF0000;
         }

        //value = r << 16 | g << 8 | b;

        if(x < xSizeRightChest && y < ySizeRightChest)
        {
          
          RightChestCanvas.SetPixelAt(x, y, value);
        }

        if(x < xSizeLeftChest && y < ySizeLeftChest)
        {
          LeftChestCanvas.SetPixelAt(x, y, value);
        }
        
        if(x < xSizeLeftArmBack && y < ySizeLeftArmBack)
        {
          LeftArmBackCanvas.SetPixelAt(x,y,value);
        }

        if(x < xSizeLeftArmPartTwo && y < ySizeLeftArmPartTwo)
        {
          LeftArmFrontPartTwoCanvas.SetPixelAt(x, y, value);
        }

        if(x < xSizeLeftArmFrontPartOne && y < ySizeLeftArmFrontPartOne)
        {
          LeftArmFrontPartOneCanvas.SetPixelAt(x, y, value);
        }

        if(x < xSizeLeftBack && y < ySizeLeftBack)
        {
          LeftBackCanvas.SetPixelAt(x, y, value);
        }

        if(x < xSizeRightBack && y < ySizeRightBack)
        {
          RightBackCanvas.SetPixelAt(x, y, value);
        }

        if(x < xSizeRightArmBack && y < ySizeRightArmBack)
        {
          RightArmBackCanvas.SetPixelAt(x, y, value);
        }

        if(x < xSizeRightArmPartOne && y < ySizeRightArmPartOne)
        {
          RightArmFrontPartOneCanvas.SetPixelAt(x, y, value);
        }

        if(x < xSizeRightArmPartTwo && y < ySizeRightArmPartTwo)
        {
          RightArmFrontPartTwoCanvas.SetPixelAt(x, y, value);
        }
        if(x < xSizeRightShoulder && y < ySizeRightShoulder)
        {
          RightShoulderCanvas.SetPixelAt(x,y, value);
        }
        if(x < xSizeLeftShoulder && y < ySizeLeftShoulder)
        {
          LeftShoulderCanvas.SetPixelAt(x,y, value);
        }
      }
    }
    //DrawAllMatrices();
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

uint32_t SetBrightness(uint32_t colorVal)
{
  int r = (colorVal >> 16) & 0xFF;
  int g = (colorVal >> 8) & 0xFF;
  int b = colorVal & 0xFF;

  r = r*curBrightness;
  g = g*curBrightness;
  b = b*curBrightness;

  uint32_t color = r << 16 | g << 8 | b;

  return color;
}

void IncrementBrightness()
{
  curBrightness += brightnessChangeVal;

  if(curBrightness > maxBrightness) curBrightness = maxBrightness;
}

void DecrementBrightness()
{
  curBrightness -= brightnessChangeVal;

  if(curBrightness < 0) curBrightness = 0;
}


void DrawLeftArmBackMatrix()
{
  for(int i = minLEDLeftArmBack; i < maxLEDLeftArmBack+1; i++)
  {
    LEDPos curPos = LeftArmBackMap[i - minLEDLeftArmBack];
    int value = LeftArmBackCanvas.GetValueAt(curPos.x, curPos.y);
    value = SetBrightness(value);
    leds.setPixel(i, value);
  }
}

void DrawLeftArmFrontPartTwoMatrix()
{
  for(int i = minLEDLeftArmPartTwo; i < maxLEDLeftArmPartTwo+1; i++)
  {
    LEDPos curPos = LeftArmPartTwoMap[i - minLEDLeftArmPartTwo];
    int value = LeftArmFrontPartTwoCanvas.GetValueAt(curPos.x, curPos.y);
    value = SetBrightness(value);
    leds.setPixel(i, value);
  }
}

void DrawLeftArmFrontPartOneMatrix()
{
  for(int i = minLEDLeftArmFrontPartOne; i < maxLEDLeftArmFrontPartOne+1; i++)
  {
    LEDPos curPos = LeftArmPartOneMap[i - minLEDLeftArmFrontPartOne];
    int value = LeftArmFrontPartOneCanvas.GetValueAt(curPos.x, curPos.y);
    value = SetBrightness(value);
    leds.setPixel(i, value);
  }
}

void DrawLeftBackMatrix()
{
  for(int i = minLEDLeftBack; i < maxLEDLeftBack+1; i++)
  {
    LEDPos curPos = LeftBackMap[i - minLEDLeftBack];
    int value = LeftBackCanvas.GetValueAt(curPos.x, curPos.y);
    value = SetBrightness(value);
    leds.setPixel(i, value);
  }
}

void DrawLeftChestMatrix()
{

  for(int i = minLEDLeftChest; i < maxLEDLeftChest+1; i++)
  {
    LEDPos curPos = LeftChestMap[i - minLEDLeftChest];
    int value = LeftChestCanvas.GetValueAt(curPos.x, curPos.y);
    value = SetBrightness(value);
    leds.setPixel(i, value);
  }
}

void DrawRightArmBackMatrix()
{
  for(int i = minLEDRightArmBack; i < maxLEDRightArmBack+1; i++)
  {
    LEDPos curPos = RightArmBackMap[i - minLEDRightArmBack];
    int value = RightArmBackCanvas.GetValueAt(curPos.x, curPos.y);
    value = SetBrightness(value);
    leds.setPixel(i, value);
  }
}

void DrawRightArmFrontPartOneMatrix()
{
  for(int i = minLEDRightArmPartOne; i < maxLEDRightArmPartOne+1; i++)
  {
    LEDPos curPos = RightArmPartOneMap[i - minLEDRightArmPartOne];
    int value = RightArmFrontPartOneCanvas.GetValueAt(curPos.x, curPos.y);
    value = SetBrightness(value);
    leds.setPixel(i, value);
  }
}

void DrawRightArmFrontPartTwoMatrix()
{
  for(int i = minLEDRightArmPartTwo; i < maxLEDRightArmPartTwo+1; i++)
  {
    LEDPos curPos = RightArmPartTwoMap[i - minLEDRightArmPartTwo];
    int value = RightArmFrontPartTwoCanvas.GetValueAt(curPos.x, curPos.y);
    value = SetBrightness(value);
    leds.setPixel(i, value);
  }
}

void DrawRightBackMatrix()
{
  for(int i = minLEDRightBack; i < maxLEDRightBack+1; i++)
  {
    LEDPos curPos = RightBackMap[i - minLEDRightBack];
    int value = RightBackCanvas.GetValueAt(curPos.x, curPos.y);
    value = SetBrightness(value);
    leds.setPixel(i, value);
  }
}

void DrawRightChestMatrix()
{
  for(int i = minLEDRightChest; i < maxLEDRightChest+1; i++)
  {
    LEDPos curPos = RightChestMap[i - minLEDRightChest];
    int value = RightChestCanvas.GetValueAt(curPos.x, curPos.y);
    value = SetBrightness(value);
    leds.setPixel(i, value);
  }
}

void DrawRightShoulderMatrix()
{
  if(turnSignals)
  {
    for(int i = minLEDRightShoulder+34; i < maxLEDRightShoulder+1; i++)
    {
      LEDPos curPos = RightShoulderMap[i - minLEDRightShoulder];
      int value = RightShoulderCanvas.GetValueAt(curPos.x, curPos.y);
      value = SetBrightness(value);
      leds.setPixel(i, value);
    }

    for(int i = minLEDRightShoulder; i < minLEDRightShoulder + 34; i++)
    {
      uint32_t color = 0x000000;
      leds.setPixel(i, color);
    }
  }
  else
  {
    for(int i = minLEDRightShoulder; i < maxLEDRightShoulder+1; i++)
    {
      LEDPos curPos = RightShoulderMap[i - minLEDRightShoulder];
      int value = RightShoulderCanvas.GetValueAt(curPos.x, curPos.y);
      value = SetBrightness(value);
      leds.setPixel(i, value);
    }
  }
  
}

void DrawLeftShoulderMatrix()
{
  if(turnSignals)
  {
    for(int i = minLEDLeftShoulder+37; i < maxLEDLeftShoulder+1; i++)
    {
      LEDPos curPos = LeftShoulderMap[i - minLEDLeftShoulder];
      int value = LeftShoulderCanvas.GetValueAt(curPos.x, curPos.y);
      value = SetBrightness(value);
      leds.setPixel(i, value);
    }

    for(int i = minLEDLeftShoulder; i < minLEDLeftShoulder+ 37; i++)
    {
      uint32_t color = 0x000000;
      leds.setPixel(i, color);
    }
  }
  else
  {
      for(int i = minLEDLeftShoulder; i < maxLEDLeftShoulder+1; i++)
      {
        LEDPos curPos = LeftShoulderMap[i - minLEDLeftShoulder];
        int value = LeftShoulderCanvas.GetValueAt(curPos.x, curPos.y);
        value = SetBrightness(value);
        leds.setPixel(i, value);
      }
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

void SetJacketOn()
{
  digitalWrite(RELAY_PIN, LOW);
}

void SetJacketOff()
{
  digitalWrite(RELAY_PIN, HIGH);
}

void setup() {

  pinMode(RELAY_PIN, OUTPUT);
  

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

void TurnRightNewShoulders(bool increment = true)
{
  turnSignals = 1;
  int maxFrames = 10;
  int startX = 15;
  int startY = 13;
  int endX = 16;
  int endY = 14;

  for(int i = 0; i < maxFrames; i++)
  { 

    if(increment) 
      IncrementBrightness();
    else 
      DecrementBrightness();

    int xDrawStart = startX - i*2;
    int yDrawStart = startY - i*2;
    int xDrawEnd = endX + i*2;
    int YDrawEnd = endY + i*2;

    if(xDrawStart < 0)
      xDrawStart = 0;
    if(yDrawStart < 0)
      yDrawStart = 0;
    if(xDrawEnd > xSizeRightShoulder - 1)
      xDrawEnd = xSizeRightShoulder - 1;
    if(YDrawEnd > ySizeRightShoulder - 1)
      YDrawEnd = ySizeRightShoulder - 1;

    int greenLevel = map(i, maxFrames, 0, 0, 255);
    int color = greenLevel << 16 | greenLevel;
    color = color & 0xFF00FF;

    RightShoulderCanvas.DrawRectangle(xDrawStart, yDrawStart, xDrawEnd, YDrawEnd, color);
    RightShoulderCanvas.Fill((startX+endX)/2, (startY+endY)/2, color);

    plasmaState = 0;
    drawPlasma2(masterFrame+=random(1,4));

    DrawAllMatrices();

    RightShoulderCanvas.ClearMatrix();
  }
  turnSignals= 0;
}

void TurnLeftNewShoulders(bool increment = true)
{
  turnSignals = 1;
  int maxFrames = 10;
  int startX = 15;
  int startY = 6;
  int endX = 16;
  int endY = 8;

  for(int i = 0; i < maxFrames; i++)
  { 

    if(increment) 
      IncrementBrightness();
    else 
      DecrementBrightness();

    int xDrawStart = startX - i*2;
    int yDrawStart = startY - i*2;
    int xDrawEnd = endX + i*2;
    int YDrawEnd = endY + i*2;

    if(xDrawStart < 0)
      xDrawStart = 0;
    if(yDrawStart < 0)
      yDrawStart = 0;
    if(xDrawEnd > xSizeLeftShoulder - 1)
      xDrawEnd = xSizeLeftShoulder - 1;
    if(YDrawEnd > ySizeLeftShoulder - 1)
      YDrawEnd = ySizeLeftShoulder - 1;

    int greenLevel = map(i, maxFrames, 0, 0, 255);
    int color = greenLevel << 16 | greenLevel;
    color = color & 0xFF00FF;

    LeftShoulderCanvas.DrawRectangle(xDrawStart, yDrawStart, xDrawEnd, YDrawEnd, color);
    LeftShoulderCanvas.Fill((startX+endX)/2, (startY+endY)/2, color);

    plasmaState = 0;
    drawPlasma2(masterFrame+=random(1,4));

    DrawAllMatrices();

    LeftShoulderCanvas.ClearMatrix();
  }
  turnSignals = 0;
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

  int armTrigger = 20;
  
  for(int i = 0; i < 20; i++)
  {
    for(int j = 0; j < 12; j++)
    {
      RightBackCanvas.DrawLine(xSizeRightBack/2, 0, i+j, ySizeRightBack-1, Wheel(j*3));
      LeftBackCanvas.DrawLine(i+j  ,  0, xSizeLeftBack/2, ySizeLeftBack-1, Wheel(j*3));
    }

    int glowLevel = map(i, 0, 20, 0, 50);
    RightChestCanvas.Fill(5, 5, glowLevel);
    LeftChestCanvas.Fill(5, 5, glowLevel);
    //RightArmFrontPartOneCanvas.Fill(5, 5, glowLevel);
    //RightArmFrontPartTwoCanvas.Fill(5, 5, glowLevel);
    //RightArmBackCanvas.Fill(5,5,glowLevel);
    //LeftArmFrontPartOneCanvas.Fill(5,5, glowLevel);
    //LeftArmFrontPartTwoCanvas.Fill(5,5,glowLevel);
    //LeftArmBackCanvas.Fill(5,5,glowLevel);

    //RightBackCanvas.Fill(30, 5, 0xFF0000);
    LeftBackCanvas.MeanFilterByColor(3);
    RightBackCanvas.MeanFilterByColor(3);
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

    for(int j = 0; j < 12; j++)
    {
      RightBackCanvas.DrawLine(xSizeRightBack/2, 0, i+j, ySizeRightBack-1, Wheel(j*3));
      LeftBackCanvas.DrawLine(i+j  ,  0, xSizeLeftBack/2, ySizeLeftBack-1, Wheel(j*3));
    }

    int redLevel = map(i, 0, 20, 0, 0xFF);
    int greenLevel = map(i, 0, 20, 0, 0xAA);
    int color = redLevel << 16 | greenLevel << 8;
    color = color & 0xFFFF00;

    // Right Arms
    int rightArmBackPos = map(i, armTrigger, 0, 5, xSizeRightArmBack-1);
    RightArmBackCanvas.DrawRectangle(rightArmBackPos - 5, 0, rightArmBackPos, ySizeRightArmBack-1, color);
    RightArmBackCanvas.Fill(rightArmBackPos-2, ySizeRightArmBack/2, color);

    int rightArmFrontPartTwoPos = map(i, armTrigger, 0, 5, xSizeRightArmPartTwo-1);
    RightArmFrontPartTwoCanvas.DrawRectangle(rightArmFrontPartTwoPos-5, 0, rightArmFrontPartTwoPos-1, ySizeRightArmPartTwo-1, color);
    RightArmFrontPartTwoCanvas.Fill(rightArmFrontPartTwoPos-2, ySizeRightArmPartTwo/2, color);

    int rightArmFrontPartOnePos = map(i, armTrigger, 0, 5, xSizeRightArmPartOne-1);
    RightArmFrontPartOneCanvas.DrawRectangle(rightArmFrontPartOnePos-5, 0, rightArmFrontPartOnePos-1, ySizeRightArmPartOne-1, color);
    RightArmFrontPartOneCanvas.Fill(rightArmFrontPartOnePos-2, ySizeRightArmPartOne/2, color);

    // Left Arms
    int leftArmBackPos = map(i, armTrigger, 0, 5, xSizeLeftArmBack-1);
    LeftArmBackCanvas.DrawRectangle(leftArmBackPos - 5, 0, leftArmBackPos, ySizeLeftArmBack-1, color);
    LeftArmBackCanvas.Fill(leftArmBackPos-2, ySizeLeftArmBack/2, color);

    int leftArmFrontPartTwoPos = map(i, armTrigger, 0, 5, xSizeLeftArmPartTwo-1);
    LeftArmFrontPartTwoCanvas.DrawRectangle(leftArmFrontPartTwoPos-5, 0, leftArmFrontPartTwoPos-1, ySizeLeftArmPartTwo-1, color);
    LeftArmFrontPartTwoCanvas.Fill(leftArmFrontPartTwoPos-2, ySizeLeftArmPartTwo/2, color);

    int leftArmFrontPartOnePos = map(i, armTrigger, 0, 5, xSizeLeftArmFrontPartOne-1);
    LeftArmFrontPartOneCanvas.DrawRectangle(leftArmFrontPartOnePos-5, 0, leftArmFrontPartOnePos-1, ySizeLeftArmFrontPartOne-1, color);
    LeftArmFrontPartOneCanvas.Fill(leftArmFrontPartOnePos-2, ySizeLeftArmFrontPartOne/2, color);


    int glowLevel = map(i, 0, 20, 0, 50);
    RightChestCanvas.Fill(5, 5, glowLevel);
    LeftChestCanvas.Fill(5, 5, glowLevel);
    //RightArmFrontPartOneCanvas.Fill(0, 0, glowLevel);
    //RightArmFrontPartTwoCanvas.Fill(0, 0, glowLevel);
    //RightArmBackCanvas.Fill(0,0,glowLevel);
    //LeftArmFrontPartOneCanvas.Fill(0,0, glowLevel);
    //LeftArmFrontPartTwoCanvas.Fill(0,0,glowLevel);
    //LeftArmBackCanvas.Fill(0,0,glowLevel);

    //RightBackCanvas.Fill(30, 5, 0xFF0000);
    LeftBackCanvas.MeanFilterByColor(3);
    RightBackCanvas.MeanFilterByColor(3);
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


void DrawWingsBezier()
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

  unsigned long lastMillis = millis();
  int armTrigger = 20;
  
  for(int i = 0; i < 20; i++)
  {
    for(int j = 0; j < 12; j++)
    {
      RightBackCanvas.DrawBezierCurve(xSizeRightBack/2, 0, xSizeLeftBack/2 + 2, ySizeLeftBack-4, i+j, ySizeRightBack-1, Wheel(j*3));
      LeftBackCanvas.DrawBezierCurve(i+j  ,  0, xSizeLeftBack/2 + 2, ySizeLeftBack-4, xSizeLeftBack/2, ySizeLeftBack-1, Wheel(j*3));
    }

    int glowLevel = map(i, 0, 20, 0, 50);
    RightChestCanvas.Fill(5, 5, glowLevel);
    LeftChestCanvas.Fill(5, 5, glowLevel);
    //RightArmFrontPartOneCanvas.Fill(5, 5, glowLevel);
    //RightArmFrontPartTwoCanvas.Fill(5, 5, glowLevel);
    //RightArmBackCanvas.Fill(5,5,glowLevel);
    //LeftArmFrontPartOneCanvas.Fill(5,5, glowLevel);
    //LeftArmFrontPartTwoCanvas.Fill(5,5,glowLevel);
    //LeftArmBackCanvas.Fill(5,5,glowLevel);

    //RightBackCanvas.Fill(30, 5, 0xFF0000);
    LeftBackCanvas.MeanFilterByColor(3);
    RightBackCanvas.MeanFilterByColor(3);
    //RightBackCanvas.Fill(5,5, 0xAA00AA);
    //RightBackCanvas.Fill(5, 5, 0xFF00FF);
    
    //LeftBackCanvas.DrawLine(xSizeLeftBack/2, 0, i, i, 0x00FF00);
    DrawAllMatrices();
    InitializeMatrices();
    delay(20);
//  
  Serial.print(millis() - lastMillis);
  lastMillis = millis();
  Serial.print(" ");
  Serial.print(i);
  Serial.print(" ");
    Serial.println("Drawing Wings");

  }

  for(int i = 20; i > 0; i--)
  {

    for(int j = 0; j < 12; j++)
    {
      RightBackCanvas.DrawBezierCurve(xSizeRightBack/2, 0, xSizeLeftBack/2 + 2, ySizeLeftBack-4, i+j, ySizeRightBack-1, Wheel(j*3));
      LeftBackCanvas.DrawBezierCurve(i+j  ,  0, xSizeLeftBack/2 + 2, ySizeLeftBack-4, xSizeLeftBack/2, ySizeLeftBack-1, Wheel(j*3));
    }

    int redLevel = map(i, 0, 20, 0, 0xFF);
    int greenLevel = map(i, 0, 20, 0, 0xAA);
    int color = redLevel << 16 | greenLevel << 8;
    color = color & 0xFFFF00;

    // Right Arms
    int rightArmBackPos = map(i, armTrigger, 0, 5, xSizeRightArmBack-1);
    RightArmBackCanvas.DrawRectangle(rightArmBackPos - 5, 0, rightArmBackPos, ySizeRightArmBack-1, color);
    RightArmBackCanvas.Fill(rightArmBackPos-2, ySizeRightArmBack/2, color);

    int rightArmFrontPartTwoPos = map(i, armTrigger, 0, 5, xSizeRightArmPartTwo-1);
    RightArmFrontPartTwoCanvas.DrawRectangle(rightArmFrontPartTwoPos-5, 0, rightArmFrontPartTwoPos-1, ySizeRightArmPartTwo-1, color);
    RightArmFrontPartTwoCanvas.Fill(rightArmFrontPartTwoPos-2, ySizeRightArmPartTwo/2, color);

    int rightArmFrontPartOnePos = map(i, armTrigger, 0, 5, xSizeRightArmPartOne-1);
    RightArmFrontPartOneCanvas.DrawRectangle(rightArmFrontPartOnePos-5, 0, rightArmFrontPartOnePos-1, ySizeRightArmPartOne-1, color);
    RightArmFrontPartOneCanvas.Fill(rightArmFrontPartOnePos-2, ySizeRightArmPartOne/2, color);

    // Left Arms
    int leftArmBackPos = map(i, armTrigger, 0, 5, xSizeLeftArmBack-1);
    LeftArmBackCanvas.DrawRectangle(leftArmBackPos - 5, 0, leftArmBackPos, ySizeLeftArmBack-1, color);
    LeftArmBackCanvas.Fill(leftArmBackPos-2, ySizeLeftArmBack/2, color);

    int leftArmFrontPartTwoPos = map(i, armTrigger, 0, 5, xSizeLeftArmPartTwo-1);
    LeftArmFrontPartTwoCanvas.DrawRectangle(leftArmFrontPartTwoPos-5, 0, leftArmFrontPartTwoPos-1, ySizeLeftArmPartTwo-1, color);
    LeftArmFrontPartTwoCanvas.Fill(leftArmFrontPartTwoPos-2, ySizeLeftArmPartTwo/2, color);

    int leftArmFrontPartOnePos = map(i, armTrigger, 0, 5, xSizeLeftArmFrontPartOne-1);
    LeftArmFrontPartOneCanvas.DrawRectangle(leftArmFrontPartOnePos-5, 0, leftArmFrontPartOnePos-1, ySizeLeftArmFrontPartOne-1, color);
    LeftArmFrontPartOneCanvas.Fill(leftArmFrontPartOnePos-2, ySizeLeftArmFrontPartOne/2, color);


    int glowLevel = map(i, 0, 20, 0, 50);
    RightChestCanvas.Fill(5, 5, glowLevel);
    LeftChestCanvas.Fill(5, 5, glowLevel);
    //RightArmFrontPartOneCanvas.Fill(0, 0, glowLevel);
    //RightArmFrontPartTwoCanvas.Fill(0, 0, glowLevel);
    //RightArmBackCanvas.Fill(0,0,glowLevel);
    //LeftArmFrontPartOneCanvas.Fill(0,0, glowLevel);
    //LeftArmFrontPartTwoCanvas.Fill(0,0,glowLevel);
    //LeftArmBackCanvas.Fill(0,0,glowLevel);

    //RightBackCanvas.Fill(30, 5, 0xFF0000);
    LeftBackCanvas.MeanFilterByColor(3);
    RightBackCanvas.MeanFilterByColor(3);
    //RightBackCanvas.Fill(5, 5, 0xFF00FF);
    
    //LeftBackCanvas.DrawLine(xSizeLeftBack/2, 0, i, i, 0x00FF00);
    DrawAllMatrices();
    InitializeMatrices();
    delay(20);

    Serial.print(millis() - lastMillis);
    Serial.print(" ");
    lastMillis = millis();
    Serial.print(i);
    Serial.print(" ");
    Serial.println("Drawing Wings");
  }
}

void DrawWingFrame1()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.DrawRectangle(21, 0, 23, 5, color);
  RightShoulderCanvas.Fill(22, 3, color);

  LeftShoulderCanvas.DrawRectangle(0,4, 4,7, color);
  LeftShoulderCanvas.Fill(2,5,color);
}

void DrawWingFrame2()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.SetPixelAt(21,6, color);
  RightShoulderCanvas.SetPixelAt(21,7, color);
  RightShoulderCanvas.DrawRectangle(0, 16, 8, 18, color);
  RightShoulderCanvas.Fill(4,17, color);

  LeftShoulderCanvas.DrawRectangle(3,3, 5, 7, color);
  LeftShoulderCanvas.Fill(4,4, color);
  LeftShoulderCanvas.DrawRectangle(18,18, 22,24, color);
  LeftShoulderCanvas.Fill(19, 20, color);
}

void DrawWingFrame3()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.SetPixelAt(20,7, color);
  RightShoulderCanvas.SetPixelAt(21,7, color);

  RightShoulderCanvas.DrawLine(7, 17, 9,17, color);


  LeftShoulderCanvas.SetPixelAt(6,6, color);
  LeftShoulderCanvas.SetPixelAt(7,6, color);
  LeftShoulderCanvas.SetPixelAt(8,6, color);
  LeftShoulderCanvas.DrawRectangle(18, 16, 21, 19, color);
  LeftShoulderCanvas.Fill(19, 17, color);

}

void DrawWingFrame4()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.SetPixelAt(9,17, color);
  RightShoulderCanvas.SetPixelAt(8,17, color);
  RightShoulderCanvas.SetPixelAt(10,16, color);
  RightShoulderCanvas.SetPixelAt(19,8, color);
  RightShoulderCanvas.SetPixelAt(20, 8, color);

  LeftShoulderCanvas.SetPixelAt(8,6, color);
  LeftShoulderCanvas.SetPixelAt(8,7, color);
  LeftShoulderCanvas.SetPixelAt(9,6, color);
  LeftShoulderCanvas.SetPixelAt(9,7, color);
  LeftShoulderCanvas.SetPixelAt(19,15, color);
  LeftShoulderCanvas.SetPixelAt(19,16, color);
}

void DrawWingFrame5()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.DrawRectangle(18, 8, 22, 10, color);
  RightShoulderCanvas.DrawRectangle(9, 15, 12, 17, color);
  RightShoulderCanvas.Fill(20,9,color);
  RightShoulderCanvas.Fill(10, 16, color);

  LeftShoulderCanvas.DrawRectangle(8,6, 10, 8, color);
  LeftShoulderCanvas.Fill(9,7, color);
  LeftShoulderCanvas.DrawRectangle(17,13, 18,15, color);
}

void DrawWingFrame6()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.DrawRectangle(12, 10, 14, 12, color);
  RightShoulderCanvas.Fill(13, 11, color);

  RightShoulderCanvas.DrawRectangle(9, 15, 12, 17, color);
  RightShoulderCanvas.Fill(11, 16, color);


  LeftShoulderCanvas.DrawRectangle(11,6, 13,14, color);
  LeftShoulderCanvas.Fill(12,7, color);
  LeftShoulderCanvas.DrawRectangle(10, 6, 12,12, color);
  LeftShoulderCanvas.Fill(11, 7, color);
}

void DrawWingFrame7()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.DrawRectangle(12, 10, 19, 15, color);
  RightShoulderCanvas.Fill(13, 11, color);

  RightShoulderCanvas.DrawRectangle(12, 12, 15, 17, color);
  RightShoulderCanvas.Fill(13, 14, color);



  LeftShoulderCanvas.DrawRectangle(13,6, 15, 12, color);
  LeftShoulderCanvas.Fill(14,7, color);
  LeftShoulderCanvas.DrawRectangle(13, 10, 17, 12, color);
  LeftShoulderCanvas.Fill(14, 11, color);
}

void DrawWingFrame8()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.DrawRectangle(16, 14, 20, 16, color);
  RightShoulderCanvas.Fill(17, 15, color);

  LeftShoulderCanvas.DrawRectangle(16,6, 20, 8, color);
  LeftShoulderCanvas.Fill(17,7, color);
}

void DrawWingFrame9()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.DrawLine(17,17, 17,20, color);

  LeftShoulderCanvas.DrawLine(16,2, 16,5, color);
}

void DrawWingFrame10()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.DrawLine(17,21, 19,21, color);

  LeftShoulderCanvas.DrawRectangle(15, 0, 18, 3, color);
  LeftShoulderCanvas.Fill(16, 2, color);
}

void DrawWingFrame11()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.SetPixelAt(19,21, color);

  LeftShoulderCanvas.SetPixelAt(17, 0, color);
  LeftShoulderCanvas.SetPixelAt(18, 0, color);
}

void DrawWingFrame12()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.DrawLine(17,17, 17,19, color);

  LeftShoulderCanvas.SetPixelAt(16, 2, color);
  LeftShoulderCanvas.SetPixelAt(16, 3, color);
}

void DrawWingFrame13()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.SetPixelAt(15,17,color);
  RightShoulderCanvas.SetPixelAt(19,15, color);
  RightShoulderCanvas.SetPixelAt(17,17,color);
  RightShoulderCanvas.SetPixelAt(17,18, color);

  LeftShoulderCanvas.DrawRectangle(17, 6, 19, 8, color);
  LeftShoulderCanvas.Fill(18, 7, color);
}

void DrawWingFrame14()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.DrawLine(17,16,19,10,color);
  RightShoulderCanvas.DrawRectangle(18,16,19,10,color);

  LeftShoulderCanvas.DrawLine(13, 6, 18, 10, color);
  LeftShoulderCanvas.DrawLine(13,6,17,10, color);
  LeftShoulderCanvas.DrawLine(13,5,17,10, color);
  LeftShoulderCanvas.DrawLine(13,6, 17, 8, color);

}

void DrawWingFrame15()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.DrawCircle(8, 22, 16, color);
  RightShoulderCanvas.DrawCircle(9, 22, 16, color);
  RightShoulderCanvas.DrawCircle(10, 22, 16, color);

  LeftShoulderCanvas.DrawCircle(8, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(9, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(10, 19,4, color);
}

void DrawWingFrame16()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.DrawCircle(10, 22, 16, color);
  RightShoulderCanvas.DrawCircle(11, 22, 16, color);
  RightShoulderCanvas.DrawCircle(12, 22, 16, color);

  LeftShoulderCanvas.DrawCircle(10, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(11, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(12, 19, 4, color);
}

void DrawWingFrame17()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.DrawCircle(12, 22, 16, color);
  RightShoulderCanvas.DrawCircle(13, 22, 16, color);
  RightShoulderCanvas.DrawCircle(14, 22, 16, color);

  LeftShoulderCanvas.DrawCircle(12, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(13, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(14, 19, 4, color);
}

void DrawWingFrame18()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.DrawCircle(14, 22, 16, color);
  RightShoulderCanvas.DrawCircle(15, 22, 16, color);
  RightShoulderCanvas.DrawCircle(16, 22, 16, color);

  LeftShoulderCanvas.DrawCircle(14, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(15, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(16, 19, 4, color);
}

void DrawWingFrame19()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.DrawCircle(16, 22, 16, color);
  RightShoulderCanvas.DrawCircle(17, 22, 16, color);
  RightShoulderCanvas.DrawCircle(18, 22, 16, color);
  RightShoulderCanvas.DrawCircle(19, 22, 16, color);
  RightShoulderCanvas.DrawCircle(20, 22, 16, color);
  RightShoulderCanvas.DrawCircle(21, 22, 16, color);
  RightShoulderCanvas.DrawCircle(22, 22, 16, color);
  RightShoulderCanvas.DrawRectangle(0,0, 4,5, color);
  RightShoulderCanvas.Fill(2,2, color);

  LeftShoulderCanvas.DrawCircle(16, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(17, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(18, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(19, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(20, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(21, 19, 4, color);
  LeftShoulderCanvas.DrawRectangle(0, 20, 8, 24, color);
  LeftShoulderCanvas.Fill(4, 22, color);
}

void DrawWingFrame20()
{
  uint32_t color = 0xFF0000;
  RightShoulderCanvas.DrawCircle(22, 22, 16, color);
  RightShoulderCanvas.DrawCircle(23, 22, 16, color);
  RightShoulderCanvas.DrawCircle(24, 22, 16, color);
  RightShoulderCanvas.DrawCircle(25, 22, 16, color);
  RightShoulderCanvas.DrawCircle(26, 22, 16, color);


  LeftShoulderCanvas.DrawCircle(22, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(23, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(24, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(25, 19, 4, color);
  LeftShoulderCanvas.DrawCircle(26, 19, 4, color);
}

void DrawWingsFrames()
{
  for(int i = 0; i < 20; i++)
  {
    if(i == 1)
    {
      DrawWingFrame1();
    }
    else if(i == 2)
    {
      DrawWingFrame2();
    }
    else if(i == 3)
    {
      DrawWingFrame3();
    }
    else if(i == 4)
    {
      DrawWingFrame4();
    }
    else if(i == 5)
    {
      DrawWingFrame5();
    }
    else if(i == 6)
    {
      DrawWingFrame6();
    }
    else if(i == 7)
    {
      DrawWingFrame7();
    }
    else if(i == 8)
    {
      DrawWingFrame8();
    }
    else if(i ==9)
    {
      DrawWingFrame9();
    }
    else if(i == 10)
    {
      DrawWingFrame10();
    }
    else if(i == 11)
    {
      DrawWingFrame11();
    }
    else if(i == 12)
    {
      DrawWingFrame12();
    }
    else if(i == 13)
    {
      DrawWingFrame13();
    }
    else if(i == 14)
    {
      DrawWingFrame14();
    }
     else if(i == 15)
    {
      DrawWingFrame15();
      delay(10);
    }
     else if(i == 16)
    {
      DrawWingFrame16();
      delay(20);
    }
     else if(i == 17)
    {
      DrawWingFrame17();
      delay(30);
    }
     else if(i == 18)
    {
      DrawWingFrame18();
      delay(30);
    }
     else if(i == 19)
    {
      DrawWingFrame19();
      delay(40);
    }
     else if(i == 20)
    {
      DrawWingFrame20();
      delay(30);
    }

    RightShoulderCanvas.MeanFilterByColor(3);
    LeftShoulderCanvas.MeanFilterByColor(3);
    drawPlasma2(masterFrame+=random(1,4));
    DrawAllMatrices();
    InitializeMatrices();

    delay(40);
  }
}

void DrawWingsShoulders()
{
  unsigned long lastMillis = millis();
  int armTrigger = 20;
  turnSignals = 1;

  Serial.println("BEGIN WINGS");
  
  for(int i = 5; i < 20; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      //LeftShoulderCanvas.DrawRectangle(j+i, 0, j+1+i, 10, Wheel(j*6));
      //RightShoulderCanvas.DrawRectangle(j+i, 13, j+1+i, 20, Wheel(j*6));

      LeftShoulderCanvas.DrawCircle(j+i-5, 15, 9, Wheel(j*6));
      RightShoulderCanvas.DrawCircle(j+i-5, 15, 13, Wheel(j*6));

    }

    LeftShoulderCanvas.MeanFilterByColor(3);
    RightShoulderCanvas.MeanFilterByColor(3);

    int loopVal = 0;

    if(i < 10)
      loopVal = 1;
    else if (i < 15)
      loopVal = 2;
    else
      loopVal = 3;

    for(int k = 0; k < loopVal; k++)
    {
      plasmaState = 0;
      //drawPlasma2(masterFrame+=random(1,4));
    
      DrawAllMatrices();
    }

    InitializeMatrices();
    //delay(20);

  Serial.print(millis() - lastMillis);
  lastMillis = millis();
  Serial.print(" ");
  Serial.print(i);
  Serial.print(" ");
    Serial.println("Drawing Wings");

  }

  for(int i = 20; i > 5; i--)
  {

    for(int j = 0; j < 5; j++)
    {
      //LeftShoulderCanvas.DrawRectangle(j+i, 0, j+1+i, 10, Wheel(j*6));
      //RightShoulderCanvas.DrawRectangle(j+i, 15, j+1+i, 20, Wheel(j*6));

      LeftShoulderCanvas.DrawCircle(j+i-5, 15, 9, Wheel(j*6));
      RightShoulderCanvas.DrawCircle(j+i-5, 15, 13, Wheel(j*6));
    }

    int loopVal = 0;

    if(i < 10)
      loopVal = 1;
    else if (i < 15)
      loopVal = 2;
    else
      loopVal = 3;

    for(int k = 0; k < loopVal; k++)
    {
      plasmaState = 0;
      //drawPlasma2(masterFrame+=random(1,4));
    
      DrawAllMatrices();
    }
    
    InitializeMatrices();
    //delay(20);

    Serial.print(millis() - lastMillis);
    Serial.print(" ");
    lastMillis = millis();
    Serial.print(i);
    Serial.print(" ");
    Serial.println("Drawing Wings");
  }

  turnSignals = 0;
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

void StopLightNewShoulders(bool increment = true)
{

  for(int i = 0; i < 10; i++)
  {
    if(increment) 
      IncrementBrightness();
    else 
      DecrementBrightness();

    int glowLevel = map(i, 0, 10, 0, 0xFF);

    int colorValue = glowLevel << 16;
    colorValue = colorValue & 0xFF0000;

    LeftShoulderCanvas.Fill(5, 5, colorValue);
    RightShoulderCanvas.Fill(5,5, colorValue);

    plasmaState = 1;
    drawPlasma2(masterFrame+=random(1,4));


    DrawAllMatrices();

    InitializeMatrices();
  }

  unsigned long startTime = millis();

  while(millis() - startTime < 4000)
  {
    if(increment) 
      IncrementBrightness();
    else 
      DecrementBrightness();

    int colorValue = 0xFF << 16;
    colorValue = colorValue & 0xFF0000;

    LeftShoulderCanvas.Fill(5, 5, colorValue);
    RightShoulderCanvas.Fill(5,5, colorValue);

    plasmaState = 1;
    drawPlasma2(masterFrame+=random(1,4));

    DrawAllMatrices();

    InitializeMatrices();
  }

  for(int i = 0; i < 10; i++)
  {

    if(increment) 
      IncrementBrightness();
    else 
      DecrementBrightness();
    
    int glowLevel = map(i, 10, 0, 0, 0xFF);

    int colorValue = glowLevel << 16;
    colorValue = colorValue & 0xFF0000;

    LeftShoulderCanvas.Fill(5, 5, colorValue);
    RightShoulderCanvas.Fill(5,5, colorValue);

    plasmaState = 1;
    drawPlasma2(masterFrame+=random(1,4));

    DrawAllMatrices();

    InitializeMatrices();
  }
}

void StopLight(bool increment = true)
{

  for(int i = 0; i < 10; i++)
  {
    int glowLevel = map(i, 0, 10, 0, 0x11);

    int colorValue = glowLevel << 16;
    colorValue = colorValue & 0xFF0000;

    Serial.println(glowLevel);

    if(increment) 
      IncrementBrightness();
    else 
      DecrementBrightness();

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
    LeftShoulderCanvas.Fill(5, 5, colorValue);
    RightShoulderCanvas.Fill(5,5, colorValue);

    DrawAllMatrices();

    InitializeMatrices();
  }

  delay(1000);

  for(int i = 0; i < 10; i++)
  {
    int glowLevel = map(i, 10, 0, 0, 0x11);

    int colorValue = glowLevel << 16;
    colorValue = colorValue & 0xFF0000;

    Serial.println(glowLevel);

    if(increment) 
      IncrementBrightness();
    else 
      DecrementBrightness();

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
    LeftShoulderCanvas.Fill(5, 5, colorValue);
    RightShoulderCanvas.Fill(5,5, colorValue);

    DrawAllMatrices();

    InitializeMatrices();
  }

  
}




void loop() {

  Serial.println("1");
  InitializeMatrices();
  for(int i = 0; i < 20; i++)
  {
    TurnRightNewShoulders();
  }
  Serial.println("2");
  InitializeMatrices();
  for(int i = 0; i < 20; i++)
  {
    TurnLeftNewShoulders();
  }
  
  StopLight();  
  Serial.println("3");
  InitializeMatrices();
  for(int i = 0; i < 20; i++)
  {
    TurnRightNewShoulders();
  }
  Serial.println("4");
  InitializeMatrices();
  for(int i = 0; i < 20; i++)
  {
    TurnLeftNewShoulders();
  }
  
  StopLight();  
Serial.println("5");
  InitializeMatrices();
  for(int i = 0; i < 20; i++)
  {
    TurnRightNewShoulders();
  }
  Serial.println("6");
  InitializeMatrices();
  for(int i = 0; i < 20; i++)
  {
    TurnLeftNewShoulders();
  }
  
  StopLight();  



  //SetJacketOff();
//
  //delay(5000);
//
  //SetJacketOn();
//
  //delay(5000);
  
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

