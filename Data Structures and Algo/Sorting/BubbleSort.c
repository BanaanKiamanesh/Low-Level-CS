#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int arr[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }

        if (flag == 0)
            break;
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

    BubbleSort(arr, n);
    PrintArray(arr, n);

    return 0;
}
