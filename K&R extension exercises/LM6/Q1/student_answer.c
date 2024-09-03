#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void) 

{
    // uint64_t number;
    uint64_t* ptr = malloc(sizeof(uint64_t));
    scanf("%lu", ptr);

    // *ptr = number;

    printf("%lu", *ptr);

    free(ptr);
}