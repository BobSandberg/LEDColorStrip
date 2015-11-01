//namespace LEDColorStrip {

#include <arduino.h>
#include <Adafruit_NeoPixel.h>

#ifndef LED_PATTERN
#define LED_PATTERN

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

//class LEDPatternSingleColor {
//  private:
//
//  public:
//    char name[MaxNameSize];
//    uint32_t color;
//
//    LEDPatternSingleColor(const char *_name, const uint32_t _color);
//
//    void loop(Adafruit_NeoPixel& neoPixels);
//};

//class LEDPatternColorToggle {
//  private:
//  int colorSelection = 0;
//  uint32_t selectedColor = colors[colorSelection];
//  
//  public:
//    char name[MaxNameSize];
//    const uint32_t *colors;
//    const int numColors;
//
//    LEDPatternColorToggle(const char *_name, const uint32_t *_colors, int _numColor);
//
//    void toggle();
//
//    void loop(Adafruit_NeoPixel& neoPixels);
//};


//}

#endif

