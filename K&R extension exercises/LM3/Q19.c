#include <stdio.h>
#include <stdint.h>

void intProcessing(int32_t integer, size_t* count, int32_t* array) 
{
    if (*count < 100 && integer != -1) {
        array[*count] = integer;
        (*count)++;
    }
}

void input() 
{
    int32_t array[100]; 
    int integer;
    size_t count = 0;

    do {
        scanf("%d", &integer);
        if (integer != -1) {
            intProcessing(integer, &count, array);
        }
    } while (count < 100 && integer != -1);
    
    printf("%zu numbers entered\n", count);
    for (size_t i = 0; i < count; i++) {
        printf("%d\n", array[i]);
    }
}

int main() 
{
    input();
    return 0;
}
