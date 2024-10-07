#include "distribution_count_sort.h"
#include <string.h>

static unsigned int get_max(const unsigned int K[], const unsigned int len);

void distribution_count_sort(const unsigned int K[], unsigned int S[], 
    const unsigned int len) {
    unsigned int k_max = get_max(K, len);
    unsigned int count_size = k_max + 1;
    unsigned int count[count_size];
    memset(count, 0, sizeof(count));
    for (unsigned int c=0; c<len; c++) {
        count[K[c]] += 1;
    }
    for (unsigned int i=1; i<count_size; i++) {
        count[i] += count[i-1];
    }
    for (unsigned int j=len; j>0; j--) {
        unsigned int k_j = K[j-1];
        unsigned int i = count[k_j];
        S[i-1] = k_j;
        count[k_j] = count[k_j] - 1;
    }
}

static unsigned int get_max(const unsigned int K[], const unsigned int len) {
    unsigned int max = 0;
    for (unsigned int i=0; i<len; i++) {
        unsigned int val = K[i];
        if (val>max) {
            max = val;
        }
    }
    return max;
}
