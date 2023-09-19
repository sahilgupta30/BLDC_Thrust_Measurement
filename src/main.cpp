#include <Arduino.h>
#include <esc.h>
#include "HX711.h"

#define LOADCELL_DOUT_PIN 18
#define LOADCELL_SCK_PIN 19

esc motor (21,ONESHOT125);
HX711 scale;

int throttle_percentage = 0;
long reading = 0;

void setup() {
  Serial.begin(115200);
  motor.init();
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN,64);
}

void loop() {
  delay(500);
  while(throttle_percentage <= 100){
    for(int i = 0;i < 6;i++){
      while(!scale.is_ready()){}
      reading += scale.read();
    }
    reading = reading / 5;
    Serial.print(throttle_percentage);
    Serial.print(",");
    Serial.println(reading);
    reading = 0;
    throttle_percentage++;
    motor.write(map(throttle_percentage,0,100,0,1023));
  }
  while (throttle_percentage>=0)
  {
    throttle_percentage--;
    motor.write(map(throttle_percentage,0,100,0,1023));
    delay(10);
  }
  while(true){}
}