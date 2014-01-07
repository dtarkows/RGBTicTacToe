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

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

void setup() {

  matrix.begin();

}

void loop() {

  // Draw a red line for the first horizontal line
  matrix.drawLine(0, 10, 31, 10, matrix.Color333(7, 0, 0));
  // Draw a green line for the second horizontal line
  matrix.drawLine(0, 21, 31, 21, matrix.Color333(0, 7, 0));
  // Draw a blue line for the first vertical line
  matrix.drawLine(10, 0, 10, 31, matrix.Color333(0, 0, 7));
  // Draw a purple line for the second vertical line
  matrix.drawLine(21, 0, 21, 31, matrix.Color333(7, 0, 7));

  drawO();
}

void drawX(uint8_t boxNum, uint16_t color) {
  uint8_t boxWidth = 9;
  uint8_t startX = (boxWidth+2) * (boxNum%3);
  uint8_t startY = (boxWidth+2) * (boxNum/3);

  matrix.drawLine(startX, startY, startX+boxWidth, startY+boxWidth, color);
  matrix.drawLine(startX, startY+boxWidth, startX+boxWidth, startY, color);
}

void drawO(void) {
  
  uint8_t boxWidth = 9;
  uint8_t radius = 4;
  uint8_t startX = 5;
  uint8_t startY = 5;

  matrix.drawCircle(startX, startY, radius, matrix.Color333(7,7,7));
  
}




