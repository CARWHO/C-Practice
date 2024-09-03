#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

#include "signMag.h"

#define MAX_MAGNITUDE ((1U << (sizeof(uint16_t) * 8)) - 1)

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

int main()

{
    SignMag_t sm1 = {true, 3};
    SignMag_t sm2 = {true, 5};
    SignMag_t* max = NULL;
    bool sat = signMag_max(&sm1, &sm2, &max);
    printf("%s %s%hu ", sat ? "(SAT)" : " ", max->isNegative ? "-" : "+", max->magnitude);
}