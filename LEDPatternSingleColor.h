#include "LEDPattern.h"

#ifndef LED_PATTERN_SINGLE_COLOR
#define LED_PATTERN_SINGLE_COLOR

class LEDPatternSingleColor : public LEDPattern  {
  private:

  public:
    uint32_t color;

    LEDPatternSingleColor(const char *_name, const uint32_t _color);

    void describe();
    
    void loop(Adafruit_NeoPixel& neoPixels);
};

#endif
