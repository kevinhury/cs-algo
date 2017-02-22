#include "insertionsort.h"

void insertion_sort(data_t *arr, size_t size)
{
    data_t value;
    int i, j;
    
    for (i = 1; i < size; i++)
    {
        value = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (value <= arr[j])
            {
                arr[j + 1] = arr[j];
                arr[j] = value;
            }
        }
    }
}

