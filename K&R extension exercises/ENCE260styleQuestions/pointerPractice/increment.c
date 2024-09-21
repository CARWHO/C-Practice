#include <stdio.h>

void increment(int* integer1) 

{
    *integer1 += 1;
}

int main()

{
    int x = 5;
    increment(&x);
    printf("%d\n", x);
}