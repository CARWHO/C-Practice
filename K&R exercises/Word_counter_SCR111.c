#include <stdio.h>
#include <string.h>

void sentence_spacer(char * sentence) {

    int nl = 0, nc = 0, nw = 0;
    int i = 0; 
    int inword = 0;
    
    while (sentence[i] != '\0') {
        ++nc;
            if (sentence[i] == '\n')
            ++nl;
            if (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t' || sentence[i] == ',')
                inword = 0;
            else if (inword == 0) {
                inword = 1;
                ++nw;
            }
        ++i;
    }
    printf("%d\n", nw);
    printf("%d\n", nc);
    printf("%d\n", nl);
    }

int main()  {
    
    char sentence[1000];
    printf("%s", "Enter a sentence and I will tell you how many words are in it: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence_spacer(sentence);
    }   