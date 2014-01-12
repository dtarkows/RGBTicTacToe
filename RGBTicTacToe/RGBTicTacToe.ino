// Based on the testshapes demo for Adafruit's 32x32 RGB LED matrix:
// http://www.adafruit.com/products/607

// Original example written by Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

// If your 32x32 matrix has the SINGLE HEADER input,
// use this pinout:
#define CLK 8  // MUST be on PORTB!
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

#define MOVE_PIN 11

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

void setup() {

  pinMode(MOVE_PIN, INPUT_PULLUP);
  matrix.begin();
  drawBoard();
  drawX(0, matrix.Color333(7,7,7));  
}

uint8_t curBox = 0;
uint16_t lastReadTime = 0;
const uint8_t moveDelay = 100;
int moveVal = HIGH;

void loop() {

  drawBoard();
  
  uint16_t curTime = millis();
  
  if (curTime > (lastReadTime + moveDelay)) {
    int val = digitalRead(MOVE_PIN);
    
    if ( (val != moveVal) && (val == LOW) ) {
      drawX(curBox, matrix.Color333(0,0,0));
      curBox = (curBox + 1) % 9;
      drawX(curBox, matrix.Color333(7,7,7));
    }
    
    moveVal = val;
    lastReadTime = curTime;
  } 
}

void drawBoard(void) {
  // Draw a red line for the first horizontal line
  matrix.drawLine(0, 10, 20, 10, matrix.Color333(7, 0, 0));
  matrix.drawLine(22, 10, 31, 10, matrix.Color333(7, 0, 0));
  
  // Draw a green line for the second horizontal line
  matrix.drawLine(0, 21, 9, 21, matrix.Color333(0, 7, 0));
  matrix.drawLine(11, 21, 31, 21, matrix.Color333(0, 7, 0));
  
  // Draw a blue line for the first vertical line
  matrix.drawLine(10, 0, 10, 9, matrix.Color333(0, 0, 7));
  matrix.drawLine(10, 11, 10, 31, matrix.Color333(0, 0, 7));

  // Draw a purple line for the second vertical line
  matrix.drawLine(21, 0, 21, 20, matrix.Color333(7, 0, 7));
  matrix.drawLine(21, 22, 21, 31, matrix.Color333(7, 0, 7));
}
void drawX(uint8_t boxNum, uint16_t color) {
  const uint8_t boxWidth = 9;
  uint8_t startX = (boxWidth+2) * (boxNum%3);
  uint8_t startY = (boxWidth+2) * (boxNum/3);

  matrix.drawLine(startX, startY, startX+boxWidth, startY+boxWidth, color);
  matrix.drawLine(startX, startY+boxWidth, startX+boxWidth, startY, color);
}

void drawO(uint8_t boxNum, uint16_t color) {

  const uint8_t boxWidth = 9;
  uint8_t radius = 4;
  uint8_t startX = 5 + (boxWidth+2) * (boxNum%3);
  uint8_t startY = 5 + (boxWidth+2) * (boxNum/3);

  matrix.drawCircle(startX, startY, radius, color);

}





