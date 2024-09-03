#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    char random;
    int8_t junk;
} Data_t;

Data_t* newData(char random, int8_t junk)
//allocates space for a new Data_t on the heap, initialises it, and returns a pointer to it

{
    Data_t* ptr = malloc(sizeof(Data_t));
    ptr->junk = junk;
    ptr->random = random;
    return ptr;
}

void freeData(Data_t* data)
//which frees the heap-allocated variable data.

{
    free(data);
}

int main()

{
    Data_t* data = newData('A', 1);
    printf("%c %d\n", data->random, data->junk);
    freeData(data);
}