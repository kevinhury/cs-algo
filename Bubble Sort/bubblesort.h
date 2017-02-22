#ifndef bubblesort_h
#define bubblesort_h

#include <stdio.h>

typedef int data_t;

/**
 * Bubble Sort algorithm.
 *
 * @param arr Pointer to an array of data_t. bubblesort will modify the given array.
 * @param size The given array size.
 *
 * Example usage:
 * @code
 *    bubblesort(array_pointer, array_size);
 * @endcode
 */
void bubblesort(data_t *arr, size_t size);

#endif /* bubblesort_h */
