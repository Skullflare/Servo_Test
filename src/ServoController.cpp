#include "ServoController.h"

ServoController::ServoController(int pin1, int pin2)
    : pin1(pin1), pin2(pin2),
      servoPos(0), servoDir(1), lastServoMove(0) {}

void ServoController::begin() {
    servo1.attach(pin1);
    servo2.attach(pin2);

    servo1.write(servoMin);
    servo2.write(servoMax);
}

void ServoController::update() {
    unsigned long currentMillis = millis();

    if (currentMillis - lastServoMove >= servoStepDelay) {
        lastServoMove = currentMillis;

        servoPos += servoDir;

        if (servoPos >= servoMax || servoPos <= servoMin) {
            servoDir = -servoDir;
        }

        servo1.write(servoPos);
        servo2.write(servoMax - servoPos); // Opposite movement
    }
}
