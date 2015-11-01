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


//
//LEDPatternSingleColor::LEDPatternSingleColor(const char *_name, const uint32_t _color) : color(_color) {
//  strncpy( name, _name, MaxNameSize);
//}
//
//void LEDPatternSingleColor::loop(Adafruit_NeoPixel& neoPixels) {
//  for(int i=0;i<PatternLength;i++)
//    neoPixels.setPixelColor(i, color);
//  neoPixels.show();
//}
//
//
//LEDPatternColorToggle::LEDPatternColorToggle(const char *_name, const uint32_t *_colors, int _numColors) : colors(_colors), numColors(_numColors) {
//  strncpy(name, _name, MaxNameSize);
//}
//
//void LEDPatternColorToggle::loop(Adafruit_NeoPixel& neoPixels) {
//  for(int i=0;i<PatternLength;i++) {
//    neoPixels.setPixelColor(i, selectedColor);
//    delay(20);
//    neoPixels.show();
//  }
//}
//
//void LEDPatternColorToggle::toggle() {
//  colorSelection = (colorSelection+1) % numColors; 
//  selectedColor = colors[colorSelection];
////  Serial.print("Toggle Color to "); 
////  Serial.print(colorSelection);
////  Serial.print(" - ");
////  Serial.println(selectedColor);
//}

//}

