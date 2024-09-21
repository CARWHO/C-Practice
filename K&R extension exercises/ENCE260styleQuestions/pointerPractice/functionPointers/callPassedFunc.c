#include <stdio.h>
#include <stdint.h>

uint8_t callPassedFunc(uint8_t (*func)(int64_t), int64_t integer1)

{
    return func(integer1);
}

uint8_t func(int64_t x)
{
    return x/2; //Only an example - could be anything. 
}

// ...

int main()

{
    int64_t arg = 10;
    uint8_t directRetVal = func(arg);
    uint8_t indirectRetVal = callPassedFunc(&func, arg);
    printf("%d\n", directRetVal == indirectRetVal);
}

