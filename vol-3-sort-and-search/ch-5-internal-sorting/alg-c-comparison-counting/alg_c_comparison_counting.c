/* 
 * TAOCP Ch. 5.2 Alg. C
 * Comparison counting. Sorts R1, ..., RN on keys K1, ... KN by maintaining 
 * an aux. table COUNT[1], ..., COUNT[N] to count the number of keys less than 
 * a given key. At conclusion, COUNT[j]+1 specifies the final position of record
 * R[j]. 
 */

#include <stdio.h>
#include "comparison_counting.h"

// void comparison_counting(const unsigned int len, unsigned int count[], int K[]);

int main() {
    const unsigned int arrlen = 16;
    unsigned int count[arrlen];
    int K[arrlen] = {503, 87, 512, 061, 908, 170, 897, 275, 653, 426, 154, 509, 
        612, 677, 765, 703};

    int len = sizeof(count) / sizeof(count[0]);
    
    comparison_counting(len, count, K);
    printf("COUNT =");
    for (unsigned int q=0; q<arrlen; q++) {
        printf(" %i", count[q]);
    }
    printf("\n");

    return 0;
}


// void comparison_counting(const unsigned int len, unsigned int count[], int K[]) {
//     for (unsigned int k=0; k<len-1; k++) {
//         unsigned int i = len - 1 - k;
//         for (unsigned int m=0; m<i; m++) {
//             unsigned int j = i - 1 - m;
//             if (K[i] < K[j]) {
//                 count[j] += 1;
//             } else {
//                 count[i] += 1;
//             }
//         }
//     }
// }