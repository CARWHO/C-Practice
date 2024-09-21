#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int64_t* newCopy(void* array, size_t numElements)   

{
    int64_t* ptr = (int64_t*)calloc(numElements, sizeof(int64_t));
    // free(ptr);
    int64_t* inputArray = (int64_t*) array;

    for (int i = 0; i < numElements; i++) {
        ptr[i] = inputArray[i];
    }

    return ptr;

}

int main()
{
    int64_t array[3] = {1, 2, 3};
    int64_t* copy = newCopy(array, 3);
    array[1] = 4;
    for (size_t i = 0; i < 3; i++) {
        printf("%lld\n", copy[i]);
    }
}