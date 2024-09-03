#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main ()
// reads an unknown number of integers (int16_t) from the keyboard, 
// terminated when the value -10000 is given, and stores these into a dynamically sized array.

{
    int size = 10;
    int i = 0;
    int16_t number;

    int16_t* ptr = calloc(size, sizeof(int16_t));

    scanf("%hd", &number);
    do {
        ptr[i] = number;
        i++;

        if (i >= size) {
            size *= 2;
            ptr = realloc(ptr, size*sizeof(int16_t));
        }

        scanf("%hd", &number);
    } while (number != -10000);

    ptr[i] = number;
    i++;

    printf("Numbers read = %d", i-1);
    free(ptr);
    return 0;
}