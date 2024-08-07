#include "bulb.h"
#include <stdio.h>

static uint32_t serialNumbers[256] = {0};
static uint32_t bulbsSold[256] = {0};

Bulb_t bulb_sellModel(uint8_t model) 
{
    Bulb_t bulb;
    bulb.model = model;
    bulb.serialNumber = serialNumbers[model]++;
    bulbsSold[model]++;
    return bulb;
}

void bulb_display(Bulb_t bulb) 
{
    printf("Model %d, SN%06u\n", bulb.model, bulb.serialNumber);
}

uint32_t bulb_numSold(uint8_t model) 
{
    return bulbsSold[model];
}