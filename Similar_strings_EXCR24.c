#include <stdio.h>
#include <string.h>

void compare_string(char * s1 , char * s2) {

    int i = 0;
    int j = 0;
    int k = -1; //location of first similarity 

    while (s1[i] != '\0') {
        
        if (s1[i] == s2[j]) {
            k = i;
            break;
        }
        else {
            i++;
            j++;
        } 

}

if (k != -1) {
        printf("First similarity is at index: %d\n", k);
        printf("The character is: %c\n", s1[k]);
    }
    else    
        printf("No similar characters");

    }

int main(){

    char s1[1000];
    char s2[1000];

    printf("Input two sentences seperated my commas, I will tell you where the character similarity is. \n");

    printf("Input your first sentence: ");
    fgets(s1, sizeof(s1), stdin);

    printf("Input your second sentence: ");
    fgets(s2, sizeof(s2), stdin);

    compare_string(s1,s2);
}