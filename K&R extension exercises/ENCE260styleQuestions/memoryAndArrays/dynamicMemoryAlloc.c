#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void allocateAndFill(int32_t n, int** array)

{
    *array = malloc(n * sizeof(int32_t));
    for (int i = 0; i < n; i++) {
        (*array)[i] = i;
    }
}

int main()

{
    int* arr;
    allocateAndFill(5, &arr);
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    // Remember to free the allocated memory
    free(arr);    
}
