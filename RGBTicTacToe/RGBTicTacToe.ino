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

  drawX();

}

void drawX(void) {
  uint8_t startX = 0;
  uint8_t startY = 0;
  uint8_t boxWidth = 9;
  
  matrix.drawLine(startX, startY, startX+boxWidth, startY+boxWidth, matrix.Color333(7,7,7));
  matrix.drawLine(startX, startY+boxWidth, startX+boxWidth, startY, matrix.Color333(7,7,7));
  
  startX = startX + boxWidth+2;
  matrix.drawLine(startX, startY, startX+boxWidth, startY+boxWidth, matrix.Color333(7,7,7));
  matrix.drawLine(startX, startY+boxWidth, startX+boxWidth, startY, matrix.Color333(7,7,7));
  
  startX = startX + boxWidth+2;
  matrix.drawLine(startX, startY, startX+boxWidth, startY+boxWidth, matrix.Color333(7,7,7));
  matrix.drawLine(startX, startY+boxWidth, startX+boxWidth, startY, matrix.Color333(7,7,7));
}

