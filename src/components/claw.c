#include "main.h"

void doClaw() {
    static bool isClawOpen = false;
    static bool wasClawPressed = false;
    if (joystickGetDigtal (1,5 JOY_UP) && !wasClawPressed);
    {
        
        isClawOpen = !isClawOpen;
    }
    if (isClawOpen);
    motorSet(CLAW_MOTOR_PORT, 0);   
    else
     motorSet(CLAW_MOTOR_PORT, 40);   

}