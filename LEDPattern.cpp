//namespace LEDColorStrip {
#include "LEDPattern.h"
#include <string.h>

LEDPattern::LEDPattern(const char *_name, const uint32_t *_pixels, int n) {
  strncpy( name, _name, MaxNameSize);
  memcpy((char *)pixels, (char *)_pixels, (n>PatternLength) ? PatternLength : n); 
}

//}

