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
        set->A[i] = A[i];

    return set;
}

void Display(const struct Set *arr)
{
    for (int i = 0; i < arr->length; i++)
        printf("%d ", arr->A[i]);
    printf("\n");
}

struct Set *Union(const struct Set *s1, const struct Set *s2)
{
    int i = 0, j = 0, k = 0;
    struct Set *s3 = (struct Set *)malloc(sizeof(struct Set));
    s3->size = s1->length + s2->length;
    s3->A = (int *)malloc(s3->size * sizeof(int));

    while (i < s1->length && j < s2->length)
    {
        if (s1->A[i] < s2->A[j])
            s3->A[k++] = s1->A[i++];
        else if (s2->A[j] < s1->A[i])
            s3->A[k++] = s2->A[j++];
        else
        {
            s3->A[k++] = s1->A[i++];
            j++;
        }
    }
    while (i < s1->length)
        s3->A[k++] = s1->A[i++];
    while (j < s2->length)
        s3->A[k++] = s2->A[j++];

    s3->length = k;
    return s3;
}

struct Set *Intersection(const struct Set *s1, const struct Set *s2)
{
    int i = 0, j = 0, k = 0;
    struct Set *s3 = (struct Set *)malloc(sizeof(struct Set));
    s3->size = s1->length < s2->length ? s1->length : s2->length;
    s3->A = (int *)malloc(s3->size * sizeof(int));

    while (i < s1->length && j < s2->length)
    {
        if (s1->A[i] < s2->A[j])
            i++;
        else if (s2->A[j] < s1->A[i])
            j++;
        else
        {
            s3->A[k++] = s1->A[i++];
            j++;
        }
    }

    s3->length = k;
    return s3;
}

struct Set *Difference(const struct Set *s1, const struct Set *s2)
{
    int i = 0, j = 0, k = 0;
    struct Set *s3 = (struct Set *)malloc(sizeof(struct Set));
    s3->size = s1->length;
    s3->A = (int *)malloc(s3->size * sizeof(int));

    while (i < s1->length && j < s2->length)
    {
        if (s1->A[i] < s2->A[j])
            s3->A[k++] = s1->A[i++];
        else if (s2->A[j] < s1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    while (i < s1->length)
        s3->A[k++] = s1->A[i++];

    s3->length = k;
    return s3;
}

int main()
{
    int A1[] = {2, 9, 21, 28, 35};
    int A2[] = {2, 3, 9, 18, 28};

    struct Set *s1 = Create(A1, sizeof(A1) / sizeof(A1[0]));
    struct Set *s2 = Create(A2, sizeof(A2) / sizeof(A2[0]));

    Display(s1);
    Display(s2);

    struct Set *s3 = Union(s1, s2);
    printf("Union: ");
    Display(s3);

    struct Set *s4 = Intersection(s1, s2);
    printf("Intersection: ");
    Display(s4);

    struct Set *s5 = Difference(s1, s2);
    printf("Difference: ");
    Display(s5);

    return 0;
}
