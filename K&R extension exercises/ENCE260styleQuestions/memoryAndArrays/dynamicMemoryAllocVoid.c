#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint64_t* newCopy(void* array, size_t numElements)

{
    uint64_t* newArray = calloc(numElements, sizeof(uint64_t));
    for (int i = 0; i < numElements; i++) {
        newArray[i] = (uint64_t)(array);
        array++;
    }
    return newArray;
}

int main()

{
    uint64_t array[3] = {1, 2, 3};
    uint64_t* copy = newCopy(array, 3);
    array[1] = 4;
    for (size_t i = 0; i < 3; i++) {
        printf("%llu\n", copy[i]);
    }
}
