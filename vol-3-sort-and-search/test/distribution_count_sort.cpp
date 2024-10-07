#include "gtest/gtest.h"

extern "C" {
    #include "distribution_count_sort.h"
}

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))

TEST(distribution_count_tests, single_elem) {
    unsigned int K[] = {1};
    unsigned int S[] = {0};
    unsigned int S_exp[] = {1};
    unsigned int len = ARRAY_LENGTH(K);
    distribution_count_sort(K, S, len);
    ASSERT_EQ(S[0], S_exp[0]);
}

TEST(distribution_count_tests, two_elems) {
    unsigned int K[] = {1, 0};
    unsigned int S[] = {0, 0};
    unsigned int S_exp[] = {0, 1};
    unsigned int len = ARRAY_LENGTH(K);
    distribution_count_sort(K, S, len);
    for(unsigned int i = 0; i<len; i++) {
        ASSERT_EQ(S[i], S_exp[i]);
    }
}

TEST(distribution_count_tests, five_elems) {
    unsigned int K[] = {3, 2, 5, 4, 6};
    unsigned int S[] = {0, 0, 0, 0, 0};
    unsigned int S_exp[] = {2, 3, 4, 5, 6};
    unsigned int len = ARRAY_LENGTH(K);
    distribution_count_sort(K, S, len);
    for(unsigned int i = 0; i<len; i++) {
        ASSERT_EQ(S[i], S_exp[i]);
    }
}