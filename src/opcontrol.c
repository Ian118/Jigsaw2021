/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

TaskHandle autonTask;

void operatorControl()
{
  while (true)
  {
    if (joystickGetDigital(1, 5, JOY_UP) && (autonTask == NULL || taskGetState(autonTask) != TASK_RUNNING))
    {
      autonTask = taskCreate(autonomous, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
    }
    else if (joystickGetDigital(1, 5, JOY_DOWN) && autonTask != NULL)
    {
      taskDelete(autonTask);
    }

    if (autonTask == NULL || taskGetState(autonTask) != TASK_RUNNING)
    {
      doDrivebase();
      doClaw();
      doFourbar();
      doFence();
      doLightpole();
    }

    delay(20);
  }
}