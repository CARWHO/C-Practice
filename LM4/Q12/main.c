// main.c
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "months.h"

int main(void)
{
    Month_t month = JANUARY;
    printf("%s\n", (month + 5) == JUNE ? "true" : "false");
    return 0;
}