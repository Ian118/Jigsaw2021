#include "main.h"

void doFence() {
    enum positionState{Up, Mid, Down};
    static positionState currentPosition = Up;
    switch (currentPosition) {
        case Up:
        motorSet(FENCE_SERVO_PORT, 127);
        break;

        case Mid:
        motorSet(FENCE_SERVO_PORT, 50);
        break;

        case Down:
        motorSet(FENCE_SERVO_PORT, -127);
        break;
    }
}