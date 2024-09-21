#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void findMaxInArray(int* array, size_t n, int** maxValueDest)

{
    int i = 0;
    *maxValueDest = &array[0];
    while (i < n) {
        if (array[i] > **maxValueDest) {
            **maxValueDest = array[i]; 
            printf("i = %d\n", i);
            i++;
            
        } else {
            printf("i = %d\n", i);
            i++;
        }
    }
}

int main()

{
    int array[5] = {3, 1, 9, 7, 5};
    int* maxValue = NULL;
    findMaxInArray(array, 5, &maxValue);
    if (maxValue != NULL) {
        printf("Max value: %d\n", *maxValue);
    }
}