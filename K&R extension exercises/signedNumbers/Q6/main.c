#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

#include "signMag.h"

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