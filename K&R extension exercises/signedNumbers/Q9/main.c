#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

#include "signMag.h"

#define MAX_MAGNITUDE ((1U << (sizeof(uint16_t) * 8)) - 1)

SignMag_t* arrayMax(SignMag_t* array, size_t size, bool (*func)(SignMag_t*, SignMag_t*, SignMag_t**))

{
    if (size == 0) {
        return NULL;
    }

    SignMag_t* max = &array[0];

    for (int i = 0; i < size; i++) {
        func(max, &array[i], &max);
    }

    return max;
}

int main()

{
    uint32_t i = 0;
    SignMag_t arr[100];
    while (i < 100) {
        SignMag_t input = signMag_read();
        if ((input.isNegative == true) && (input.magnitude == 0)) {
            break;
        } else {    
            arr[i] = input;
            i++;
        }
        
    }
    uint32_t j = 0;
    while (j < i) {
        if (arr[j].isNegative) {
        printf("Got Number: -%d\n", arr[j].magnitude);
        j++; 
    } else {
        printf("Got Number: %d\n", arr[j].magnitude);
        j++; 
    }
        
    }

    SignMag_t accum = signMag_accumulate(arr, i);
    if (accum.isNegative) {
        printf("Accumulated Sum: -%d\n", accum.magnitude); 
    } else {
        printf("Accumulated Sum: %d\n", accum.magnitude); 
    }
    
    uint32_t square = accum.magnitude * accum.magnitude;
    if (square > MAX_MAGNITUDE) {
        printf("Square Accumulated Sum: %d\n", MAX_MAGNITUDE);
    } else {
        printf("Square Accumulated Sum: %d\n", square);
    }
    
    SignMag_t* maxNum = arrayMax(arr, i, signMag_max);
    if (maxNum->isNegative) {
        printf("Max of Numbers: -%d\n", maxNum->magnitude); 
    } else {
        printf("Max of Numbers: %d\n", maxNum->magnitude); 
    }
}