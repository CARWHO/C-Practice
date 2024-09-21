#include <stdio.h>
#include <stdint.h>

float callPassedFunc(float (*func)(double), float x)

{
    return func(x);
}

float func(double x)
{
    return (float)(x * 2.5); // Only an example - could be anything.
}

int main()

{
    double arg = 4.0;
    float directRetVal = func(arg);
    float indirectRetVal = callPassedFunc(&func, arg);
    printf("%d\n", directRetVal == indirectRetVal);   
}


