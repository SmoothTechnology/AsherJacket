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

MatrixDraw LeftArmBackCanvas            (xSizeLeftArmBack, ySizeLeftArmBack, 3);
MatrixDraw LeftArmFrontPartTwoCanvas    (xSizeLeftArmPartTwo, ySizeLeftArmPartTwo, 3);
MatrixDraw LeftArmFrontPartOneCanvas    (xSizeLeftArmFrontPartOne, ySizeLeftArmFrontPartOne, 3);
MatrixDraw LeftBackCanvas               (xSizeLeftBack, ySizeLeftBack, 3);
MatrixDraw LeftChestCanvas              (xSizeLeftChest, ySizeLeftChest, 3);
MatrixDraw RightArmBackCanvas           (xSizeRightArmBack, ySizeRightArmBack, 3);
MatrixDraw RightArmFrontPartOneCanvas   (xSizeRightArmPartOne, ySizeRightArmPartOne, 3);
MatrixDraw RightArmFrontPartTwoCanvas   (xSizeRightArmPartTwo, ySizeRightArmPartTwo, 3);
MatrixDraw RightBackCanvas              (xSizeRightBack, ySizeRightBack, 3);
MatrixDraw RightChestCanvas             (xSizeRightChest, ySizeRightChest, 3);

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
      RightArmBackCanvas.DrawRectangle(rightArmBackPos - 5, 0, rightArmBackPos, ySizeRightArmBack-1, 0xFF0000);
      RightArmBackCanvas.Fill(rightArmBackPos-2, ySizeRightArmBack/2, 0xFF0000);

      int rightArmFrontPartTwoPos = map(i, armTrigger, 0, 5, xSizeRightArmPartTwo-1);
      RightArmFrontPartTwoCanvas.DrawRectangle(rightArmFrontPartTwoPos-5, 0, rightArmFrontPartTwoPos-1, ySizeRightArmPartTwo-1, 0xFF0000);
      RightArmFrontPartTwoCanvas.Fill(rightArmFrontPartTwoPos-2, ySizeRightArmPartTwo/2, 0xFF0000);

      int rightArmFrontPartOnePos = map(i, armTrigger, 0, 5, xSizeRightArmPartOne-1);
      RightArmFrontPartOneCanvas.DrawRectangle(rightArmFrontPartOnePos-5, 0, rightArmFrontPartOnePos-1, ySizeRightArmPartOne-1, 0xFF0000);
      RightArmFrontPartOneCanvas.Fill(rightArmFrontPartOnePos-2, ySizeRightArmPartOne/2, 0xFF0000);


      // Left Arms
      int leftArmBackPos = map(i, armTrigger, 0, 5, xSizeLeftArmBack-1);
      LeftArmBackCanvas.DrawRectangle(leftArmBackPos - 5, 0, leftArmBackPos, ySizeLeftArmBack-1, 0xFF0000);
      LeftArmBackCanvas.Fill(leftArmBackPos-2, ySizeLeftArmBack/2, 0xFF0000);

      int leftArmFrontPartTwoPos = map(i, armTrigger, 0, 5, xSizeLeftArmPartTwo-1);
      LeftArmFrontPartTwoCanvas.DrawRectangle(leftArmFrontPartTwoPos-5, 0, leftArmFrontPartTwoPos-1, ySizeLeftArmPartTwo-1, 0xFF0000);
      LeftArmFrontPartTwoCanvas.Fill(leftArmFrontPartTwoPos-2, ySizeLeftArmPartTwo/2, 0xFF0000);

      int leftArmFrontPartOnePos = map(i, armTrigger, 0, 5, xSizeLeftArmFrontPartOne-1);
      LeftArmFrontPartOneCanvas.DrawRectangle(leftArmFrontPartOnePos-5, 0, leftArmFrontPartOnePos-1, ySizeLeftArmFrontPartOne-1, 0xFF0000);
      LeftArmFrontPartOneCanvas.Fill(leftArmFrontPartOnePos-2, ySizeLeftArmFrontPartOne/2, 0xFF0000);
    }


    DrawAllMatrices();
    RightChestCanvas.ClearMatrix();
    LeftChestCanvas.ClearMatrix();
    RightArmFrontPartOneCanvas.ClearMatrix();
    RightArmFrontPartTwoCanvas.ClearMatrix();
    RightArmBackCanvas.ClearMatrix();
    LeftArmBackCanvas.ClearMatrix();
    LeftArmFrontPartTwoCanvas.ClearMatrix();
    LeftArmFrontPartOneCanvas.ClearMatrix();

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
      LeftArmBackCanvas.DrawRectangle(leftArmBackPos - 5, 0, leftArmBackPos, ySizeLeftArmBack-1, 0xFF0000);
      LeftArmBackCanvas.Fill(leftArmBackPos-2, ySizeLeftArmBack/2, 0xFF0000);

      int leftArmFrontPartTwoPos = map(i, armTrigger, 0, 5, xSizeLeftArmPartTwo-1);
      LeftArmFrontPartTwoCanvas.DrawRectangle(leftArmFrontPartTwoPos-5, 0, leftArmFrontPartTwoPos-1, ySizeLeftArmPartTwo-1, 0xFF0000);
      LeftArmFrontPartTwoCanvas.Fill(leftArmFrontPartTwoPos-2, ySizeLeftArmPartTwo/2, 0xFF0000);

      int leftArmFrontPartOnePos = map(i, armTrigger, 0, 5, xSizeLeftArmFrontPartOne-1);
      LeftArmFrontPartOneCanvas.DrawRectangle(leftArmFrontPartOnePos-5, 0, leftArmFrontPartOnePos-1, ySizeLeftArmFrontPartOne-1, 0xFF0000);
      LeftArmFrontPartOneCanvas.Fill(leftArmFrontPartOnePos-2, ySizeLeftArmFrontPartOne/2, 0xFF0000);
    }

    DrawAllMatrices();
    LeftChestCanvas.ClearMatrix();
    LeftArmBackCanvas.ClearMatrix();
    LeftArmFrontPartTwoCanvas.ClearMatrix();
    LeftArmFrontPartOneCanvas.ClearMatrix();

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
      RightArmBackCanvas.DrawRectangle(rightArmBackPos - 5, 0, rightArmBackPos, ySizeRightArmBack-1, 0xFF0000);
      RightArmBackCanvas.Fill(rightArmBackPos-2, ySizeRightArmBack/2, 0xFF0000);

      int rightArmFrontPartTwoPos = map(i, armTrigger, 0, 5, xSizeRightArmPartTwo-1);
      RightArmFrontPartTwoCanvas.DrawRectangle(rightArmFrontPartTwoPos-5, 0, rightArmFrontPartTwoPos-1, ySizeRightArmPartTwo-1, 0xFF0000);
      RightArmFrontPartTwoCanvas.Fill(rightArmFrontPartTwoPos-2, ySizeRightArmPartTwo/2, 0xFF0000);

      int rightArmFrontPartOnePos = map(i, armTrigger, 0, 5, xSizeRightArmPartOne-1);
      RightArmFrontPartOneCanvas.DrawRectangle(rightArmFrontPartOnePos-5, 0, rightArmFrontPartOnePos-1, ySizeRightArmPartOne-1, 0xFF0000);
      RightArmFrontPartOneCanvas.Fill(rightArmFrontPartOnePos-2, ySizeRightArmPartOne/2, 0xFF0000);
    }

    DrawAllMatrices();
    RightChestCanvas.ClearMatrix();
    RightArmFrontPartOneCanvas.ClearMatrix();
    RightArmFrontPartTwoCanvas.ClearMatrix();
    RightArmBackCanvas.ClearMatrix();

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

    //RightBackCanvas.Fill(30, 5, 0xFF0000);
    LeftBackCanvas.MeanFilter(3);
    RightBackCanvas.MeanFilter(3);
    //RightBackCanvas.Fill(5,5, 0xAA00AA);
    //RightBackCanvas.Fill(5, 5, 0xFF00FF);
    
    //LeftBackCanvas.DrawLine(xSizeLeftBack/2, 0, i, i, 0x00FF00);
    DrawAllMatrices();
    RightBackCanvas.ClearMatrix();
    LeftBackCanvas.ClearMatrix();
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

    //RightBackCanvas.Fill(30, 5, 0xFF0000);
    LeftBackCanvas.MeanFilter(3);
    RightBackCanvas.MeanFilter(3);
    //RightBackCanvas.Fill(5, 5, 0xFF00FF);
    
    //LeftBackCanvas.DrawLine(xSizeLeftBack/2, 0, i, i, 0x00FF00);
    DrawAllMatrices();
    RightBackCanvas.ClearMatrix();
    LeftBackCanvas.ClearMatrix();
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
  LeftArmBackCanvas.Fill(5, 5, 0x110000);      
  LeftArmFrontPartTwoCanvas.Fill(5, 5, 0x110000);  
  LeftArmFrontPartOneCanvas.Fill(5, 5, 0x110000);   
  LeftBackCanvas.Fill(5, 5, 0x110000);              
  LeftChestCanvas.Fill(5, 5, 0x110000);             
  RightArmBackCanvas.Fill(5, 5, 0x110000);          
  RightArmFrontPartOneCanvas.Fill(5, 5, 0x110000);  
  RightArmFrontPartTwoCanvas.Fill(5, 5, 0x110000);  
  RightBackCanvas.Fill(5, 5, 0x110000);             
  RightChestCanvas.Fill(5, 5, 0x110000);

  DrawAllMatrices();
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

  for(int i = 0; i < 4; i++)
  {
    CenterOut();
  }
  InitializeMatrices();

  for(int i = 0; i < 4; i++)
  {
    TurnRight();
  }
  InitializeMatrices();

  for(int i = 0; i < 4; i++)
  {
    TurnLeft();
  }
  InitializeMatrices();

  for(int i = 0; i < 4; i++)
  {
    DrawWings();
  }
  InitializeMatrices();

  StopLight();
  delay(2000);
  InitializeMatrices();
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

