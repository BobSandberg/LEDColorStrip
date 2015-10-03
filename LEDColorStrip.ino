// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      10

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int loopDelay = 500;
int delayval = loopDelay / NUMPIXELS;

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
}

long cntr = 0;
enum Direction { GOING_UP, GOING_DOWN };
Direction dir = GOING_UP;

const long colRange = 256;

const long colBegining = 0; 
const long redBegin = colBegining;
const long redEnd = redBegin + colRange - 1;
const long greenBegin = redEnd + 1;
const long greenEnd = greenBegin + colRange - 1;
const long blueBegin = greenEnd + 1;
const long blueEnd = blueBegin + colRange - 1;
const long colEnding = blueEnd;

void incrementCntr() {
  cntr = (cntr < colEnding) ? cntr + 1 : colBegining;
}

uint8_t mkAColor(long c, long cBegin, long cEnd) {
  return (uint8_t) ((c < cBegin && c < cEnd) ? 0 : c);
}

uint32_t mkColor(long c) {
  uint8_t r = mkAColor(c, redBegin, redEnd);
  uint8_t g = mkAColor(c, greenBegin, greenEnd);
  uint8_t b = mkAColor(c, blueBegin, blueEnd);
  return pixels.Color(r,g,b);
}

void sendColor(int iPix, uint32_t c) {
  pixels.setPixelColor(iPix, c);
}

void colorIncrementer() {

  for(int iPix=0;iPix<NUMPIXELS;iPix++) {
    sendColor(iPix,mkColor(cntr));
    pixels.show();
    delay(delayval);
    incrementCntr();
  }

 }

uint32_t colors [] = {
  pixels.Color(80,0,0),
  pixels.Color(0,80,0),
  pixels.Color(0,0,100), 
  pixels.Color(80,80,0),
  pixels.Color(0,80,80),
  pixels.Color(80,0,80),
  pixels.Color(80,80,80) 
};

int r = 0;

template <typename T,unsigned S>
inline unsigned arraysize(const T (&v)[S]) { return S; }

int colorsLen = arraysize(colors);

void colorToggler() {

  r = r - 1;
  for(int iPix=0;iPix<NUMPIXELS;iPix++) {
    sendColor(iPix,colors[(r + iPix) % colorsLen]);
  }
  pixels.show();
  delay(loopDelay);

 }

void loop() {

//  colorIncrementer();
  colorToggler();

 }



