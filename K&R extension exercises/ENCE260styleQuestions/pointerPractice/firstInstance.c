#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void findInArray(uint16_t* array, size_t n, uint16_t value, uint16_t** foundValueDest)

{
    *foundValueDest = NULL;
    for (int i = 0; i < n; i++) {
        if (array[i] == value) {
            *foundValueDest = &array[i];
        } 
    }
}

int main()

{
    uint16_t array[6] = {0, 2, 4, 6, 8, 10};
    uint16_t* foundValue = NULL;
    findInArray(array, 6, 8, &foundValue);
    if (foundValue != NULL) {
        printf("%u == %u\n", *foundValue, array[4]);
    }
}