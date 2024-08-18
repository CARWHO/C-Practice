#include <stdio.h>
#include <string.h>

size_t readString(char* string, size_t maxStringLength) //read name from file using stdin
{
    //size_t maxStringLength = 80;
    size_t count = 0;
    char chr;
    do {
        chr = getchar();
        if (chr != EOF && chr != '\n') {
            *(string++) = chr;
            count++;
        }
    } while (chr != EOF && chr != '\n' && count < maxStringLength);
    *string = '\0';
    return count;
}

FILE* openInputFile(const char* filename)
{
    char mode[] = "r";
    FILE* aFile;
    aFile = fopen(filename, mode);
    if (aFile != NULL) { 
        return aFile;
    } else {
        printf("Input file can't be opened");
        return NULL;
    }
    
}

int main() //gets user input
{
    int maxStringLength = 80;
    char chr;
    char filename[maxStringLength];
    int count = 0;
    char current_char;

    readString(filename, maxStringLength);
    chr = getchar();
    FILE* file = openInputFile(filename);
    if (file == NULL) {
        return 1; 
    }


    while ((current_char = fgetc(file)) != EOF) {
        if (current_char == chr) {
            count++;
        }

    }

    fclose(file);
    printf("%d", count);
    return 0;


}

