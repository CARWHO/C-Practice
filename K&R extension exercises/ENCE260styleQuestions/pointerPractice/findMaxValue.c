#include <stdio.h>
#include <stdint.h>

int findMax(int* element, size_t n) 

{
    int32_t max = 0;
    int32_t i = 0;

    while (i < n) {
        if (*element > max) {
            max = *element;
            element++;
            i++;
            // printf("max [%d] at %d\n", max, i);
            // printf("element %d\n", *element);
            
        } else {
            element++;
            i++;
            // printf("max [%d] at %d\n", max, i);
            continue;
        }
    }
    return max;
}

int main()

{
    int arr[5] = {99, 25, 3, 42, 15};
    int max_value = findMax(arr, 5);
    printf("Max value: %d\n", max_value);
}