
#ifndef BUTTON_TRIGGER
#define BUTTON_TRIGGER

#include <arduino.h>
#include <Adafruit_NeoPixel.h>


class ButtonTrigger {
  public:

  private:
  public:
    int buttonPin;
    bool lastState = HIGH;
    
    ButtonTrigger(int _pin);

    void init();

    int check();
};


#endif


