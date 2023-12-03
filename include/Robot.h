#include <Arduino.h>
#include <Config.h>

#ifndef ROBOT_H 
#define ROBOT_H 

class Robot {
    public:
        // move forward
        void run(int speed) {
            digitalWrite(DIRECTION_LEFT, LOW);
            digitalWrite(DIRECTION_RIGHT, LOW);
            analogWrite(MOTOR_LEFT, speed);
            analogWrite(MOTOR_RIGHT, speed);
        }

        // stop moving
        void stop(){
            analogWrite(MOTOR_LEFT, 0);
            analogWrite(MOTOR_RIGHT, 0);
        }

        // move distance
        void straightDistance(int speed, int distance) {
            distance *= 2.3250406882120437107649383864218;
            analogWrite(MOTOR_LEFT, speed);
            analogWrite(MOTOR_RIGHT, speed);
            digitalWrite(DIRECTION_LEFT, LOW);
            digitalWrite(DIRECTION_RIGHT, LOW);
            // estimated distance
            delay(distance);
            stop();
        }

        // turn angle
        void turn(int speed, int angle) {
            int untilAngle = abs(angle * 6);
            // turn right
            if (angle > 0) {
                digitalWrite(DIRECTION_LEFT, HIGH);
                digitalWrite(DIRECTION_RIGHT, LOW);  
            // turn left
            } else {
                digitalWrite(DIRECTION_LEFT, LOW);
                digitalWrite(DIRECTION_RIGHT, HIGH);
            }
            analogWrite(MOTOR_LEFT, speed);
            analogWrite(MOTOR_RIGHT, speed);
            // estimated angle
            delay(untilAngle);
            stop();
        }
    };

#endif