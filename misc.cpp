//
//long cntr = 0;
//enum Direction { GOING_UP, GOING_DOWN };
//Direction dir = GOING_UP;

//
//const long colRange = 256;
//
//const long colBegining = 0; 
//const long redBegin = colBegining;
//const long redEnd = redBegin + colRange - 1;
//const long greenBegin = redEnd + 1;
//const long greenEnd = greenBegin + colRange - 1;
//const long blueBegin = greenEnd + 1;
//const long blueEnd = blueBegin + colRange - 1;
//const long colEnding = blueEnd;
//
//void incrementCntr() {
//  cntr = (cntr < colEnding) ? cntr + 1 : colBegining;
//}
//
//uint8_t mkAColor(long c, long cBegin, long cEnd) {
//  return (uint8_t) ((c < cBegin && c < cEnd) ? 0 : c);
//}
//
//uint32_t mkColor(long c) {
//  uint8_t r = mkAColor(c, redBegin, redEnd);
//  uint8_t g = mkAColor(c, greenBegin, greenEnd);
//  uint8_t b = mkAColor(c, blueBegin, blueEnd);
//  return neoPixels.Color(r,g,b);
//}
//
//void sendColor(int iPix, uint32_t c) {
//  neoPixels.setPixelColor(iPix, c);
//}
//
//void colorIncrementer() {
//
//  for(int iPix=0;iPix<NUMPIXELS;iPix++) {
//    sendColor(iPix,mkColor(cntr));
//    neoPixels.show();
//    delay(delayval);
//    incrementCntr();
//  }
//
// }
//
//uint32_t colors [] = {
//  neoPixels.Color(80,0,0),
//  neoPixels.Color(0,80,0),
//  neoPixels.Color(0,0,100), 
//  neoPixels.Color(80,80,0),
//  neoPixels.Color(0,80,80),
//  neoPixels.Color(80,0,80),
//  neoPixels.Color(80,80,80) 
//};

//
//int r = 0;
//
//template <typename T,unsigned S>
//inline unsigned arraysize(const T (&v)[S]) { return S; }
//
//int colorsLen = arraysize(colors);
//
//void colorToggler() {
//
//  r = r - 1;
//  for(int iPix=0;iPix<NUMPIXELS;iPix++) {
//    sendColor(iPix,colors[(r + iPix) % colorsLen]);
//  }
//  neoPixels.show();
//  delay(loopDelay);
//
// }


