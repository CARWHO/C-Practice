#include "rect.h"

void rect_set(Rect_t* rect, uint32_t width, uint32_t height)

{
    rect->width = width;
    rect->height = height;
}

uint32_t rect_area(const Rect_t* rect)

{
    uint32_t area;
    area = rect->height * rect->width;
    return area;
}

uint32_t rect_perimeter(const Rect_t* rect)

{
    uint32_t perim;
    perim = (rect->width * 2 + rect->height * 2);
    return perim;
}

