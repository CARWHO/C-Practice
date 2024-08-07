// BULB.H
#include <stdint.h>
#include <stdbool.h>

#ifndef BULB_H
#define BULB_H

typedef struct {
    uint32_t serialNumber;
    uint16_t model;
} Bulb_t;

Bulb_t bulb_sellModel(uint8_t model); // I dont understand 
void bulb_display(Bulb_t bulb);
uint32_t bulb_numSold(uint8_t model);

#endif // BULB.H

