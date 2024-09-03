#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void fillRamp(int16_t* data, size_t n)
//given a pointer to an already-allocated array, and which filled it with the required data.

{
    for (int i = 0; i<n; i++) {
        data[i] = i + 1;
    }
}

int main(void)

{
    int16_t* data = calloc(4, sizeof(int16_t));
    fillRamp(data, 4);
    for (size_t i = 0; i < 4; i++) {
        printf("data[%zu] = %d\n", i, data[i]);
    }
    free(data);
}