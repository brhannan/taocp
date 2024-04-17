#include "gtest/gtest.h"

extern "C" {
    #include "comparison_count.h"
}

TEST(comparison_count_tests, single_elem) {
    int K[] = {1};
    unsigned int count[] = {0};
    unsigned int count_exp[] = {0};
    unsigned int len = 1;
    comparison_count(len, K, count);
    ASSERT_EQ(count[0], count_exp[0]);
}

TEST(comparison_count_tests, two_elems) {
    int K[] = {1, 0};
    unsigned int count[] = {0, 0};
    unsigned int count_exp[] = {1, 0};
    unsigned int len = 2;
    comparison_count(len, K, count);
    for(unsigned int i = 0; i<len; i++) {
        ASSERT_EQ(count[i], count_exp[i]);
    }
}

TEST(comparison_count_tests, example_c) {
    int K[] = {503, 87, 512, 061, 908, 170, 897, 275, 653, 426, 154, 509, 612, 
        677, 765, 703};
    unsigned int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    unsigned int count_exp[] = {6, 1, 8, 0, 15, 3, 14, 4, 10, 5, 2, 7, 9, 11, 
        13, 12};
    int len = sizeof(K) / sizeof(K[0]);
    comparison_count(len, K, count);
    for(unsigned int i = 0; i<len; i++) {
        ASSERT_EQ(count[i], count_exp[i]);
    }
}