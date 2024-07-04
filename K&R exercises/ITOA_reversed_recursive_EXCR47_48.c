#include <stdio.h>
#include <string.h>

void recursive_reverse(char s[], int start, int end) {
    if (start > end) {
        return;
    }
    char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    
}

void reverse(char s[]) { 
    int length = strlen(s);
    int start = 0;
    int end = length - 1;
    
    recursive_reverse(s, start, end);
}


void int_to_string_recursive(int n, char s[], int *i) { // user's int gets converted char by char to a string
    if (n == 0) {
        return;
    }
    s[(*i)++] = n % 10 + '0';
    int_to_string_recursive(n / 10, s, i);
}

void int_to_string(int n, int width, char string[]) { // user's int gets sent here, then gets sent to int_to_string_recursive 
    
    int i = 0;
    int sign;
    
    if (n < 0) {
        sign = -1;
        n = -n;
    } else {
        sign = 1;
    }

    if (n == 0) { // Handle the case where n is 0
        string[i++] = '0';
    } else {
        int_to_string_recursive(n, string, &i);
    }

    if (sign < 0) {
        string[i++] = '-';
    }

    string[i] = '\0';

    while (i < width) {
        string[i++] = ' ';
    }
    
    string[i] = '\0';
    
    reverse(string);
    
}

int main() {

int n;
int width;
char string[1000];

    printf("Enter a integer, I will turn it into a string: ");
    scanf("%d", &n);
    printf("Enter a width (numerically) you want before the integer turned string: ");
    scanf("%d", &width);

    int_to_string(n, width, string);
    printf("Result: %s\n", string);
    
    return 0;
}