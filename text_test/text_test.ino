/***************************************************
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#include "Adafruit_EPD.h"
#include <Adafruit_GFX.h> // Core graphics library

#ifdef ARDUINO_ADAFRUIT_FEATHER_RP2040_THINKINK // detects if compiling for
                                                // Feather RP2040 ThinkInk
#define EPD_DC PIN_EPD_DC       // ThinkInk 24-pin connector DC
#define EPD_CS PIN_EPD_CS       // ThinkInk 24-pin connector CS
#define EPD_BUSY PIN_EPD_BUSY   // ThinkInk 24-pin connector Busy
#define SRAM_CS -1              // use onboard RAM
#define EPD_RESET PIN_EPD_RESET // ThinkInk 24-pin connector Reset
#define EPD_SPI &SPI1           // secondary SPI for ThinkInk
#else
#define EPD_DC 10
#define EPD_CS 9
#define EPD_BUSY -1 // can set to -1 to not use a pin (will wait a fixed delay)
#define SRAM_CS 6
#define EPD_RESET -1  // can set to -1 and share with microcontroller Reset!
#define EPD_SPI &SPI // primary SPI
#endif

/* Uncomment the following line if you are using 2.9" EPD */
Adafruit_IL0373 display(296, 128, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY, EPD_SPI); 

void setup(void) {
  Serial.begin(115200);
  Serial.println("Hello! EPD Test");

  display.begin();

  Serial.println("Initialized");

  display.setRotation(2);

  // large block of text
  display.clearBuffer();
  display.setTextWrap(true);

  display.setCursor(0, 0);
  display.setTextSize(3);
  display.setTextColor(EPD_BLACK);
  display.print(
      "SHILPAa");
  Serial.println("Printed! for tim");

  // display.setCursor(50, 70);
  // display.setTextColor(EPD_RED);
  // display.print("YESYES");

  display.display();
}

void loop() {
  // do nothing 
  delay(500); 
  }