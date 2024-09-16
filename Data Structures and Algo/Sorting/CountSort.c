#include <stdio.h>

void countingSort(int arr[], int n)
{
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int range = max - min + 1;
    int count[range];

    for (int i = 0; i < range; i++)  count[i] = 0;
    for (int i = 0; i < n; i++)      count[arr[i] - min]++;

    int index = 0;
    for (int i = 0; i < range; i++)
        while (count[i]-- > 0)
            arr[index++] = i + min;
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
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    PrintArray(arr, n);

    countingSort(arr, n);

    printf("Sorted array: ");
    PrintArray(arr, n);

    return 0;
}
