#include <stdio.h>
#include <stdint.h>

typedef struct  {
    uint16_t width, height;
    void (*callback)();
} Button_t;

void clickFunc(void)
{
    puts("Button Clicked!");
}

Button_t button_init(uint16_t x, uint16_t y, uint16_t width, uint16_t height, void (*callback)(void))

{
    Button_t button_info;
    button_info.width = width;
    button_info.height = height;
    button_info.callback = callback;
    return button_info;
}

void button_click(const Button_t* button)

{
    button->callback();
}

int main(void)
{
    Button_t button = button_init(480, 320, 64, 32, &clickFunc);
    button_click(&button);
}