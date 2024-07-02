#include <stdio.h>
#include <string.h>

void conversion(int n, char*many_lines){

    char many_lines_converted[1000] = "";
    int i = 0;
    int j = 0;
    int last_space = -1;
    
    while (many_lines[i] != '\0') { 
        if (i - last_space > n) { 
            if (last_space == -1) { 
                many_lines_converted[j++] = '\n';
                last_space = j - 1; 
            }
            else { 
                many_lines_converted[last_space] = '\n';
                j = last_space + 1;
                last_space = -1;
            }
        }      
        many_lines_converted[j++] = many_lines[i++];
    }
    many_lines_converted[j] = '\0';
    printf("%s", many_lines_converted);
        
}
        
int main() {
    int n;
    char many_lines[1000];

    printf("Input a character length 'n': "); 
    scanf("%d", &n); 
    getchar();

    printf("Now input a few lines of text as one line. I will 'fold' it into multiple lines after 'n' characters: ");
    fgets(many_lines, sizeof(many_lines), stdin); 

    conversion(n, many_lines);

    return 0;
}