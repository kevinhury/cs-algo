#ifndef binarysearch_h
#define binarysearch_h

#include <stdio.h>

typedef int data_t;

/**
 * Binary Search algorithm.
 *
 * @param arr Pointer to an array of data_t.
 * @param size The array size.
 * @param value Value to search in the array. Returns -1 if not found.
 *
 * @return The index of the given value. -1 if not found.
 *
 * Example usage:
 * @code
 *    binarysearch(array_pointer, 10, 2);
 * @endcode
 */
int binarysearch(data_t *arr, int size, data_t value);

#endif /* binarysearch_h */
