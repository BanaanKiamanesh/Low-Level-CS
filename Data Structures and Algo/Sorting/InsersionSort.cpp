#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PrintArray(int arr[], int n)
{
    cout << "[";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << ((i == n - 1) ? "" : ", ");
    cout << "]" << endl;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 64};
    int n = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(arr, n);
    PrintArray(arr, n);

    return 0;
}
