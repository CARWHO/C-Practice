#include <stdio.h>
#include <stdint.h>

int32_t callFunc(int32_t (*func)(float), float floater)

{
    return func(floater);
}

int32_t func(float x)
{
    return (int32_t)(x * 2.5);
}

int main()

{
    float arg = 4.0;
    int32_t directRetVal = func(arg);
    int32_t indirectRetVal = callFunc(&func, arg);
    printf("%d\n", directRetVal == indirectRetVal);
}   


