#include <stdio.h>
#include <string.h>

// removes character c from string and returns it 

void remove_char(char *s, char c) {
    int i = 0; //read index
    int j = 0; //write index
    while(s[i] != '\0') {
        if (s[i] == c) {
            i++;
        } else {
            s[j] = s[i];
            j++;
            i++;
        }
    }
    s[j] = '\0';
}

// calls remove_char w/ char and string from stdin, prints output

int main() {
    char buffer[100];
    char ch;
    fgets(buffer, sizeof(buffer), stdin); 
    int bufferlen = strlen(buffer);  
    if (bufferlen > 0) {
        buffer[bufferlen - 1] = '\0';
    } 
    (scanf(" %c", &ch)); 
    remove_char(buffer, ch);
    printf("%s", buffer);
}