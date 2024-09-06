#include <iostream>
using namespace std;

// Diagonal Matrix
class Matrix
{
private:
    int *A;
    int n;

public:
    Matrix(int arr[], int size)
    {
        n = size;
        A = new int[n];
        for (int i = 0; i < n; i++)
            A[i] = arr[i];
    }

    void Set(int i, int j, int x)
    {
        if (i == j)
            A[i - 1] = x;
    }

    int Get(int i, int j)
    {
        if (i == j)
            return A[i - 1];
        else
            return 0;
    }

    void Display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    cout << A[i] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    Matrix m(arr, size);

    cout << "Matrix:" << endl;
    m.Display();

    cout << "\nElement at (2,2): " << m.Get(2, 2) << endl;

    return 0;
}
