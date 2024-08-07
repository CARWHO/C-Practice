#include "lift.h"

Lift_t lift_init(uint8_t maxPassengers, int16_t startFloor)

{
    Lift_t lift;
    lift.maxPassengers = maxPassengers;
    lift.passengers = 0;
    lift.currentFloor = startFloor;
    return lift;
}

void lift_onboard(Lift_t* lift, uint8_t peopleOff, uint8_t peopleOn)

{
    lift->passengers = lift->passengers - peopleOff + peopleOn;
}

int16_t lift_goToFloor(Lift_t* lift, int16_t floor)

{
    if (lift->currentFloor < 0 || lift->passengers > lift->maxPassengers) {
        return lift->currentFloor;
    } else {
        lift->currentFloor = floor;
        return lift->currentFloor;
    }
}

