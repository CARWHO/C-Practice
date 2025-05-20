#include <stdio.h>
#include <string.h>

void insert_char(char *s, char c, int pos) {

    int i = strlen(s);

    // printf("\n i = %d, j = %d, ith = %c, jth = %c", i, j, s[i], s[j]);

    while (i >= pos) {
        s[i+1] = s[i];
        i--;
        // printf("\n i = %d, j = %d, ith = %c, jth = %c", i, j, s[i], s[j]);
    }

    s[pos] = c;
}

int main() {

    char buffer[100];
    char ch;
    int shift;

    fgets(buffer, sizeof(buffer), stdin);
    scanf(" %c %d", &ch, &shift);

    if (strlen(buffer) > 0) {
        buffer[strlen(buffer) - 1] = '\0'; 
    }

    insert_char(buffer, ch, shift);
    printf("\n %s", buffer);
}