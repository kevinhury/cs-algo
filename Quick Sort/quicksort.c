#include "quicksort.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(data_t *arr, int low, int high)
{
    int pivot = arr[(low + high) / 2];
    while (low <= high)
    {
        while (arr[low] < pivot)
            low++;
        while (arr[high] > pivot)
            high--;
        if (low <= high) {
            swap(&arr[low], &arr[high]);
            low++;
            high--;
        }
    }
    return low;
}

void quicksort(data_t *arr, int low, int high)
{
    if (low >= high) return;
    
    int index = partition(arr, low, high);
    quicksort(arr, low, index - 1);
    quicksort(arr, index + 1, high);
}

