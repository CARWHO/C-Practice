#include <stdio.h>
#include <stdint.h>

void stringCopy(char* dest, const char* src)

{
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

int main()

{
    char src[] = "Hello, World!";
    char dest[50];
    stringCopy(dest, src);
    printf("%s\n", dest);
}

