
#ifndef SERVER_CLIENT
#define SERVER_CLIENT

#include <arduino.h>
#include <Adafruit_NeoPixel.h>
#include "LEDPattern.h"

enum COMMAND {
  NO_COMMAND,
  NEW_PATTERN
};


class ServerClient {
  public:

  private:
  public:
    Adafruit_NeoPixel& neoPixels;
    bool doneOnce = false;

    LEDPattern& pattern;  

    ServerClient(Adafruit_NeoPixel& _neoPixels, LEDPattern& _pattern);

    void init();

    COMMAND getCommand();
    int receivePattern(int& patternSlot, LEDPattern **newPattern);
};

#endif
