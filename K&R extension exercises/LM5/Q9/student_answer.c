#include <stdio.h>
#include <string.h>
#include <ctype.h>

FILE* openInputFile(const char* filename)
{
    char mode[] = "r";
    FILE* aFile;
    aFile = fopen(filename, mode);
    if (aFile != NULL) { 
        return aFile;
    } else {
        printf("Input file can't be opened\n");
        return NULL;
    }
}

FILE* openOutputFile(const char* filename)
{
    char mode[] = "w";
    FILE* aFile;
    aFile = fopen(filename, mode);
    if (aFile != NULL) { 
        return aFile;
    } else {
        printf("Output file can't be opened\n");
        return NULL;
    }
}

size_t readString(char* string, size_t maxStringLength) //read name from file using stdin
{
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

int main() {
    char inputFilename[80];
    char outputFilename[80];

    readString(inputFilename, 80);
    readString(outputFilename, 80);

    FILE* inputFile = openInputFile(inputFilename);
    //if (inputFile == NULL) return 1;

    FILE* outputFile = openOutputFile(outputFilename);
    //if (outputFile == NULL) {
    //     fclose(inputFile); 
    //     return 1;
    // }

    if (outputFile && inputFile) {

        int firstCharacter = 1; 
        int previousWasWhitespace = 1; 
        char currentChar;

        while ((currentChar = fgetc(inputFile)) != EOF) {
        if (firstCharacter || previousWasWhitespace) {
            fputc(toupper(currentChar), outputFile);
        } else {
            fputc(tolower(currentChar), outputFile);
        }

        previousWasWhitespace = isspace(currentChar);
        firstCharacter = 0;
        }
    }

    if (inputFile) {
        fclose(inputFile);
    }

    if (outputFile) {
        fclose(outputFile); 
    }

    return 0;
}