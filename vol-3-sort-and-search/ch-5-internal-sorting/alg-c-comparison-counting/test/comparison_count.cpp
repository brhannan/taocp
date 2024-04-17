#include "gtest/gtest.h"

extern "C" {
    #include "comparison_count.h"
}

TEST(comparison_count, ok) {
    int K[] = {1};
    unsigned int count[] = {0};
    unsigned int count_exp[] = {0};
    comparison_count(1, K, count);
    ASSERT_EQ(count[0], count_exp[0]);
}