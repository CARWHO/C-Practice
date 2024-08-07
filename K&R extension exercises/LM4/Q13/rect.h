// RECT.H
#include <stdint.h>
#include <stdbool.h>

#ifndef RECT_H
#define RECT_H

typedef struct {
    uint32_t width, height;

} Rect_t;

void rect_set(Rect_t* rect, uint32_t width, uint32_t height); // I dont undertand this 
uint32_t rect_area(const Rect_t* rect);
uint32_t rect_perimeter(const Rect_t* rect);

#endif // RECT.H

