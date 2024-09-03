#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

#include "signMag.h"

#define MAX_MAGNITUDE ((1U << (sizeof(uint16_t) * 8)) - 1)

SignMag_t signMag_sum(SignMag_t sm1, SignMag_t sm2)

{
    SignMag_t sumResult;
    unsigned int sum_diff;

    if (sm1.isNegative != sm2.isNegative) {
        if (sm1.magnitude > sm2.magnitude) {
            sum_diff = (sm1.magnitude - sm2.magnitude);
            sumResult.isNegative = sm1.isNegative;
            sumResult.magnitude = sum_diff;

        } else if (sm1.magnitude < sm2.magnitude) {
            sum_diff = (sm2.magnitude - sm1.magnitude);
            sumResult.isNegative = sm2.isNegative;
            sumResult.magnitude = sum_diff;

        } else {
            sum_diff = 0;
            sumResult.isNegative = false;
            sumResult.magnitude = sum_diff;

        }
    } else {
        sum_diff = (sm1.magnitude + sm2.magnitude);
        if (sum_diff > MAX_MAGNITUDE) {
            sumResult.magnitude = MAX_MAGNITUDE;
        } else {
            sumResult.magnitude = sum_diff;
        }
        sumResult.isNegative = sm1.isNegative;
    }
    return sumResult;
}

SignMag_t signMag_accumulate(const SignMag_t* array, size_t arraySize)

{
    if (arraySize == 0) {
        SignMag_t zeroResult = {false, 0};
        return zeroResult;
    }

    SignMag_t total = array[0];
    for (int i = 1; i < arraySize; i++) {
        total = signMag_sum(total, array[i]);
    }

    return total;
}

int main()

{
    // Test 8: Positive Result Exceeding Maximum Magnitude (Saturation)
    SignMag_t test8[] = { {false, 20000}, {false, 20000}, {false, 10000} };
    SignMag_t result8 = signMag_accumulate(test8, 3);
    assert(result8.magnitude == MAX_MAGNITUDE && !result8.isNegative);

    printf("All tests passed!\n");

    return 0;
}

