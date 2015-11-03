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
#include "ButtonTrigger.h"
#include "util.h"

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define NEOPIXEL_PIN    2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      10

#define BUTTON_PIN      3

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel neoPixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

int loopDelay = 50;
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

LEDPattern* patterns[] = {
    &patternBasic,
    &patternAllRed,
    &patternAllGreen,
    &patternAllBlue,
    &patternColorToggle
};

int nPatterns = 5;

ButtonTrigger button(BUTTON_PIN);

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

  button.init();
}

int selectedPattern = 0;

void loop() {
  LEDPattern *pattern = patterns[selectedPattern];

  pattern->describe(); Serial.println();      
    
  while(true) {
    if (button.check() > 0) {
      Serial.println("button.check fired +1");
      selectedPattern++;
      if (selectedPattern >= nPatterns) selectedPattern = 0;
      pattern = patterns[selectedPattern];
      pattern->describe(); Serial.println();      
    }
    
    pattern->loop(neoPixels);
    delay(loopDelay);
  }
 }



