#include "binarysearch.h"

int binarysearch(data_t *arr, int size, data_t value)
{
    int low = 0;
    int high = size - 1;
    int middle = -1;
    int index = -1;
    
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
