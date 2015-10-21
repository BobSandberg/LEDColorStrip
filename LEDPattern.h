//namespace LEDColorStrip {

#include <Adafruit_NeoPixel.h>

const int MaxNameSize = 20;
const int PatternLength = 10;

class LEDPattern {
  public:
    char name[MaxNameSize];
    uint32_t pixels[PatternLength];

    LEDPattern(const char *_name, const uint32_t *_pixels, int n);
};

//}

