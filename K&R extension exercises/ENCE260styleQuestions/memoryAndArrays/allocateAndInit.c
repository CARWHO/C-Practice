#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

float* allocateAndInitialize(size_t numElements, float initialValue)

{
    float* newArray = calloc(numElements, sizeof(float));
    for (int i = 0; i < numElements;) {
        newArray[i] = initialValue;
        i++;
    } 
    return newArray;
}

int main() {
    size_t numElements = 5;
    float initialValue = 3.14;
    float* array = allocateAndInitialize(numElements, initialValue);
    for (size_t i = 0; i < numElements; i++) {
        printf("%.2f\n", array[i]);
    }
    free(array);
    return 0;
}