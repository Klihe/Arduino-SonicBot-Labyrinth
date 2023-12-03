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
                robot.turn(MAX_SPEED, 90);
            } else {
                robot.turn(MAX_SPEED, -90);
            }
        } else {
            robot.run(MAX_SPEED);
        }
    }

    // Compare left and right sides
    void sideWaysSonic(int sonicReadLeft, int sonicReadRight, int distance, Robot &robot) {
        if (sonicReadLeft * 2 < sonicReadRight && sonicReadLeft < distance) {
            robot.turn(MAX_SPEED, 30);
        }
        else if (sonicReadRight * 2 < sonicReadLeft && sonicReadRight < distance) {
            robot.turn(MAX_SPEED, -30);
        }
    }
private:
    static const int MAX_SPEED = 255;
};

#endif