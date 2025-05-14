#include <stdio.h>
#include <string.h>

// return 1 if null terminated string s read the same backwards and forwards (case sensitive)

int is_palindrome(const char *s) {
    int i = 0;
    int j = strlen(s) - 1;
    int tmp;
    char[] = reversed_string;
    
    while (i < j) {
        reversed_string[i] = s[j];
        i++;
        j--;
    }
    
    i = 0;
    while (i < j) {
        if (reversed_string[i] == s[i]) {
            continue;
        } else {
            return 0;
        }
        return 1;
    }
}

// reads a string from stdin (up to length 100), prints pass or fail message

int main() {
    char buf[100];
    if (fgets(buf, sizeof(buf), stdin)) {
        if (is_palindrome(stdin) == 1) {
            printf("%s\n", "Is palidrome")
        } else {
            printf("%s\n", "Not palidrome")
        }
    }
    calls is_palidrome(string from stdin);
}