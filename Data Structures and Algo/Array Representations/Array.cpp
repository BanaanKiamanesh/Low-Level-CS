#include <cstdlib>
#include <iostream>

class Array
{
public:
    int *A;
    int size;
    int len;

    Array(int *InitContent, int InitLen)
    {
        size = InitLen;
        len = InitLen;
        A = (int *)malloc(size * sizeof(int));

        for (int i = 0; i < InitLen; i++)
            A[i] = InitContent[i];
    }

    ~Array() { free(A); }

    void Display()
    {
        std::cout << "[";
        for (int i = 0; i < len; i++)
            std::cout << A[i] << (i == (len - 1) ? "" : ", ");
        std::cout << "]" << std::endl;
    }

    void Delete(int idx)
    {
        if (idx >= 0 && idx < len)
        {
            for (int i = idx; i < len - 1; i++)
                A[i] = A[i + 1];
            len--;
        }
        else
            std::cout << "Index out of bounds." << std::endl;
    }

    int LinearSearch(int x)
    {
        for (int i = 0; i < len; i++)
            if (A[i] == x)
                return i;

        return -1;
    }

    void Append(int value)
    {
        int *newArray = (int *)malloc((size + 1) * sizeof(int));
        for (int i = 0; i < len; i++)
            newArray[i] = A[i];

        newArray[len] = value;
        size++;
        len++;
        free(A);
        A = newArray;
    }

    void Insert(int idx, int value)
    {
        if (idx >= 0 && idx <= len)
        {
            int *newArray = (int *)malloc((size + 1) * sizeof(int));
            for (int i = 0; i < idx; i++)
                newArray[i] = A[i];

            newArray[idx] = value;
            for (int i = idx; i < len; i++)
                newArray[i + 1] = A[i];

            size++;
            len++;

            free(A);
            A = newArray;
        }
        else
            std::cout << "Index out of bounds." << std::endl;
    }

    int Minimum()
    {
        if (len == 0)
        {
            std::cout << "Array is empty." << std::endl;
            return -1;
        }
        int min = A[0];
        for (int i = 1; i < len; i++)
            if (A[i] < min)
                min = A[i];

        return min;
    }

    int Maximum()
    {
        if (len == 0)
        {
            std::cout << "Array is empty." << std::endl;
            return -1;
        }

        int max = A[0];
        for (int i = 1; i < len; i++)
            if (A[i] > max)
                max = A[i];

        return max;
    }

    int Get(int idx)
    {
        if (idx >= 0 && idx < len)
            return A[idx];
        else
            return -1;
    }

    void Set(int idx, int value)
    {
        if (idx >= 0 && idx < len)
            A[idx] = value;
        else
            std::cout << "Index out of bounds." << std::endl;
    }

    int Sum()
    {
        int sum = 0;
        for (int i = 0; i < len; i++)
            sum += A[i];

        return sum;
    }

    double Mean() { return (double)Sum() / len; }

    void Sort()
    {
        for (int i = 0; i < len - 1; i++)
            for (int j = 0; j < len - 1 - i; j++)
                if (A[j] > A[j + 1])
                {
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
    }

    void Reverse()
    {
        int i, j;
        for (i = 0, j = len - 1; i < j; i++, j--)
        {
            // Swap
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    Array Merge(Array &arr2)
    {
        Array arr3(nullptr, len + arr2.len);
        int i = 0, j = 0, k = 0;

        while (i < len && j < arr2.len)
        {
            if (A[i] < arr2.A[j])
                arr3.A[k++] = A[i++];
            else
                arr3.A[k++] = arr2.A[j++];
        }

        while (i < len)
            arr3.A[k++] = A[i++];

        while (j < arr2.len)
            arr3.A[k++] = arr2.A[j++];

        return arr3;
    }
};

int main()
{
    int InitContent[] = {18, 20, 11, 3, 3, 6, 17};
    int InitLen = sizeof(InitContent) / sizeof(InitContent[0]);

    Array arr1(InitContent, InitLen);
    arr1.Display();

    int idx = arr1.LinearSearch(4);
    if (idx != -1)
        std::cout << "Element 4 found at index " << idx << std::endl;
    else
        std::cout << "Element 4 not found" << std::endl;

    arr1.Delete(2);
    arr1.Display();

    arr1.Append(7);
    std::cout << "\nAfter appending 7:";
    arr1.Display();

    arr1.Insert(2, 8);
    std::cout << "\nAfter inserting 8 at index 2:";
    arr1.Display();

    std::cout << "\nMinimum value: " << arr1.Minimum() << std::endl;
    std::cout << "Maximum value: " << arr1.Maximum() << std::endl;

    int value = arr1.Get(3);
    if (value != -1)
        std::cout << "Value at index 3: " << value << std::endl;

    arr1.Set(3, 10);
    std::cout << "\nAfter setting index 3 to 10:";
    arr1.Display();

    std::cout << "\nSum of elements: " << arr1.Sum() << std::endl;
    std::cout << "Mean of elements: " << arr1.Mean() << std::endl;

    arr1.Sort();
    std::cout << "\nAfter sorting:";
    arr1.Display();

    arr1.Reverse();
    std::cout << "\nAfter reversing:";
    arr1.Display();

    int InitContent2[] = {1, 4, 9, 15};
    int InitLen2 = sizeof(InitContent2) / sizeof(InitContent2[0]);

    Array arr2(InitContent2, InitLen2);

    Array arr3 = arr1.Merge(arr2);
    std::cout << "\nAfter merging arr1 and arr2:";
    arr3.Display();

    return 0;
}
