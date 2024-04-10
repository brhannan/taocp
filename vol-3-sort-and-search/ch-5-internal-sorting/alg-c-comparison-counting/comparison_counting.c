#include "comparison_counting.h"

void comparison_counting(const unsigned int len, unsigned int count[], int K[]) {
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