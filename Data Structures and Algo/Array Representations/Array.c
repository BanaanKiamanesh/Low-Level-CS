#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int len;
};

struct Array Create(int *InitContent, int InitLen)
{
    struct Array arr;
    arr.size = InitLen;
    arr.len = InitLen;
    arr.A = (int *)malloc(arr.size * sizeof(int));

    for (int i = 0; i < InitLen; i++)
        arr.A[i] = InitContent[i];

    return arr;
}

void Display(struct Array arr)
{
    printf("\nElements are\n");
    for (int i = 0; i < arr.len; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void Delete(struct Array *arr, int idx)
{
    if (idx >= 0 && idx < arr->len)
    {
        for (int i = idx; i < arr->len - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->len--;
    }
    else
        printf("Index out of bounds.\n");
}

int LinearSearch(struct Array arr, int x)
{
    for (int i = 0; i < arr.len; i++)
        if (arr.A[i] == x)
            return i;

    return -1;
}

void Append(struct Array *arr, int value)
{
    int *newArray = (int *)malloc((arr->size + 1) * sizeof(int));
    for (int i = 0; i < arr->len; i++)
        newArray[i] = arr->A[i];

    newArray[arr->len] = value;
    arr->size++;
    arr->len++;
    free(arr->A);
    arr->A = newArray;
}

void Insert(struct Array *arr, int idx, int value)
{
    if (idx >= 0 && idx <= arr->len)
    {
        int *newArray = (int *)malloc((arr->size + 1) * sizeof(int));
        for (int i = 0; i < idx; i++)
            newArray[i] = arr->A[i];

        newArray[idx] = value;
        for (int i = idx; i < arr->len; i++)
            newArray[i + 1] = arr->A[i];

        arr->size++;
        arr->len++;

        free(arr->A);
        arr->A = newArray;
    }
    else
        printf("Index out of bounds.\n");
}

int Minimum(struct Array arr)
{
    if (arr.len == 0)
    {
        printf("Array is empty.\n");
        return -1;
    }
    int min = arr.A[0];
    for (int i = 1; i < arr.len; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Maximum(struct Array arr)
{
    if (arr.len == 0)
    {
        printf("Array is empty.\n");
        return -1;
    }

    int max = arr.A[0];
    for (int i = 1; i < arr.len; i++)
        if (arr.A[i] > max)
            max = arr.A[i];

    return max;
}

int Get(struct Array arr, int idx)
{
    if (idx >= 0 && idx < arr.len)
        return arr.A[idx];
    else
        return -1;
}

void Set(struct Array *arr, int idx, int value)
{
    if (idx >= 0 && idx < arr->len)
        arr->A[idx] = value;
    else
        printf("Index out of bounds.\n");
}

int Sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.len; i++)
        sum += arr.A[i];

    return sum;
}

double Mean(struct Array arr)
{
    return (double)Sum(arr) / arr.len;
}

void Sort(struct Array *arr)
{
    // Simple Bubble Sort
    for (int i = 0; i < arr->len - 1; i++)
        for (int j = 0; j < arr->len - 1 - i; j++)
            if (arr->A[j] > arr->A[j + 1])
            {
                int temp = arr->A[j];
                arr->A[j] = arr->A[j + 1];
                arr->A[j + 1] = temp;
            }
}

void Reverse(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->len - 1; i < j; i++, j--)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

struct Array Merge(struct Array arr1, struct Array arr2)
{
    struct Array arr3;
    arr3.size = arr1.len + arr2.len;
    arr3.len = arr3.size;
    arr3.A = (int *)malloc(arr3.size * sizeof(int));

    int i = 0, j = 0, k = 0;
    while (i < arr1.len && j < arr2.len)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else
            arr3.A[k++] = arr2.A[j++];
    }
    while (i < arr1.len)
        arr3.A[k++] = arr1.A[i++];
    while (j < arr2.len)
        arr3.A[k++] = arr2.A[j++];

    return arr3;
}

int main()
{
    int InitContent[] = {18, 20, 11, 3, 3, 6, 17};
    int InitLen = sizeof(InitContent) / sizeof(InitContent[0]);

    struct Array arr1 = Create(InitContent, InitLen);
    Display(arr1);

    int idx = LinearSearch(arr1, 4);
    if (idx != -1)
        printf("Element 4 found at index %d\n", idx);
    else
        printf("Element 4 not found\n");

    Delete(&arr1, 2);
    Display(arr1);

    Append(&arr1, 7);
    printf("\nAfter appending 7:");
    Display(arr1);

    Insert(&arr1, 2, 8);
    printf("\nAfter inserting 8 at index 2:");
    Display(arr1);

    printf("\nMinimum value: %d\n", Minimum(arr1));
    printf("Maximum value: %d\n", Maximum(arr1));

    int value = Get(arr1, 3);
    if (value != -1)
        printf("Value at index 3: %d\n", value);

    Set(&arr1, 3, 10);
    printf("\nAfter setting index 3 to 10:");
    Display(arr1);

    printf("\nSum of elements: %d\n", Sum(arr1));
    printf("Mean of elements: %.2f\n", Mean(arr1));

    Sort(&arr1);
    printf("\nAfter sorting:");
    Display(arr1);

    Reverse(&arr1);
    printf("\nAfter reversing:");
    Display(arr1);

    int InitContent2[] = {1, 4, 9, 15};
    int InitLen2 = sizeof(InitContent2) / sizeof(InitContent2[0]);

    struct Array arr2 = Create(InitContent2, InitLen2);

    struct Array arr3 = Merge(arr1, arr2);
    printf("\nAfter merging arr1 and arr2:");
    Display(arr3);

    return 0;
}
