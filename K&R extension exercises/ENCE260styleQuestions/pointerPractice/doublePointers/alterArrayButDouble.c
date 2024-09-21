#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void set_value(int **arr, int rows, int cols, int value)

{
    int **arr_temp = arr;
    for (int i = 0; i < rows; i++) {
        int *rowPtr = *arr_temp;
        for (int i = 0; i < cols; i++) {
            *rowPtr = value;
            rowPtr++;
        }
        arr_temp++;
    }

    for (int i = 0; i < rows; i++) {               // Loop over each row
        for (int j = 0; j < cols; j++) {           // Loop over each column in the row
            printf("%d\n", arr[i][j]);                     // Set the value for each element
        }
    }
}

int main()

{
    int rows = 3, cols = 3;
    int **array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }

    set_value(array, rows, cols, 42);
    // After setting, all elements in the 2D array should be 42
}