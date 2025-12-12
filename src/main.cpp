#include <Arduino.h>
#include "utils.h"
#include "constants.h"
#include <WiFiNINA.h>
#include "rgbLight.h"
#include "motors.h"
#include <Wire.h>
#include "sensors.h"

using namespace Robot;

void setup() {
  Wire.begin();


  // Initialize all the motors:
  for (int n = 0; n < 3; n++) {
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
  }
  // Initialize the RGB Light on the board:
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}



void loop() {
  rgbLight::lightRGB(true, false, false);
  // Sample for reading the IR Seeker:
  int direction;
  int strength;
  Sensors::readIrSeeker(direction, strength);

  Serial.println(direction);
  rgbLight::lightRGB(false, true, false);
}