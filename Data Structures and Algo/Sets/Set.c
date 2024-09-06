#include <stdio.h>
#include <stdlib.h>

struct Set
{
    int *A;
    int size;
    int length;
};

struct Set *Create(int A[], int length)
{
    struct Set *set = (struct Set *)malloc(sizeof(struct Set));
    set->size = length;
    set->length = length;
    set->A = (int *)malloc(set->size * sizeof(int));
    for (int i = 0; i < length; i++)
    {
        set->A[i] = A[i];
    }
    return set;
}

void Display(const struct Set *arr)
{
    for (int i = 0; i < arr->length; i++)
        printf("%d ", arr->A[i]);
    printf("\n");
}

struct Set *Union(const struct Set *arr1, const struct Set *arr2)
{
    int i = 0, j = 0, k = 0;
    struct Set *arr3 = (struct Set *)malloc(sizeof(struct Set));
    arr3->size = arr1->length + arr2->length;
    arr3->A = (int *)malloc(arr3->size * sizeof(int));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    while (i < arr1->length)
        arr3->A[k++] = arr1->A[i++];
    while (j < arr2->length)
        arr3->A[k++] = arr2->A[j++];

    arr3->length = k;
    return arr3;
}

int main()
{
    int A1[] = {2, 9, 21, 28, 35};
    int A2[] = {2, 3, 9, 18, 28};

    struct Set *arr1 = Create(A1, sizeof(A1) / sizeof(A1[0]));
    struct Set *arr2 = Create(A2, sizeof(A2) / sizeof(A2[0]));

    Display(arr1);
    Display(arr2);

    struct Set *arr3 = Union(arr1, arr2);
    Display(arr3);

    return 0;
}
