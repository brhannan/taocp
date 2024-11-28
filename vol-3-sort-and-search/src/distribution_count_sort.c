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

int initialize_count_array(unsigned int count[], size_t size) {
    if (size > SIZE_MAX / sizeof(unsigned int)) {
        return -1;
    }
    memset(count, 0, size * sizeof(unsigned int));
    return 0;
}

void populate_count_array(const int input[], unsigned int count[], unsigned int len) {
    for (unsigned int i=0; i<len; i++) {
        count[input[i]] += 1;
    }
}

void accumulate_counts(unsigned int count[], size_t size) {
    for (unsigned int i = 1; i < size; i++) {
        count[i] += count[i - 1];
    }
}

void sort_input_array(const int input[], int output[], unsigned int count[], unsigned int length) {
    for (unsigned int i = length; i > 0; i--) {
        int value = input[i - 1];
        unsigned int position = count[value];
        output[position - 1] = value;
        count[value]--;
    }
}

int distribution_count_sort(const unsigned int len, const int K[], int S[]) {
    if (K==NULL || S==NULL || len==0) {
        return -1;
    }
    int k_max = get_max(K, len);
    if (k_max < 0) {
        return -1;
    }
    size_t count_size = (size_t)k_max + 1;
    unsigned int count[count_size];
    if (count_size > SIZE_MAX / sizeof(unsigned int)) {
        return -1;  // Error code for overflow
    }
    if (initialize_count_array(count, count_size) != 0) {
        return -1;
    }
    populate_count_array(K, count, len);
    accumulate_counts(count, count_size);
    sort_input_array(K, S, count, len);
    return 0;
}
