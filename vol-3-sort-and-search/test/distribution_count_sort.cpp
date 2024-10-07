#include "gtest/gtest.h"

extern "C" {
    #include "distribution_count_sort.h"
}

TEST(distribution_count_tests, single_elem) {
    unsigned int K[] = {1};
    unsigned int S[] = {0};
    unsigned int S_exp[] = {1};
    unsigned int len = 1;
    distribution_count_sort(K, S, len);
    ASSERT_EQ(S[0], S_exp[0]);
}

TEST(distribution_count_tests, two_elems) {
    unsigned int K[] = {1, 0};
    unsigned int S[] = {0, 0};
    unsigned int S_exp[] = {0, 1};
    unsigned int len = 2;
    distribution_count_sort(K, S, len);
    for(unsigned int i = 0; i<len; i++) {
        ASSERT_EQ(S[i], S_exp[i]);
    }
}