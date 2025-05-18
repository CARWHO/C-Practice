#include <stdio.h>
#include <string.h>

//converts a string s into an integer

int my_atoi(const char *s) {

int value = 0;
int flag = 1;
int i = 0;

    if (s[i] == '+') {
        flag = 1;
        i++;
    } else if (s[i] == '-') {
        flag = -1;
        i++;
    }

    while (s[i] != '\0') {

        if (s[i] >= '0' && s[i] <= '9' ) {
            value = value * 10 + (s[i] - '0');
            i++;
        } else {
            break;
        }
    }
    value = value * flag;
    return value;
 }

int main() {
    char string[100];

    fgets(string, sizeof(string), stdin);
    int value = my_atoi(string);
    printf("%d", value);
}