#include "main.h"

#define ANTIGRAV_INCREMENT 5

void doFourbar()
{
    static char antigrav = 0;
    static bool wasIncPressed = false, wasDecPressed = false;

    // Antigrav
    if (joystickGetDigital(1, 8, JOY_UP) && !wasIncPressed && antigrav <= 127 - ANTIGRAV_INCREMENT)
        antigrav += ANTIGRAV_INCREMENT;
    else if (joystickGetDigital(1, 8, JOY_DOWN) && !wasDecPressed && antigrav >= -127 + ANTIGRAV_INCREMENT)
        antigrav -= ANTIGRAV_INCREMENT;
    wasIncPressed = joystickGetDigital(1, 8, JOY_UP);
    wasDecPressed = joystickGetDigital(1, 8, JOY_DOWN);

    // Four-bar, motor is reversed
    if (joystickGetDigital(1, 6, JOY_UP))
        motorSet(FOURBAR_MOTOR_PORT, -127);
    else if (joystickGetDigital(1, 6, JOY_DOWN))
        motorSet(FOURBAR_MOTOR_PORT, 127);
    else
        motorSet(FOURBAR_MOTOR_PORT, -antigrav);
}