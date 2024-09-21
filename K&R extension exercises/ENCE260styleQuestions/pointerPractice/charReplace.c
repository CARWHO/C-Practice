#include <stdio.h>
#include <stdint.h>

void replaceChar(char* a, char b)

{
    *a = b;
}

int main()

{
    char c = 'a';
    replaceChar(&c, 'z');
    printf("%c\n", c);
}