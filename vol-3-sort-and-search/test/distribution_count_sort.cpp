#include "gtest/gtest.h"

extern "C" {
    #include "distribution_count_sort.h"
}

TEST(distribution_count_tests, single_elem) {
    unsigned int K[] = {1};
    unsigned int S[] = {0};
    unsigned int S_exp[] = {1};
    unsigned int len = 1;
    distribution_count_sort(len, K, S);
    ASSERT_EQ(S[0], S_exp[0]);
}

