/* 
 * Function: <<comment>>
 * Version Hash # 3780659720504238011639
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>

uint64_t scanBase9(void)

{
    int32_t result = 0;
    int32_t n = 0;
    int32_t array[6];

    int32_t chr = getchar();
    while (chr != EOF && n < 6) {
        if (chr >= '0' && chr <= '8') {
            array[n] = chr - '0';
            n++;
        }
            
        chr = getchar();
    }

    for (int i = 0; i < n; i++) {
        int exponent = (n - i - 1);
        printf("exponent: %d", exponent);
        result += array[i] * pow(9, exponent);
        printf("%d\n", result);
    }
    return result;
}

int main()

{
    uint64_t y = scanBase9();
    printf("%zu\n", y);
}