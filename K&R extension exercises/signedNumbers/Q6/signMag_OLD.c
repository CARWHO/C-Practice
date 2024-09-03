#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

#include "signMag.h"

SignMag_t signMag_init(bool isNegative, uint16_t magnitude) {
    SignMag_t sm;
    // sm.isNegative = isNegative;
    // sm.magnitude = magnitude;
    return sm;
}

void signMag_print(SignMag_t sm) {
    printf("Magnitude: %u, Sign: %s\n", sm.magnitude, sm.isNegative ? "Negative" : "Positive");
}

SignMag_t signMag_sum(SignMag_t sm1, SignMag_t sm2) {
    SignMag_t result;
    unsigned int sum_diff;

    if (sm1.isNegative != sm2.isNegative) {
        if (sm1.magnitude > sm2.magnitude) {
            sum_diff = (sm1.magnitude - sm2.magnitude);
            result.isNegative = sm1.isNegative;
            result.magnitude = sum_diff;

        } else if (sm1.magnitude < sm2.magnitude) {
            sum_diff = (sm2.magnitude - sm1.magnitude);
            result.isNegative = sm2.isNegative;
            result.magnitude = sum_diff;

        } else {
            sum_diff = 0;
            result.isNegative = false;
            result.magnitude = sum_diff;

        }
    } else {
        sum_diff = (sm1.magnitude + sm2.magnitude);
        if (sum_diff > ((1U << 16) - 1)) {
            result.magnitude = ((1U << 16) - 1); 
        } else {
            result.magnitude = sum_diff;
        }
        result.isNegative = sm1.isNegative;
    }
    return result;
}

SignMag_t signMag_accumulate(const SignMag_t* array, size_t arraySize) {
    SignMag_t result = {false, 0}; 
    for (size_t i = 0; i < arraySize; i++) {
        result = signMag_sum(result, array[i]); 
    }
    return result;
}

int main()

{
    SignMag_t array[100];
    SignMag_t result;
    
    for (size_t i=0; i < 100; i++) {
        array[i] = signMag_init(i%2, i);
    }
    result = signMag_accumulate(array, 100);
    result = signMag_multiply(result, result);
    
    signMag_print(result);
}