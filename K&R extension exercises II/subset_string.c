#include <stdio.h>
#include <string.h>

int find_substr(const char *s, const char *substr) {

    int i = 0;
    int j = 0;

    int strlength = strlen(s);

    while (i < strlength) {
        if (s[i] != substr[j]) {
            i++;
        } else {
            j = 0;
            while (substr[j] != '\0' && s[i + j] == substr[j] ) {
                j++;
            }
            if (substr[j] == '\0') {
                return i;
            }
            i++;
            j = 0;
        }
    }
    return -1;
}

int main() {
    char buffer[100];
    char pattern[100];

    fgets(buffer, sizeof(buffer), stdin);
    fgets(pattern, sizeof(pattern), stdin);

    size_t blen = strlen(buffer);
    if (blen > 0 && buffer[blen-1] == '\n') {
        buffer[blen-1] = '\0';
    }

    size_t plen = strlen(pattern);
    if (plen > 0 && pattern[plen-1] == '\n') {
        pattern[plen-1] = '\0';
    }

    int value = find_substr(buffer, pattern);

    if (value >= 0) {
        printf("Found substring at index: %d", value);
    } else {
        printf("%s not found", pattern);
    }

    return 0;
    
}