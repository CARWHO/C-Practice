#include <stdio.h>
#include <string.h>

// program to replace tabs with spaces  

void replacetabs(char*sentence) { // void signifies that this function returns nothing, * refers to char pointing to character //
    
    char result[1000] = ""; // string to hold resulting, altered string 
    int i = 0; // current position index in old sentence //
    int j = 0; // current position index in new sentence // 
    
    while (sentence[i] != '\0') { // loop over inputted sentence until at end of it (end @ i = \0) //
        if (sentence[i] == '\t') { // find where tabs are //
            result[j++] = ' '; // replace with spaces //
            result[j++] = ' '; // replace with spaces //
            result[j++] = ' '; // replace with spaces //
            result[j++] = ' '; // replace with spaces //
        }
        else { // if not a tab (if a letter) //
            result[j++] = sentence[i]; // keep that part of sentence //
        result[j] = '\0'; // include end marker for string //
        }
        i++; // go to next char in sentence //
        }
        
    printf("%s", sentence); 
    }

int main() {

    char sentence[1000];
    
    printf("%s" ,"Enter a sentence with tabs, I will convert them to the correect number of spaces");
    fgets(sentence, sizeof(sentence), stdin);
    replacetabs(sentence);
    
}
        