#include <stdio.h>
#include "comparison_count.h"

int main() {    
    int K[] = {503, 87, 512, 061, 908, 170, 897, 275, 653, 426, 154, 509, 
        612, 677, 765, 703};
    int len = sizeof(K) / sizeof(K[0]);
    unsigned int count[len];
    
    comparison_count(len, K, count);
    
    printf("COUNT =");
    for (unsigned int q=0; q<len; q++) {
        printf(" %i", count[q]);
    }
    printf("\n");

    return 0;
}