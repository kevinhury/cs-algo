#include "mergesort.h"

void merge(int *arr, size_t low, size_t middle, size_t high)
{
    size_t i, j, k;
    size_t lowsize = middle - low + 1;
    size_t highsize =  high - middle;

    int lowarr[lowsize], higharr[highsize];
    
    for (i = 0; i < lowsize; i++)
    {
        lowarr[i] = arr[low + i];
    }
    for (j = 0; j < highsize; j++)
    {
        higharr[j] = arr[middle + 1+ j];
    }
    
    i = 0;
    j = 0;
    k = low;
    
    while (i < lowsize && j < highsize)
    {
        if (lowarr[i] <= higharr[j]) {
            arr[k] = lowarr[i];
            i++;
        } else {
            arr[k] = higharr[j];
            j++;
        }
        k++;
    }
    
    while (i < lowsize)
    {
        arr[k] = lowarr[i];
        i++;
        k++;
    }
    while (j < highsize)
    {
        arr[k] = higharr[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, size_t low, size_t high)
{
    size_t middle;
    if (low >= high) {
        return;
    }
    middle = low + (high - low) / 2;
    
    merge_sort(arr, low, middle);
    merge_sort(arr, middle + 1, high);
    
    merge(arr, low, middle, high);
}
