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
    SignMag_t info;
    info.isNegative = isNegative;
    info.magnitude = magnitude;
    return info;
}

void signMag_print(SignMag_t value)

{
    if (value.isNegative) {
        printf("-%d", value.magnitude);
    } else {
        printf("%d", value.magnitude);
    }
}

bool signMag_max(SignMag_t* num1, SignMag_t* num2, SignMag_t** max) {

    if (num1->magnitude > num2->magnitude) {
        *max = num1;
    } else if (num1->magnitude < num2->magnitude) {
        *max = num2;
    } else {  
        if (num1->isNegative == false && num2->isNegative == true) {  
            *max = num1;
        } else if (num1->isNegative == true && num2->isNegative == false) {  
            *max = num2;
        } else {  
            *max = num1;
        }
    }

    if ((num1->magnitude == MAX_MAGNITUDE) || (num2->magnitude == MAX_MAGNITUDE)) {
        return true;
    }

    return false;
}

SignMag_t* arrayMax(SignMag_t* array, size_t size, bool (*func)(SignMag_t*, SignMag_t*, SignMag_t**))

{
    if (size == 0) return NULL;

    SignMag_t* max = &array[0];

    for (int i = 0; i < size; i++) {
        func(max, &array[i], &max);
    }

    return max;
}

int main()

{
    SignMag_t array[] = {signMag_init(true, 50), signMag_init(false, 50), signMag_init(false, 1)};

    SignMag_t* max = arrayMax(array, 3, &signMag_max);
    printf("Max of Numbers: ");
    signMag_print(*max);    
}