#include <stdio.h>

void Merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) arr[k] = L[i++];
        else              arr[k] = R[j++];

        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        
        Merge(arr, left, mid, right);
    }
}

void RecursiveMergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    RecursiveMergeSort(arr, left, mid);
    RecursiveMergeSort(arr, mid + 1, right);

    Merge(arr, left, mid, right);
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    PrintArray(arr, n);

    MergeSort(arr, 0, n - 1);
    printf("Sorted array (Iterative): ");
    PrintArray(arr, n);

    int arr2[] = {12, 11, 13, 5, 6, 7};
    RecursiveMergeSort(arr2, 0, n - 1);
    printf("Sorted array (Recursive): ");
    PrintArray(arr2, n);

    return 0;
}
