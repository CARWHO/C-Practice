// TEMP.H
#include <stdint.h>
#include <stdbool.h>

#ifndef TEMP_H
#define TEMP_H

typedef enum {
    CELSIUS,
    FAHRENHEIT,
    KELVIN
} Unit_t;

typedef struct {
    float temperature;
    Unit_t unit; //what type for unit?
} Temp_t;

void temp_set(Temp_t* temp, float value, Unit_t unit);
void temp_print(const Temp_t* temp, Unit_t unit);

#endif // TEMP.H

