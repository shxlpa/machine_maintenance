/***************************************************
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#include "Adafruit_ThinkInk.h"
#include "SPI.h"

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

// 2.9" Tricolor Featherwing or Breakout with IL0373 chipset
ThinkInk_290_Tricolor_Z10 display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY, EPD_SPI);
// 2.9" Tricolor Featherwing or Breakout with UC8151D chipset
// ThinkInk_290_Tricolor_Z13 display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS,
// EPD_BUSY, EPD_SPI);
// 2.9" Tricolor Featherwing or Breakout with SSD1680 chipset and negative
// offset
// ThinkInk_290_Tricolor_Z94 display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS,
// EPD_BUSY, EPD_SPI);

// ThinkInk_420_Tricolor_RW display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS,
// EPD_BUSY, EPD_SPI); ThinkInk_420_Tricolor_Z21 display(EPD_DC, EPD_RESET,
// EPD_CS, SRAM_CS, EPD_BUSY, EPD_SPI);

void setup() {
  SPI.begin();
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }
  Serial.println("Adafruit EPD full update test in red/black/white");
  display.begin(THINKINK_TRICOLOR);
}

void loop() {
    Serial.println("Banner demo");
    display.clearBuffer();
    display.setTextSize(3);
    display.setCursor((display.width() - 144) / 2, (display.height() - 24) / 2);
    display.setTextColor(EPD_BLACK);
    display.print("TES");
    display.setTextColor(EPD_RED);
    display.print("COLLR");
    display.display();

    delay(15000);

    Serial.println("Color rectangle demo");
    display.clearBuffer();
    display.fillRect(display.width() / 3, 0, display.width() / 3,
                    display.height(), EPD_BLACK);
    display.fillRect((display.width() * 2) / 3, 0, display.width() / 3,
                    display.height(), EPD_RED);
    display.display();

    delay(15000);

    Serial.println("Text demo");
    // large block of text
    display.clearBuffer();
    display.setTextSize(1);
    testdrawtext(
        "THIS IS A TEST",
        EPD_WHITE);
    display.display();

    delay(15000);
}

void testdrawtext(const char *text, uint16_t color) {
  display.setCursor(0, 0);
  display.setTextColor(color);
  display.setTextWrap(true);
  display.print(text);
}
