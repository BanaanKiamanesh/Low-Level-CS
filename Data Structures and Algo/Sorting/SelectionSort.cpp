#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;

        swap(arr[minIdx], arr[i]);
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
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    PrintArray(arr, n);
    return 0;
}
