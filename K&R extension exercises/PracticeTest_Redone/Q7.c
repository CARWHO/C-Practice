#include <stdio.h>
#include <stdint.h>

void swap3_acb(int16_t* x, int16_t* y, int16_t* z)
{
    int16_t temp;

    if (*x > *y) { // if x > y //swap x and y proceedure
        temp = *x; 
        *x = *y;
        *y = temp;
    }

    if (*y > *z) { // if y > z //swap y and z proceedure
        temp = *y; 
        *y = *z;
        *z = temp;
    }

    if (*z > *x) { // if y > z //swap y and z proceedure
        temp = *y; 
        *z = *x;
        *y = temp;
    }
}

int main()

{
    int16_t a = 0;
    int16_t b = 7;
    int16_t c = 10;
    swap3_acb(&a, &b, &c);
    printf("%d <= %d <= %d\n", a, c, b);
}