#include "quicksort.h"


void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int partition(data_t *arr, int low, int high)
{
    int pivot, i, j;
    pivot = arr[high];
    i = low - 1;
    
    for (j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    
    return i + 1;
}

void quicksort(data_t *arr, int low, int high)
{
    if (low >= high) return;
    
    int part = partition(arr, low, high);
    
    quicksort(arr, low, part - 1);
    quicksort(arr, part + 1, high);
}

