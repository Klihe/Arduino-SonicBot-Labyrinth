#include <Arduino.h>
#include <Ultrasonic.h>
#include <Config.h>
#include <Robot.h>
#include <Sensor.h>

using namespace MotorPins;
using namespace SonicPins;

// Ultrasonic and Robot instance
Ultrasonic ultrasonic1(TRIGGER_FRONT, ECHO_FRONT);
Ultrasonic ultrasonic2(TRIGGER_LEFT ,ECHO_LEFT);
Ultrasonic ultrasonic3(TRIGGER_RIGHT, ECHO_RIGHT);
Robot robot;
Sensor sensor;

// Constants
const int SONIC_UPDATE_DELAY = 10;

// Init Pins
void initPins();

void setup() {
  Serial.begin(9600);
  initPins();
}

void loop() {
  // Update sonic value
  int sonicReadFront = ultrasonic1.read();
  int sonicReadLeft = ultrasonic2.read();
  int sonicReadRight = ultrasonic3.read();
  delay(SONIC_UPDATE_DELAY);

  // Check values of sonic
  Serial.print("FrontSonic: ");
  Serial.print(ultrasonic1.read(CM));
  Serial.println("cm");

  Serial.print("LeftSonic: ");
  Serial.print(ultrasonic2.read(CM));
  Serial.println("cm");

  Serial.print("RightSonic: ");
  Serial.print(ultrasonic3.read(CM));
  Serial.println("cm");

  // Main
  sensor.untilSonic(sonicReadFront, sonicReadLeft, sonicReadRight, 25, robot);
  sensor.sideWaysSonic(sonicReadLeft, sonicReadRight, 7, robot);
}

void initPins() {
  pinMode(MOTOR_LEFT, OUTPUT);
  pinMode(MOTOR_RIGHT, OUTPUT);
  pinMode(DIRECTION_LEFT, OUTPUT);
  pinMode(DIRECTION_RIGHT, OUTPUT); 
}