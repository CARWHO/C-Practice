#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

#include "signMag.h"

#define MAX_MAGNITUDE ((1U << (sizeof(sm1.magnitude) * 8)) - 1)

SignMag_t signMag_sum(SignMag_t sm1, SignMag_t sm2)

{
    SignMag_t sumResult;
    uint32_t sum_diff;

    if (sm1.isNegative != sm2.isNegative) {
        if (sm1.magnitude > sm2.magnitude) {
            sum_diff = (sm1.magnitude - sm2.magnitude);
            sumResult.isNegative = sm1.isNegative;
            sumResult.magnitude = sum_diff;

        } else if (sm1.magnitude < sm2.magnitude) {
            sum_diff = (sm2.magnitude - sm1.magnitude);
            sumResult.isNegative = sm2.isNegative;
            sumResult.magnitude = sum_diff;

        } else {
            sum_diff = 0;
            sumResult.isNegative = false;
            sumResult.magnitude = sum_diff;

        }
    } else {
        sum_diff = (sm1.magnitude + sm2.magnitude);
        if (sum_diff > MAX_MAGNITUDE) {
            sumResult.magnitude = MAX_MAGNITUDE;
        } else {
            sumResult.magnitude = sum_diff;
        }
        sumResult.isNegative = sm1.isNegative;
    }
    return sumResult;
}

// Helper function to print test results
void print_test_result(const char* test_name, SignMag_t result, bool expected_isNegative, unsigned int expected_magnitude) {
    printf("%s: Result - isNegative: %d, magnitude: %u | Expected - isNegative: %d, magnitude: %u\n",
           test_name, result.isNegative, result.magnitude, expected_isNegative, expected_magnitude);
}

int main() {
    // Test case 1: Both positive, simple addition
    SignMag_t sm1 = {false, 5};
    SignMag_t sm2 = {false, 10};
    SignMag_t result = signMag_sum(sm1, sm2);
    print_test_result("Test 1", result, false, 15);
    assert(result.isNegative == false && result.magnitude == 15);

    // Test case 2: Both negative, simple addition
    sm1 = (SignMag_t){true, 3};
    sm2 = (SignMag_t){true, 4};
    result = signMag_sum(sm1, sm2);
    print_test_result("Test 2", result, true, 7);
    assert(result.isNegative == true && result.magnitude == 7);

    // Test case 3: Different signs, sm1 > sm2
    sm1 = (SignMag_t){false, 10};
    sm2 = (SignMag_t){true, 4};
    result = signMag_sum(sm1, sm2);
    print_test_result("Test 3", result, false, 6);
    assert(result.isNegative == false && result.magnitude == 6);

    // Test case 4: Different signs, sm1 < sm2
    sm1 = (SignMag_t){true, 5};
    sm2 = (SignMag_t){false, 7};
    result = signMag_sum(sm1, sm2);
    print_test_result("Test 4", result, false, 2);
    assert(result.isNegative == false && result.magnitude == 2);

    // Test case 5: Different signs, equal magnitudes
    sm1 = (SignMag_t){true, 8};
    sm2 = (SignMag_t){false, 8};
    result = signMag_sum(sm1, sm2);
    print_test_result("Test 5", result, false, 0);
    assert(result.isNegative == false && result.magnitude == 0);

    // Test case 6: Addition with overflow
    sm1 = (SignMag_t){false, MAX_MAGNITUDE - 1};
    sm2 = (SignMag_t){false, 2};
    result = signMag_sum(sm1, sm2);
    print_test_result("Test 6", result, false, MAX_MAGNITUDE);
    assert(result.isNegative == false && result.magnitude == MAX_MAGNITUDE);

    printf("All tests passed successfully.\n");
    return 0;
}
