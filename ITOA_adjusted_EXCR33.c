#include <stdio.h>
#include <string.h>

void reverse(char s[]) { // I didnt write this
    int length = strlen(s);
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

void int_to_string(n, width) {

    int i = 0;
    char s[1000];
    int sign;

            if ((sign = n) < 0)    /* record sign */
                n = -n;              /* make n positive */
            i = 0;
            do {    /* generate digits in reverse order */
                s[i++] = n % 10 + '0';     /* get next digit */
            } while ((n /= 10) > 0); /* delete it */
            if (sign < 0)
                s[i++] = '-';
            s[i] = '\0';
            while (i < width)
                s[i++] = ' ';
            reverse(s);

            printf("%s", s);

}

int main() {

int n;
int width;

    printf("Enter a integer, I will turn it into a string: ");
    scanf("%d", &n);
    printf("Enter a width (numerically) you want before the integer turned string: ");
    scanf("%d", &width);

    int_to_string(n);
}