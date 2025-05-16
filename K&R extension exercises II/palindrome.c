#include <stdio.h>
#include <string.h>

// return 1 if null terminated string s read the same backwards and forwards (case sensitive)

int is_palindrome(const char *s) {
    int i = 0;
    int j = strlen(s) - 1;
    
    while (i < j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        } else {
            return 0;
        }
    }
    return 1;
}

// reads a string from stdin (up to length 100), prints pass or fail message

int main() {
    char buf[100];
    if (scanf("%99s", buf) == 1) {
        if (is_palindrome(buf) == 1) {
            printf("%s\n", "Is palidrome");
        } else {
            printf("%s\n", "Not palidrome");
        }
    }
}