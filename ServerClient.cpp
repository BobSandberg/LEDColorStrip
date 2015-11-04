#include "ServerClient.h"
#include <string.h>
#include <Adafruit_NeoPixel.h>
#include "util.h"
#include "PredefinedColors.h"
#include "LEDPatternSingleColor.h"


ServerClient::ServerClient(Adafruit_NeoPixel& _neoPixels, LEDPattern& _pattern) : neoPixels(_neoPixels), pattern(_pattern) {}

void ServerClient::init() {}

COMMAND ServerClient::getCommand() {
  if (doneOnce) return NO_COMMAND;
  else { doneOnce = true; return NEW_PATTERN; }
}

int ServerClient::receivePattern(int& patternSlot, LEDPattern **newPattern) {
  patternSlot = 1;
  *newPattern = &pattern;
  return 0;
}


