#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

#include "signMag.h"

#define MAX_MAGNITUDE ((1U << (sizeof(uint16_t) * 8)) - 1)

bool signMag_max(SignMag_t* num1, SignMag_t* num2, SignMag_t** max) {

    if (num1->magnitude > num2->magnitude) {
        *max = num1;
    } else if (num1->magnitude < num2->magnitude) {
        *max = num2;
    } else {  
        if (num1->isNegative == false && num2->isNegative == true) {  
            *max = num1;
        } else if (num1->isNegative == true && num2->isNegative == false) {  
            *max = num2;
        } else {  
            *max = num1;
        }
    }

    if ((num1->magnitude == MAX_MAGNITUDE) || (num2->magnitude == MAX_MAGNITUDE)) {
        return true;
    }

    return false;
}

void test_case_1() {
    SignMag_t num1 = { .magnitude = 500 };
    SignMag_t num2 = { .magnitude = 300 };
    SignMag_t* max = NULL;

    bool result = signMag_max(&num1, &num2, &max);

    assert(max == &num1);
    assert(result == false);
}

void test_case_2() {
    SignMag_t num1 = { .magnitude = 200 };
    SignMag_t num2 = { .magnitude = 400 };
    SignMag_t* max = NULL;

    bool result = signMag_max(&num1, &num2, &max);

    assert(max == &num2);
    assert(result == false);
}

void test_case_3() {
    SignMag_t num1 = { .magnitude = 300 };
    SignMag_t num2 = { .magnitude = 300 };
    SignMag_t* max = NULL;

    bool result = signMag_max(&num1, &num2, &max);

    assert((max == &num1) || (max == &num2));
    assert(result == false);
}

void test_case_4() {
    SignMag_t num1 = { .magnitude = MAX_MAGNITUDE };
    SignMag_t num2 = { .magnitude = 300 };
    SignMag_t* max = NULL;

    bool result = signMag_max(&num1, &num2, &max);

    assert(max == &num1);
    assert(result == true);
}

void test_case_5() {
    SignMag_t num1 = { .magnitude = 300 };
    SignMag_t num2 = { .magnitude = MAX_MAGNITUDE };
    SignMag_t* max = NULL;

    bool result = signMag_max(&num1, &num2, &max);

    assert(max == &num2);
    assert(result == true);
}

void test_case_6() {
    SignMag_t num1 = { .magnitude = MAX_MAGNITUDE };
    SignMag_t num2 = { .magnitude = MAX_MAGNITUDE };
    SignMag_t* max = NULL;

    bool result = signMag_max(&num1, &num2, &max);

    assert((max == &num1) || (max == &num2));
    assert(result == true);
}

int main()
{
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();
    test_case_6();

    printf("All test cases passed!\n");

    return 0;
}