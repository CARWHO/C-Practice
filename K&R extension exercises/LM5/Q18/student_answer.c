#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef int32_t* (*Func_t)(int32_t*, size_t);

int32_t* offsetArray(int32_t* array, size_t offset){
    return array + offset;
}

int main(void)
{
    Func_t func = &offsetArray;
    
    int32_t arr[5] = {1, 2, 3, 4, 5};
    int32_t* offsetArr = (*func)(arr, 2);
    printf("%ld\n", offsetArr - arr);
}