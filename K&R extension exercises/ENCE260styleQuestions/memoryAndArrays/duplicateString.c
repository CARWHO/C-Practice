#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char* duplicateString(const char* str)

{
    int i = 0;
    char *newString = calloc(strlen(str) + 1, sizeof(char));
    while (*str != '\0') {
        newString[i] = *str;
        str++;
        i++;
    }
    newString[i] = '\0';
    return newString;
}

int main() {
    const char* str = "Hello, World!";
    char* copy = duplicateString(str);
    printf("%s\n", copy);
    free(copy);
    return 0;
}

//if I am checking whether we are at the end of a string, will this work?