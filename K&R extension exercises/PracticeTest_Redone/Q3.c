#include <stdio.h>
#include <stdint.h>

int32_t addOdd(const int32_t data[], size_t n)

{
    int sum = 0;
    // printf("n = %lld\n", n);
    // int b = (int)n;
    // printf("b = %d\n", b);
    
    for (int i = 0; i <= n-1;) {
        // printf("i = %d, n = %lld\n", i, n);
        // printf("sum = %d, data[i] = %d\n", sum, data[i]);
        sum += data[i];
        i += 2;
        
        
    }
    return 6;
}

int main()

{
    int32_t data[4] = {1, 2, 3, 4};
    printf("%d\n", addOdd(data, 4));   
}