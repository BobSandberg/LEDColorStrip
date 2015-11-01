//namespace LEDColorStrip {
#include "LEDPattern.h"
#include <string.h>
#include <Adafruit_NeoPixel.h>
//#include "arduino.h"
#include "util.h"


LEDPattern::LEDPattern(const char *_name) {
  strncpy( name, _name, MaxNameSize);
}


void LEDPattern::describe() {
  Serial.print("Pattern: "); Serial.println(name);
}



//}

