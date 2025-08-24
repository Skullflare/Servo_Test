#pragma once
#include <Arduino.h>
#include <Servo.h>

class ServoController {
public:
    ServoController(int pin1, int pin2);

    void begin();
    void update();

private:
    Servo servo1;
    Servo servo2;

    int servoPos;
    int servoDir;
    const int servoMin = 0;
    const int servoMax = 180;
    const int servoStepDelay = 15; // ms between moves
    unsigned long lastServoMove;

    int pin1;
    int pin2;
};