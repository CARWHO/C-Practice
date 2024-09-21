#include <stdio.h>
#include <stdint.h>

void reverseArray(int* ptrStart, size_t n)

{
    uint32_t temp;
    int* ptrEnd = ((ptrStart + n)-1);
    while (ptrStart < ptrEnd) {
        *ptrStart = *ptrEnd;
        *ptrEnd = temp; 
        ptrEnd--;
        ptrStart++;
    }
}

int main()

{
    int arr[5] = {1, 2, 3, 4, 5};
    reverseArray(arr, 5);
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
}