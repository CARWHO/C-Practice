/* 
 * Function: <<comment>>
 * Version Hash # 3800196120504238207003
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void swap3_cab(int32_t* x, int32_t* y, int32_t* z)

{
    int32_t temp_a = *x;
    int32_t temp_b = *y;
    int32_t temp_c = *z;

    // *x = temp_a;
    // *y = temp_b;
    // *z = temp_c;

    if (temp_a > temp_b && temp_a > temp_c) { // x is largest
        temp_a = *x;
        if (*y > *z) { // y is second largest
            temp_b = *y;
            temp_c = *z;
        } else { // z is second largest
            temp_b = *z;
            temp_c = *y;
        } 
    }

    // else if (*y > *x && *y > *z) { // y is largest
    //     *y = temp_a;
    //     if (*x > *z) { // x is second largest
    //         *x = temp_b;
    //     } else { // z is second largest
    //         *z = temp_b;
    //     }
    // }
}

int main()

{
    int32_t a = 10;
    int32_t b = 7;
    int32_t c = 5;
    swap3_cab(&a, &b, &c);
    printf("%d <= %d <= %d\n", c, a, b);
}