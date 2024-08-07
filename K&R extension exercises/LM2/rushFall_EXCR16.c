#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

uint32_t countRushes(float screeHeight, float rushHeight, float slideBack)

{

    int rushCount = 0;
    float currentHeight = 0;
 
    while (currentHeight < screeHeight) {
        currentHeight += rushHeight;
        if (currentHeight < screeHeight) {
            currentHeight -= slideBack;
        }
    
        rushCount++; 
    }
 
    //printf("%d", rushCount);
    return rushCount;
 
}

