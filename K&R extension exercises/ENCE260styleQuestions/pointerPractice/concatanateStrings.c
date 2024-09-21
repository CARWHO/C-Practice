#include <stdio.h>
#include <stdint.h>

void stringConcat(char* result, const char* str1, const char* str2)

{
    while (*str1 != '\0') {
        *result = *str1;
        result++;
        str1++;
    }

    while (*str2 != '\0') {
        *result = *str2;
        result++;
        str2++;
        // printf("test");
    } 
    *result = '\0';
}

int main()

{
    const char str1[] = "Hello, ";
    const char str2[] = "World!";
    char result[50];
    stringConcat(result, str1, str2);
    printf("%s\n", result);
}