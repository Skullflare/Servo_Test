#include <Arduino.h>
#include "ServoController.h"

// Servo pins
#define SERVO1_PIN 9
#define SERVO2_PIN 10

ServoController servos(SERVO1_PIN, SERVO2_PIN);

void setup() {
  Serial.begin(9600);
  servos.begin();
}

void loop() {
  servos.update();
}
