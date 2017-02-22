#include "binarysearch.h"

size_t binarysearch(data_t *arr, size_t size, data_t value)
{
    size_t low = 0;
    size_t high = size - 1;
    size_t middle = -1;
    size_t index = -1;
    
    while(low <= high) {
        middle = low + (high - low) / 2;
        
        if (arr[middle] == value) {
            return index = middle;
        } else if (arr[middle] < value) {
            low = middle + 1;
        }
        else {
            high = middle - 1;
        }
    }
    return index;
}
