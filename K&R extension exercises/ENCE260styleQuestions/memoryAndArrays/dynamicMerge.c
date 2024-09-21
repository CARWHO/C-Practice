#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void mergeSortedArrays(int32_t* arr1, size_t n1, int32_t* arr2, size_t n2, int** merged_array, size_t* merged_size)

{
    *merged_size = n1 + n2;
    *merged_array = calloc(*merged_size, sizeof(int32_t)); // space for new array
    
    int32_t *ptr = *merged_array;

    int i = 0;
    int j = 0;

    while (i < n1) { // goes through first array
        printf("i = %d, n1 = %zu\n", i, n1);
        *ptr++ = *arr1++; //adds stuff from first array to newly memory allocated array
        i++;
    }

    while (j < n2)  { // same for second array
        printf("j = %d, n2 = %zu\n", j, n2);
        *ptr++ = *arr2++; // adds stuff from second array
        j++;
    }

}

int main()

{
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    int* merged_array;
    size_t merged_size;

    mergeSortedArrays(arr1, 3, arr2, 3, &merged_array, &merged_size);

    for(size_t i = 0; i < merged_size; i++) {
        printf("%d ", merged_array[i]);
    }
}