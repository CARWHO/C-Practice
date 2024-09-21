#include <stdio.h>
#include <stdint.h>

void swap(int **a, int **b)

{
    int temp;
    printf("double star a: %d, double star b: %d\n", **a, **b);
    temp = **a;
    **a = **b;
    **b = temp;
    printf("double star a (new): %d, double star b (new): %d\n", **a, **b);
}

int main()

{
    int x = 10, y = 20;
    int *px = &x, *py = &y;
    swap(&px, &py);
    // After swapping, px should point to y (20) and py should point to x (10)
}