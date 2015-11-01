#include "LEDPattern.h"

#ifndef LED_PATTERN_BASIC
#define LED_PATTERN_BASIC

class LEDPatternBasic : public LEDPattern {
  private:
    int shift;

  public:
    int patternLen;
    uint32_t pixels[PatternLength];

    LEDPatternBasic(const char *_name, const uint32_t _pixels[], int n, int startingShift);

    void describe();
    
    void loop(Adafruit_NeoPixel& pixels);
};

#endif
