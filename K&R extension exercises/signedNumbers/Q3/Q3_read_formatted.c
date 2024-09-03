#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_MAGNITUDE ((1U << (sizeof(info.magnitude) * 8)) - 1)

#include "signMag.h"

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

int main() {
    SignMag_t val = signMag_read();
    printf("%s%hu ", val.isNegative ? "-" :"+", val.magnitude);
}