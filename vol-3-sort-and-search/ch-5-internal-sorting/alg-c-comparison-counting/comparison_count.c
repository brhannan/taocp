#include "comparison_count.h"

void comparison_count(const unsigned int len, const int K[], unsigned int count[]) {
    for (unsigned int k=0; k<len-1; k++) {
        unsigned int i = len - 1 - k;
        for (unsigned int m=0; m<i; m++) {
            unsigned int j = i - 1 - m;
            if (K[i] < K[j]) {
                count[j] += 1;
            } else {
                count[i] += 1;
            }
        }
    }
}