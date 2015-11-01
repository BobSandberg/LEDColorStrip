// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
// Version 0.1

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#include "LEDPattern.h"
#include "LEDPatternBasic.h"
#include "LEDPatternSingleColor.h"
#include "LEDPatternColorToggle.h"
#include "util.h"

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      10

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel neoPixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int loopDelay = 500;
//int delayval = loopDelay / NUMPIXELS;

const uint32_t red   =  neoPixels.Color(255,0,0);
const uint32_t green =  neoPixels.Color(0,255,0);
const uint32_t blue  =  neoPixels.Color(0,0,255);

const uint32_t bluePixels[] = {
  blue,
  blue,
  blue,
  blue,
  blue,
  blue,
  blue,
  blue,
  blue,
  red,
};

LEDPatternBasic patternBasic("BLUE", bluePixels, 10, 0 );

LEDPatternSingleColor patternAllRed  ("All Red"  , red  ); 
LEDPatternSingleColor patternAllGreen("All Green", green); 
LEDPatternSingleColor patternAllBlue ("All Blue" , blue ); 

const uint32_t RGBColors[] = { red, green, blue };
LEDPatternColorToggle patternColorToggle("RGB Toggle", RGBColors, 3, 50); 

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  neoPixels.begin(); // This initializes the NeoPixel library.
  neoPixels.show();
  
  Serial.begin(9600);
  delay(2000);
  Serial.println("Starting NeoPixels");
  Serial.println("------------------");

  delay(200);

}






//void testPatternMemory() {
//  uint32_t a[10];
//  uint32_t b[10];
//
//
//  memcpy( (char *)a, (char *)bluePixels, 10 * sizeof(uint32_t));
////  memcpy( a, bluePixels, sizeof(uint32_t) * 10);
//
////  showPixels("memcpy'd bluePixels array into a: ", a, 10);
//
//  for(int k = 0; k<10; k++)
//    b[k] = bluePixels[k];
//
//  showPixels("array copied bluePixels array into b: ", b, 10);
//
//  showPixels("patternBasic initilized with bluePixels:", patternBasic.pixels, 10);
//}

void loop() {
  LEDPattern& pattern = 
//    patternBasic;
//    patternAllRed;
//    patternAllGreen;
//    patternAllBlue;
    patternColorToggle;
//    patternColorToggle.loop(neoPixels);

//  testPatternMemory();
  pattern.describe();
    
  while(true) {
    pattern.loop(neoPixels);
    patternColorToggle.toggle(); // Hmmmm how to do this -- put it in the pattern loop or do some kind of post loop hook
    delay(loopDelay);
  }
 }



