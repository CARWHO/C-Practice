#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) 

{
    int i = 0;
    
    while (i < argc) {
        printf("[%d] %s\n", i, argv[i]);
        i++;
        
        }
}

