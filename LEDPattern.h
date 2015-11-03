//namespace LEDColorStrip {

#ifndef LED_PATTERN
#define LED_PATTERN

#include <arduino.h>
#include <Adafruit_NeoPixel.h>

const int PatternLength = 10;

class LEDPattern {
  public:
    const static int MaxNameSize = 20;

  private:

  public:
    char name[MaxNameSize];

    LEDPattern(const char *_name);

    virtual void describe();
        
    virtual void loop(Adafruit_NeoPixel& pixels) = 0;
};



#endif

