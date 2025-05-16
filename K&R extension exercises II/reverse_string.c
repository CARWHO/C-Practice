#include <stdio.h>
#include <string.h>

char reverse_string(char *s) {
    int i = 0;
    int j = strlen(s)-1;
    char temp;
    while(i < j) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        j--;
        i++;
    }
}

int main() {
    char strng[] = "Hello";
    reverse_string(strng);
    printf("%s", strng);
}