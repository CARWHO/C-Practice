#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "bulb.h"

#define MAX_PASSENGERS 12

int main(void)

{

Bulb_t bulbs[20];

for (size_t i = 0; i < 4; i++) {
    bulbs[i] = bulb_sellModel(15);
}

bulbs[4] = bulb_sellModel(201);

for (size_t i = 5; i < 20; i++) {
    bulbs[i] = bulb_sellModel(99);
}

printf("Model %u: %u sold\n", 15, bulb_numSold(15));
printf("Model %u: %u sold\n", 201, bulb_numSold(201));
printf("Model %u: %u sold\n", 99, bulb_numSold(99));

size_t index = 0;
scanf("%zu", &index);
bulb_display(bulbs[index]);

}