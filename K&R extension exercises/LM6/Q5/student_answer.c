#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char* skipping(const char* string, size_t n)
//takes a C string as input and returns a new 
//dynamically-allocated C string containing every second character of string starting with the first one.

{
    int i = 0;
    char* ptr = calloc(((n+1)/2 + 1), sizeof(char));
    for (int j = 0; j<n; i++, j+=2) {
        ptr[i] = string[j];
    }
    ptr[i] = '\0';

    return ptr;
}

int main()

{
    char* s = skipping("0123456789", 10);
    printf("%s\n", s);
    free(s);
}