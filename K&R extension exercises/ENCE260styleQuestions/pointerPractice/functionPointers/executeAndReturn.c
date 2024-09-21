#include <stdio.h>
#include <stdint.h>

int32_t executeAndReturn(int8_t (*func)(int32_t a, int32_t b), int32_t a, int32_t b)

{
    return func(a,b);
}

int8_t func(int32_t a, int32_t b)
{
    return (a > b) ? 1 : -1;
}

int main()

{
    int32_t arg1 = 5, arg2 = 10;
    int8_t directRetVal = func(arg1, arg2);
    int8_t indirectRetVal = executeAndReturn(&func, arg1, arg2);
    printf("%d\n", directRetVal == indirectRetVal);
}