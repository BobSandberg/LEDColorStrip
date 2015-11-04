#ifndef UTIL
#define UTIL

#include <Adafruit_NeoPixel.h>

void SerialPrintColor(uint32_t color);
void showPixels(const char* label, const uint32_t* pixels, int len);


#endif

