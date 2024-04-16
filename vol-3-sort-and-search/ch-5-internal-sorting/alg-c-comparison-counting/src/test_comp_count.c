#include <stdio.h>
#include <stdbool.h>
#include "comparison_count.h"

bool test_simple_array();
bool are_arrays_equal(unsigned int act[], unsigned int exp[], unsigned int len);
bool test_example_c();

int main() {
    int out;
    bool test_suite_success = true;

    bool test_simple_array_passed = test_simple_array();
    test_suite_success = test_suite_success && test_simple_array_passed;

    bool test_example_c_passed = test_example_c();
    test_suite_success = test_suite_success && test_example_c_passed;

    if (test_suite_success) {
        printf("All tests passed.\n");
        out = 0;
    } else {
        printf("Test suite failed.\n");
        out = 1;
    }
    return out;
}

bool test_simple_array() {
    int K[] = {3, 2, 1};
    unsigned int count[] = {0, 0, 0};
    unsigned int count_exp[] = {2, 1, 0};
    int len = sizeof(K) / sizeof(K[0]);
    comparison_count(len, K, count);
    bool passed = are_arrays_equal(count, count_exp, len);
    if (!passed) {
        printf("test_simple_array failed.\n");
    }
    return passed;
}

/* Reproduce the example from Sect. 5.2 Tab. 1. */
bool test_example_c() {
    int K[] = {503, 87, 512, 061, 908, 170, 897, 275, 653, 426, 154, 509, 612, 
        677, 765, 703};
    unsigned int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    unsigned int count_exp[] = {6, 1, 8, 0, 15, 3, 14, 4, 10, 5, 2, 7, 9, 11, 
        13, 12};
    int len = sizeof(K) / sizeof(K[0]);
    comparison_count(len, K, count);
    bool passed = are_arrays_equal(count, count_exp, len);
    if (!passed) {
        printf("test_example_c failed.\n");
    }
    return passed;
}

bool are_arrays_equal(unsigned int act[], unsigned int exp[], unsigned int len) {
    bool equal = true;
    for (unsigned int k=0; k<len; k++) {
        if (act[k] != exp[k]) {
            equal = false;
            printf("Expected element %u to equal %u. Instead it was %u.\n", 
                k, exp[k], act[k]);
        }
    }
    return equal;
}