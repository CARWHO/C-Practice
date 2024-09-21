#include <stdio.h>
#include <stdint.h>

size_t myIndex(int16_t arr[], int16_t* element)

{
    return element - arr;
}

int main()

{
    int16_t data[30];
    int16_t* p = &data[17];
    printf("Index is %zu\n", myIndex(data, p));
}