#include <Arduino.h>
#include <Ultrasonic.h>
#include <Config.h>
#include <Robot.h>

Ultrasonic ultrasonic1(TRIGGER_1, ECHO_1);
Ultrasonic ultrasonic2(TRIGGER_2 ,ECHO_2);
Ultrasonic ultrasonic3(TRIGGER_3, ECHO_3);
Robot robot;

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_A, OUTPUT);
  pinMode(MOTOR_B, OUTPUT);
  pinMode(DIRECTION_A, OUTPUT);
  pinMode(DIRECTION_B, OUTPUT);
}

void loop() {
  // Serial.print("Sensor 01: ");
  // Serial.print(ultrasonic1.read(CM));
  // Serial.println("cm");

  // Serial.print("Sensor 02: ");
  // Serial.print(ultrasonic2.read(CM));
  // Serial.println("cm");

  // Serial.print("Sensor 03: ");
  // Serial.print(ultrasonic3.read(CM));
  // Serial.println("cm");

  // delay(1000);
  for(int i = 0; i < 4; i++) { 
    robot.turn(255, 90);
    robot.straight(255, 1000);
  }
  delay(1000);
}
