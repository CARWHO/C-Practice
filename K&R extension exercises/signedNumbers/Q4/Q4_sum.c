#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

#include "signMag.h"

#define MAX_MAGNITUDE ((1U << (sizeof(sm1.magnitude) * 8)) - 1)

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

        }
        else {
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

int main() 

{
    return 0;
}