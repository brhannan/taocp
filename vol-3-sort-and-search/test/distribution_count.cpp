#include "gtest/gtest.h"

extern "C" {
    #include "distribution_count.h"
}

TEST(distribution_count_tests, smoke) {
    int K[] = {1};
    unsigned int count[] = {0};
    unsigned int count_exp[] = {0};
    unsigned int len = 1;
    distribution_count(len, K, count);
}