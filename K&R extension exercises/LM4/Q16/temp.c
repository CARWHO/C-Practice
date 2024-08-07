// TEMP.C
#include "temp.h"
#include <stdio.h>

static float convert(const Temp_t* temp, Unit_t targetUnit) 
{
    float tempInCelsius = 0.0f;

    switch (temp->unit) {
        case CELSIUS:
            tempInCelsius = temp->temperature;
            break;
        case FAHRENHEIT:
            tempInCelsius = (temp->temperature - 32.0f) * 5.0f / 9.0f;
            break;
        case KELVIN:
            tempInCelsius = temp->temperature - 273.15f;
            break;
    }

    switch (targetUnit) {
        case CELSIUS:
            return tempInCelsius;
        case FAHRENHEIT:
            return tempInCelsius * 9.0f / 5.0f + 32.0f;
        case KELVIN:
            return tempInCelsius + 273.15f;
        default:
            return 0.0f; // or some other default value
    }
}

void temp_set(Temp_t* temp, float value, Unit_t unit) 
{
    temp->temperature = value;
    temp->unit = unit;
}

void temp_print(const Temp_t* temp, Unit_t unit) 
{
    float convertedTemp = convert(temp, unit);
    printf("%.2f", convertedTemp);

    switch (unit) {
        case CELSIUS:
            printf(" deg C\n");
            break;
        case FAHRENHEIT:
            printf(" deg F\n");
            break;
        case KELVIN:
            printf(" K\n");
            break;
    }
}