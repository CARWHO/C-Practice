#include <stdio.h>
#include <stdint.h>

void swap_elements(int* a, int* b)

{
    uint32_t temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()

{
    int arr[3] = {1, 2, 3};
    swap_elements(&arr[0], &arr[2]);
    printf("%d %d %d\n", arr[0], arr[1], arr[2]);
}