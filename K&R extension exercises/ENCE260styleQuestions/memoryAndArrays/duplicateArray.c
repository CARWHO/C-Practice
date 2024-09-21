#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int* duplicateArray(int* array, size_t numElements)

{
    int* newArray = calloc(numElements, sizeof(int));
    for (int i = 0; i < numElements; i++) {
        newArray[i] = array[i];
    }
    return newArray;
}

int main() {
    int array[4] = {1, 2, 3, 4};
    int* copy = duplicateArray(array, 4);
    array[1] = 5;
    for (size_t i = 0; i < 4; i++) {
        printf("%d\n", copy[i]);
    }
    free(copy);
    return 0;
}