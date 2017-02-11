#ifndef mergesort_h
#define mergesort_h

#include <stdio.h>

/**
 * Merge Sort algorithm.
 *
 * @param arr Pointer to an array of data_t. merge_sort will modify the given array.
 * @param low The lowest index to sort from.
 * @param high The highest index to sort to.
 *
 * Example usage:
 * @code
 *    merge_sort(array_pointer, 0, array_size - 1);
 * @endcode
 */
void merge_sort(int *arr, int low, int high);

#endif /* mergesort_h */
