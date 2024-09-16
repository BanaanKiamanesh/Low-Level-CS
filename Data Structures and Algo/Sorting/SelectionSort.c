#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) 
            if (arr[j] < arr[minIdx])
                minIdx = j;

        swap(&arr[minIdx], &arr[i]);
    }
}

void PrintArray(int arr[], int n)
{
    printf("[");
    for (int i = 0; i < n; ++i)
        printf((i == (n - 1)) ? "%d" : "%d, ", arr[i]);
    printf("]\n");
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 64};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    PrintArray(arr, n);
    return 0;
}
