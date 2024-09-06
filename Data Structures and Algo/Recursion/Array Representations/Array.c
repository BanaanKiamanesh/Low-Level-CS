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

int main()
{
    int InitContent[] = {2, 3, 4, 5, 6};
    int InitLen = sizeof(InitContent) / sizeof(InitContent[0]);

    struct Array arr1 = Create(InitContent, InitLen);
    Display(arr1);

    int idx = LinearSearch(arr1, 4);
    if (idx != -1)
        printf("Element 4 found at idx %d\n", idx);
    else
        printf("Element 4 not found\n");

    Delete(&arr1, 2);
    Display(arr1);

    Append(&arr1, 7);
    printf("\nAfter appending 7:");
    Display(arr1);

    Insert(&arr1, 2, 8);
    printf("\nAfter inserting 8 at idx 2:");
    Display(arr1);

    return 0;
}
