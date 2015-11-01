#include "LEDPattern.h"

#ifndef LED_PATTERN_COLOR_TOGGLE
#define LED_PATTERN_COLOR_TOGGLE

class LEDPatternColorToggle : public LEDPattern {
  private:
  int colorSelection = 0;
  uint32_t selectedColor = colors[colorSelection];
  
  public:
    const uint32_t *colors;
    const int numColors;
    const long interPixelDelay;

    LEDPatternColorToggle(const char *_name, const uint32_t *_colors, int _numColor, long _interPixelDelay);

    void describe();

    void toggle();

    void loop(Adafruit_NeoPixel& neoPixels);
};

#endif

