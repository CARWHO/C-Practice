#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void insertSorted(int* array, size_t n, int integer, int** newArray, size_t* newSize)

{
    *newArray = calloc(n+1, sizeof(int32_t)); // allocates enough memory for array
    *newSize = n + 1;

    
    int32_t* ptrOld = array; // ptr to old array
    int32_t* ptrNew = *newArray; // position to new array

    while (ptrOld < array + n && *ptrOld < integer) {
        *ptrNew++ = *ptrOld++;
    }

    *ptrNew++ = integer;
    
    while (ptrOld < array + n) {
            *ptrNew++ = *ptrOld++;
    }
}

int main()
{
    int* arr = malloc(5 * sizeof(int));
    arr[0] = 1; arr[1] = 3; arr[2] = 5; arr[3] = 7; arr[4] = 9;
    size_t new_size;
    int* new_arr;
    insertSorted(arr, 5, 6, &new_arr, &new_size); 
    for(size_t i = 0; i < new_size; i++) {
        printf("%d ", new_arr[i]); 
    }
    free(arr); 
    free(new_arr); 
    
    return 0;
}
