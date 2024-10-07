#include "distribution_count_sort.h"
#include <string.h>

static int get_max(const unsigned int K[], const unsigned int len);

void distribution_count_sort(const unsigned int len, const unsigned int K[], 
    unsigned int S[]) {
    unsigned int k_max = get_max(K, len);
    int count_size = k_max + 1;
    unsigned int count[count_size];
    memset(count, 0, sizeof(count));
    /* Increase count[K_j]. */
    for (unsigned int j=0; j<len; j++) {
        int kj = K[j];
        count[kj] += 1;
    }
    /* Accumulate. */
    for (unsigned int k=1; k<count_size; k++) {
        count[k] = count[k] + count[k-1];
    }
    /* Loop on j. */
    for (unsigned int j=len; j>0; j -= 1) {
        unsigned int k_j = K[j-1];
        unsigned int i = count[k_j];
        S[i-1] = k_j;
        count[k_j] = count[k_j] - 1;
    }
}

int get_max(const unsigned int K[], const unsigned int len) {
    unsigned int max = 0;
    for (unsigned int k=0; k<len; k++) {
        unsigned int val = K[k];
        if (val>max) {
            max = val;
        }
    }
    return max;
}
