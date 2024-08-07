// main.c
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "rect.h"

int main()

{
    uint32_t width;
    uint32_t height;
    scanf("%d %d", &width, &height);

    Rect_t rect;
    rect_set(&rect, width, height);
    printf("Area = %d\n", rect_area(&rect));
    printf("Perimeter = %d\n", rect_perimeter(&rect));
}