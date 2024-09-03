#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "signMag.h"

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

// int main()

// {
//     SignMag_t value = signMag_init(false, 200);
//     signMag_print(value);
//     return 0;
// }

