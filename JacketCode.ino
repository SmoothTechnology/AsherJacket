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
}

void DrawLeftArmBackMatrix()
{
  for(int i = minLEDLeftArmBack; i < maxLEDLeftArmBack; i++)
  {
    LEDPos curPos = LeftArmBackMap[i - minLEDLeftArmBack];
    int value = LeftArmBackCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawLeftArmFrontPartTwoMatrix()
{
  for(int i = minLEDLeftArmPartTwo; i < maxLEDLeftArmPartTwo; i++)
  {
    LEDPos curPos = LeftArmPartTwoMap[i - minLEDLeftArmPartTwo];
    int value = LeftArmFrontPartTwoCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawLeftArmFrontPartOneMatrix()
{
  for(int i = minLEDLeftArmFrontPartOne; i < maxLEDLeftArmFrontPartOne; i++)
  {
    LEDPos curPos = LeftArmPartOneMap[i - minLEDLeftArmFrontPartOne];
    int value = LeftArmFrontPartOneCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawLeftBackMatrix()
{
  for(int i = minLEDLeftBack; i < maxLEDLeftBack; i++)
  {
    LEDPos curPos = LeftBackMap[i - minLEDLeftBack];
    int value = LeftBackCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawLeftChestMatrix()
{

  for(int i = minLEDLeftChest; i < maxLEDLeftChest; i++)
  {
    LEDPos curPos = LeftChestMap[i - minLEDLeftChest];
    int value = LeftChestCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawRightArmBackMatrix()
{
  for(int i = minLEDRightArmBack; i < maxLEDRightArmBack; i++)
  {
    LEDPos curPos = RightArmBackMap[i - minLEDRightArmBack];
    int value = RightArmBackCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawRightArmFrontPartOneMatrix()
{
  for(int i = minLEDRightArmPartOne; i < maxLEDRightArmPartOne; i++)
  {
    LEDPos curPos = RightArmPartOneMap[i - minLEDRightArmPartOne];
    int value = RightArmFrontPartOneCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawRightArmFrontPartTwoMatrix()
{
  for(int i = minLEDRightArmPartTwo; i < maxLEDRightArmPartTwo; i++)
  {
    LEDPos curPos = RightArmPartTwoMap[i - minLEDRightArmPartTwo];
    int value = RightArmFrontPartTwoCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawRightBackMatrix()
{
  for(int i = minLEDRightBack; i < maxLEDRightBack; i++)
  {
    LEDPos curPos = RightBackMap[i - minLEDRightBack];
    int value = RightBackCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawRightChestMatrix()
{
  for(int i = minLEDRightChest; i < maxLEDRightChest; i++)
  {
    LEDPos curPos = RightChestMap[i - minLEDRightChest];
    int value = RightChestCanvas.GetValueAt(curPos.x, curPos.y);
    leds.setPixel(i, value);
  }
}

void DrawAllMatrices()
{
  delay(10);
  Serial.println("Start Drawing");
  delay(10);

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

  delay(10);
  Serial.println("About to show");
  delay(10);

  leds.show();

  delay(10);
  Serial.println("Done Showing");
  delay(10);
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



  DrawAllMatrices();
  Serial.println("Good to go");
  delay(1000);

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
