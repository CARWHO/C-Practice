#include <stdio.h>
#include <string.h>

void remove_dups(char *s) {

int i = 0;
int j = 1;
int k = 0;

    while(s[i] != '\0') {
        j = i + 1;
        while (s[j] != '\0') {
            if (s[i] == s[j]) {
                k = j;
                while (s[k] != '\0') {
                    s[k] = s[k+1];
                    k++;
                }
            } else {
                j++;
            }
        }
    i++;
    }   
}

int main() {
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    remove_dups(buffer);
    printf("%s", buffer);
}