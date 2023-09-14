#include <Arduino.h>
#include <esc.h>
#include "HX711.h"

const int LOADCELL_DOUT_PIN = 19;
const int LOADCELL_SCK_PIN = 18;

esc motor (5,ONESHOT125);
HX711 scale;

void setup() {
  Serial.begin(57600);
  motor.init();
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN,64);
}

void loop() {

  if (scale.is_ready()) {
  }
}