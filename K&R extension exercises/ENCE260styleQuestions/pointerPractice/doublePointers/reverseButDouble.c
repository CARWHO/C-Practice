#include <stdio.h>
#include <stdint.h>

void reverseArray(int* array, size_t n, int** startOfReversedArray)

{
    int temp;
    int* ptrStart = (int*)array;
    int* ptrEnd = (int*)(array + n - 1);

    while (ptrEnd > ptrStart) {
        temp = *ptrEnd;
        *ptrEnd = *ptrStart;
        *ptrStart = temp;
        ptrEnd--;
        ptrStart++;
    }
    *startOfReversedArray = array;
}

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    int* startOfReversedArray = NULL;

    printf("Original array:\n");
    for (size_t i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Call reverseArray function
    reverseArray(array, 5, &startOfReversedArray);

    printf("Reversed array:\n");
    for (size_t i = 0; i < 5; i++) {
        printf("%d ", startOfReversedArray[i]);
    }
    printf("\n");

    return 0;
}