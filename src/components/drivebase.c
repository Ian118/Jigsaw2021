#include "main.h"
#include <math.h>

void doDrivebase()
{
    static int forwardPower, turnPower, leftPower, rightPower;
    forwardPower = joystickGetAnalog(1, 3);
    turnPower = joystickGetAnalog(1, 1);

    // Apply square adjustment to turning so it can controlled precisely
    // turnPower = copysign((char)(turnPower * turnPower / 127.0), turnPower);

    // Calculating left and right powers
    leftPower = forwardPower + turnPower;
    rightPower = forwardPower - turnPower;

    // Setting Controller Deadband
    if (abs(leftPower) < DEADBAND)
        leftPower = 0;
    if (abs(rightPower) < DEADBAND)
        rightPower = 0;

    // Setting Max motor power
    if (abs(leftPower) > 127)
        leftPower = copysign(127, leftPower);
    if (abs(rightPower) > 127)
        rightPower = copysign(127, rightPower);

    // Set motors to calculated powers (right motor is reversed)
    motorSet(LEFT_DRIVE_MOTOR, leftPower);
    motorSet(RIGHT_DRIVE_MOTOR, -rightPower);
}