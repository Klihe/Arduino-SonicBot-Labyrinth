#include <Arduino.h>
#include <Ultrasonic.h>
#include <Config.h>
#include <Robot.h>
#include <Sensor.h>

Ultrasonic ultrasonic1(TRIGGER_FRONT, ECHO_FRONT);
Ultrasonic ultrasonic2(TRIGGER_LEFT ,ECHO_LEFT);
Ultrasonic ultrasonic3(TRIGGER_RIGHT, ECHO_RIGHT);
Robot robot;
Sensor sensor;

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_LEFT, OUTPUT);
  pinMode(MOTOR_RIGHT, OUTPUT);
  pinMode(DIRECTION_LEFT, OUTPUT);
  pinMode(DIRECTION_RIGHT, OUTPUT);
}

void loop() {
  // Update sonic value
  int sonicReadFront = ultrasonic1.read();
  int sonicReadLeft = ultrasonic2.read();
  int sonicReadRight = ultrasonic3.read();
  delay(100);

  // Check values of sonic
  Serial.print("Sensor 01: ");
  Serial.print(ultrasonic1.read(CM));
  Serial.println("cm");

  Serial.print("Sensor 02: ");
  Serial.print(ultrasonic2.read(CM));
  Serial.println("cm");

  Serial.print("Sensor 03: ");
  Serial.print(ultrasonic3.read(CM));
  Serial.println("cm");

  // Main
  sensor.untilSonic(sonicReadFront, sonicReadLeft, sonicReadRight, 25, robot);
  sensor.sideWaysSonic(sonicReadLeft, sonicReadRight, 10, robot);
}
