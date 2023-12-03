#include <Arduino.h>
#include <Ultrasonic.h>
#include <Config.h>
#include <Robot.h>
#include <Sensor.h>

Ultrasonic ultrasonic1(TRIGGER_1, ECHO_1);
Ultrasonic ultrasonic2(TRIGGER_2 ,ECHO_2);
Ultrasonic ultrasonic3(TRIGGER_3, ECHO_3);
Robot robot;
Sensor sensor;

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
  // for(int i = 0; i < 4; i++) { 
  //   robot.straightDistance(255, 1000);
  //   robot.turn(255, 90);
  // }
  // delay(1000);
  // if(20 < ultrasonic3.read()) {
  //   Serial.println(ultrasonic3.read());
  //   robot.run(255);
  // } else {
  //   robot.stop();
  // }
  // delay(100);
  sensor.untilSonic(ultrasonic3, 20, robot);
  sensor.sideWaysSonic(ultrasonic1, ultrasonic2, 10, robot);
}
