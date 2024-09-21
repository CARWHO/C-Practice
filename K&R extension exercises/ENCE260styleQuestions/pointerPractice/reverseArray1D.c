#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void reverse_array(void* array, size_t numElements, size_t elementSize)

{
    // uint16_t elementSize;
    size_t temp;
    int* ptrStart = (int*)array;
    int* ptrEnd = (int*)array + (numElements - 2) * elementSize;
    
    while (ptrEnd > ptrStart) {
        temp = *ptrEnd;
        *ptrEnd = *ptrStart;
        *ptrStart = temp;
        ptrEnd -= elementSize;
        ptrStart += elementSize;
    }
    for (int i = 0; i < numElements; i++) {
    printf("New array item %i: %d\n", i + 1, ((int*)array)[i]);
}
    
}

int main()

{
    int array[5] = {1, 2, 3, 4, 5};
    reverse_array(array, 5, sizeof(int));
    // After reversing, array should be {5, 4, 3, 2, 1}
}