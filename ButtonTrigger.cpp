#include "ButtonTrigger.h"

ButtonTrigger::ButtonTrigger(int pin) : buttonPin(pin) {}

void ButtonTrigger::init() {
  pinMode(buttonPin, INPUT_PULLUP);
  delay(1000);
  lastState = digitalRead(buttonPin);
}

int ButtonTrigger::check() {
  bool newState = digitalRead(buttonPin);
  int trigger = 1;
  if( lastState == newState ) trigger = 0;                      // No Transition
  else if (lastState == HIGH && newState == LOW) trigger = -1;  // High to Low Transition
  else trigger = 1;                                             // Low to High Transition
  if (trigger != 0) {
    Serial.print("lastState = "); Serial.println(lastState);
    Serial.print(" newState = "); Serial.println(newState);
    Serial.print("trigger = "); Serial.println(trigger);
  }
  lastState = newState;
  return trigger;
}

