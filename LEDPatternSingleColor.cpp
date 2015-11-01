#include "LEDPatternSingleColor.h"
#include <string.h>
#include <Adafruit_NeoPixel.h>
#include "util.h"

LEDPatternSingleColor::LEDPatternSingleColor(const char *_name, const uint32_t _color) : LEDPattern(_name), color(_color) {}

void LEDPatternSingleColor::describe() {
  LEDPattern::describe();
  Serial.print("Solid color: ");
  SerialPrintColor(color);
}


void LEDPatternSingleColor::loop(Adafruit_NeoPixel& neoPixels) {
  for(int i=0;i<PatternLength;i++)
    neoPixels.setPixelColor(i, color);
  neoPixels.show();
}


