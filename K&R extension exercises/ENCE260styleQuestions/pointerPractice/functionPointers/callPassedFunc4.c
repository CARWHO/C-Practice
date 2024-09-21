#include <stdio.h>
#include <stdint.h>

int32_t callPassedFunc(int32_t (*func)(uint32_t), uint32_t x) 

{
    return func(x);
}

int32_t func(uint32_t x)
{
    return (int32_t)(x - 100); // Only an example - could be anything.
}

int main()

{
    uint32_t arg = 150;
    int32_t directRetVal = func(arg);
    int32_t indirectRetVal = callPassedFunc(&func, arg);
    printf("%d\n", directRetVal == indirectRetVal);
}
