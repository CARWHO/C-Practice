// LIFT.H
#include <stdint.h>
#include <stdbool.h>

#ifndef LIFT_H
#define LIFT_H

typedef struct {
    uint16_t currentFloor;
    uint8_t passengers;
    uint8_t maxPassengers;

} Lift_t;

Lift_t lift_init(uint8_t maxPassengers, int16_t startFloor); //I dont understand
void lift_onboard(Lift_t* lift, uint8_t peopleOff, uint8_t peopleOn);
int16_t lift_goToFloor(Lift_t* lift, int16_t floor);

#endif // LIFT.H

