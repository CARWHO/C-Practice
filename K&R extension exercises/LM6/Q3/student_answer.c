#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int16_t* ramp(size_t n)
//returns a pointer to a n-element dynamically-allocated array of int16_t 
//containing the values 1, 2, 3, ... n. You may assume n is at least 1.

{
    int16_t* ptr = calloc(n, sizeof(int16_t));
        for (int i = 0; i<n; i++) {
            ptr[i] = i + 1;
        }
    return ptr;
}

int main()

{
    int16_t* data = ramp(5);
        for (size_t i = 0; i < 5; i++) {
        printf("%d ", data[i]);
        }
        free(data);
}

