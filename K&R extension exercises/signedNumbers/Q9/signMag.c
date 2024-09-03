#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

#include "signMag.h"

#define MAX_MAGNITUDE ((1U << (sizeof(uint16_t) * 8)) - 1)

SignMag_t signMag_init(bool isNegative, uint16_t magnitude)
{
    SignMag_t newSM;
    newSM.isNegative = isNegative;
    newSM.magnitude = magnitude;
    return newSM;
}

void signMag_print(SignMag_t value)
{
    if (value.isNegative) {
        printf("-%u\n", value.magnitude);
    } else {
        printf("%u\n", value.magnitude);
    }
    
}

SignMag_t signMag_sum(SignMag_t sm1, SignMag_t sm2)
{
    SignMag_t result;
    uint32_t sm_diff;

    if (sm1.isNegative != sm2.isNegative) {
        if (sm1.magnitude > sm2.magnitude) {
            sm_diff = (sm1.magnitude - sm2.magnitude);
            result.isNegative = sm1.isNegative;
            result.magnitude = sm_diff;

        } else if (sm1.magnitude < sm2.magnitude) {
            sm_diff = (sm2.magnitude - sm1.magnitude);
            result.isNegative = sm2.isNegative;
            result.magnitude = sm_diff;

        } else {
            sm_diff = 0;
            result.isNegative = false;
            result.magnitude = sm_diff;

        }
    } else {
        sm_diff = (sm1.magnitude + sm2.magnitude);
        if (sm_diff > ((1U << 16) - 1)) {
            result.magnitude = ((1U << 16) - 1);
        } else {
            result.magnitude = sm_diff;
        }
        result.isNegative = sm1.isNegative;
    }
    return result;
}

SignMag_t signMag_accumulate(const SignMag_t* array, size_t arraySize)
{
    SignMag_t result = {false, 0};
    for (size_t i = 0; i < arraySize; i++) {
        result = signMag_sum(result, array[i]);
    }
    return result;
}

SignMag_t signMag_read(void)

{
    SignMag_t info;

    info.isNegative = false;
    info.magnitude = 0;

    uint32_t input = getchar();

    if (input != '+' && input != '-' && (!isdigit(input))) {
        info.isNegative = true;
        info.magnitude = 0;
        return info;
    }

    if (input == '-') { // check if negative
        info.isNegative = true;
        input = getchar();
    }

    else if (input == '+') { // check if positive
        info.isNegative = false;
        input = getchar();
    }

    if (!isdigit(input)) {
        info.isNegative = true;
        info.magnitude = 0;
        return info;
    }

    while (isdigit(input)) {
        uint32_t digit = input - '0';

        if (info.magnitude > (MAX_MAGNITUDE - digit) / 10) {
            info.magnitude = MAX_MAGNITUDE;
        } else {
            info.magnitude = info.magnitude * 10 + digit;
        }

        input = getchar();

    }

    return info;
}

bool signMag_max(SignMag_t* num1, SignMag_t* num2, SignMag_t** max)

{
    if (num1->isNegative != num2->isNegative) { //not the same side
        if(num1->isNegative == false) {
            *max = num1;
        } else {
            *max = num2;
        }

    } else { // same sign
        if (num1->isNegative == false) { //both positive

            if (num1->magnitude >= num2->magnitude) {
                *max = num1;
            } else if (num1->magnitude < num2->magnitude) {
                *max = num2;
            }

        } else { //both negative
            if (num1->magnitude >= num2->magnitude) {
                *max = num2;
            } else if (num1->magnitude < num2->magnitude) {
                *max = num1;
            }
        }

    }
    if ((num1->magnitude >= MAX_MAGNITUDE) || (num2->magnitude >= MAX_MAGNITUDE)) {
        return true;
    } else {
        return false;
    }
}