#include <stdio.h>
#include <stdint.h>

void allocate_array(int **arr, int size)

{
    **arr = calloc(size, sizeof(int));
    // return *arr;
}

int main()

{
    int *array = NULL;
    int size = 5;
    allocate_array(&array, size);
    // After allocation, array should point to the memory allocated for 5 integers
}