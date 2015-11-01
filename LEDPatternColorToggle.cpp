#include "LEDPatternColorToggle.h"
#include <string.h>
#include <Adafruit_NeoPixel.h>
#include "util.h"



LEDPatternColorToggle::LEDPatternColorToggle(const char *_name, const uint32_t *_colors, int _numColors, long _interPixelDelay) : 
  LEDPattern(name), colors(_colors), numColors(_numColors), interPixelDelay(_interPixelDelay) {}

void LEDPatternColorToggle::describe() {
  LEDPattern::describe();
  showPixels("Toggle Colors: ", colors, numColors);
}

void LEDPatternColorToggle::loop(Adafruit_NeoPixel& neoPixels) {
  for(int i=0;i<PatternLength;i++) {
    neoPixels.setPixelColor(i, selectedColor);
    delay(interPixelDelay);
    neoPixels.show();
  }
}

void LEDPatternColorToggle::toggle() {
  colorSelection = (colorSelection+1) % numColors; 
  selectedColor = colors[colorSelection];
}

