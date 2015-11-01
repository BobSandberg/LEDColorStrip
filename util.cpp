#include <Adafruit_NeoPixel.h>
#include <arduino.h>


void SerialPrintColor(uint32_t color) {
  uint32_t r = color & 0xFF;
  uint32_t g = (color >> 8) & 0xFF;
  uint32_t b = (color >> 16) & 0xFF;
  Serial.print("(");
  Serial.print(b);
  Serial.print(",");
  Serial.print(g);
  Serial.print(",");
  Serial.print(r);
  Serial.print(")");
}

void showPixels(const char* label, const uint32_t* pixels, int len) {
  Serial.println(label);
  for( int i = 0; i<len; i++) {
    Serial.print("\t\t"); Serial.print(i); Serial.print(". "); SerialPrintColor(pixels[i]); Serial.println(); // Serial.println(pixels[0]); 
  }
}
  

