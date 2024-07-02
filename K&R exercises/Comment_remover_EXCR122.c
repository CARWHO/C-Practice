#include <stdio.h>
#include <string.h>

void comment_remover(char * program) {

        char program_no_comment[1000];
        int i = 0;
        int j = 0;

        while (program[i] != '\0') { 
            if (program[i] == '\\')
                break;
            else
                program_no_comment[i] = program[i];
            i++;

        }
        printf("%s\n", program_no_comment);
}

int main() {

        char program[1000];

        printf("Enter a line of code and I will remove the comments from it: ");
        fgets(program, sizeof(program), stdin);
        comment_remover(program);
}