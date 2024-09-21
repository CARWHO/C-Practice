#include <stdio.h>
#include <stdint.h>

void scale_array(void* array, size_t numElements, uint64_t factor) 

{
    uint64_t* uint16_array = (uint64_t*)(array);

    for (int i = 0; i < numElements; i++) {
        uint16_array[i] = (uint16_array[i] * factor); 
        printf("%i: %lld\n", i + 1, uint16_array[i]);
    }

    for (int i = 0; i < numElements; i++) {
    printf("New array item %i: %lld\n", i + 1, uint16_array[i]);
    }
}

int main()

{
    uint64_t array[4] = {1, 2, 3, 4};
    scale_array(array, 4, 10);
    // After scaling, array should be {10, 20, 30, 40}
}