#include <Arduino.h>
#include <Ultrasonic.h>
#include <Config.h>

Ultrasonic ultrasonic1(TRIGGER_1, ECHO_1);
Ultrasonic ultrasonic2(TRIGGER_2 ,ECHO_2);
Ultrasonic ultrasonic3(TRIGGER_3, ECHO_3);

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_A, OUTPUT);
  pinMode(MOTOR_B, OUTPUT);
  pinMode(DIRECTION_A, OUTPUT);
  pinMode(DIRECTION_B, OUTPUT);
}

void loop() {
  Serial.print("Sensor 01: ");
  Serial.print(ultrasonic1.read());
  Serial.println("cm");

  Serial.print("Sensor 02: ");
  Serial.print(ultrasonic2.read(CM));
  Serial.println("cm");

  Serial.print("Sensor 03: ");
  Serial.print(ultrasonic3.read(INC));
  Serial.println("inc");

  delay(1000);

  for (int speed = 50; speed < 200; speed++) {
    digitalWrite(DIRECTION_A, HIGH);
    digitalWrite(DIRECTION_B, HIGH);
    analogWrite(MOTOR_A, speed);
    analogWrite(MOTOR_B, speed);
    delay(10);
  }
  for (int speed = 200; speed > 50; speed--) {
    digitalWrite(DIRECTION_A, HIGH);
    digitalWrite(DIRECTION_B, HIGH);
    analogWrite(MOTOR_A, speed);
    analogWrite(MOTOR_B, speed);
    delay(1);
  }
  delay(1000);
}