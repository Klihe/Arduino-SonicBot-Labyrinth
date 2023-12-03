#include <Arduino.h>
#include <Ultrasonic.h>
#include <Config.h>
#include <Robot.h>

#ifndef SENSOR_H 
#define SENSOR_H

class Sensor {
    public:
        // Move until front sonic
        void untilSonic(int sonicReadFront, int sonicReadLeft, int sonicReadRight, int distance, Robot &robot) {
            if (distance > sonicReadFront) {
                if (sonicReadLeft < sonicReadRight) {
                    robot.turn(255, 90);
                } else {
                    robot.turn(255, -90);
                }
            } else {
                robot.run(255);
            }
        }

        // Compare left and right sides
        void sideWaysSonic(int sonicReadLeft, int sonicReadRight, int distance, Robot &robot) {
            if (sonicReadLeft * 2 < sonicReadRight && sonicReadLeft < distance) {
                robot.turn(255, 45);
            }
            else if (sonicReadRight * 2 < sonicReadLeft && sonicReadRight < distance) {
                robot.turn(255, -45);
            }
        }
};

#endif