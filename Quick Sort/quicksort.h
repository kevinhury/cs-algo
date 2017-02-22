#ifndef quicksort_h
#define quicksort_h

#include <stdio.h>

typedef int data_t;

/**
 * Quick Sort algorithm.
 * 
 * @param arr Pointer to an array of data_t. quicksort will modify the given array.
 * @param low The lowest index to sort from.
 * @param high The highest index to sort to.
 *
 * Example usage:
 * @code
 *    quicksort(array_pointer, 0, array_size - 1);
 * @endcode
 */
void quicksort(data_t *arr, size_t low, size_t high);

#endif /* quicksort_h */
