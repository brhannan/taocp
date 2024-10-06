#ifndef __DISTRIBUTION_COUNT_H__
#define __DISTRIBUTION_COUNT_H__

/* 
 * Sorts records R1, ..., RN on keys K1, ... KN by maintaining an aux. table COUNT[1], 
 * ..., COUNT[N] to count the number of keys less than a given key. At 
 * conclusion, COUNT[j]+1 specifies the final position of record R[j]. 
 * len is the length aux. table count and keys K.
 */
void distribution_count(const unsigned int len, const int K[], unsigned int count[]);

#endif