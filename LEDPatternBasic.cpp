#include "LEDPatternBasic.h"
#include <string.h>
#include <Adafruit_NeoPixel.h>
#include "util.h"

LEDPatternBasic::LEDPatternBasic(const char *_name, const uint32_t _pixels[], int n, int startingShift) : LEDPattern(_name), shift(startingShift) {
  patternLen = (n>PatternLength) ? PatternLength : n;
  memcpy((char *)pixels, (char *)_pixels, patternLen * sizeof(uint32_t)); 
}

void LEDPatternBasic::describe() {
  LEDPattern::describe();
  showPixels("Pattern Pixels:", pixels, patternLen);
}

void LEDPatternBasic::loop(Adafruit_NeoPixel& neoPixels) {
  if (shift >= (patternLen-1)) shift = 0; 
  else shift++;
  Serial.print("Shift at "); Serial.println(shift);
  for(int iPix=0;iPix<patternLen;iPix++)
    neoPixels.setPixelColor(iPix, pixels[(iPix + shift) % patternLen]);
  neoPixels.show();
}

