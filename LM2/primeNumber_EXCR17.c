#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

void printPrimesInRange(uint32_t n1, uint32_t n2)

{
    
    for  (int n = n1; n <= n2; n++) {
        bool isPrime = true;
        
        for (int i = 2; i <= n/2; i++) {
            if (n % i == 0) {
                isPrime = false;
            }
        }
        
        if (n>1 && isPrime) {
            printf("%d\n", n);
        }
        
    }
    
    
}