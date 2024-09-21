#include <stdio.h>
#include <stdint.h>

double computeWithFunc(double (*func)(double x, double y), double x, double y)

{
    return(func(x, y));
}

double func(double x, double y)
{
    return x + y;
}

int main()

{
    double arg1 = 2.5, arg2 = 3.0;
    double directRetVal = func(arg1, arg2);
    double indirectRetVal = computeWithFunc(&func, arg1, arg2);
    printf("%f\n", directRetVal == indirectRetVal);
}