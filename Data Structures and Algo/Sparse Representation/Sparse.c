#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void Create(struct Sparse *s, int m, int n, int values[], int rows[], int cols[], int num)
{
    int i;
    s->m = m;
    s->n = n;
    s->num = num;
    printf("\n%d\n", num);

    s->ele = (struct Element *)malloc(num * sizeof(struct Element));

    for (i = 0; i < num; i++)
    {
        s->ele[i].i = rows[i];
        s->ele[i].j = cols[i];
        s->ele[i].x = values[i];
        printf("Element %d: (%d, %d) = %d\n", i, rows[i], cols[i], values[i]); // Debug print
    }
}

void Display(struct Sparse s)
{
    int i, j, k = 0;
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (k < s.num && i == s.ele[k].i && j == s.ele[k].j)
                printf("%d ", s.ele[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

struct Sparse *Add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;
    int i = 0, j = 0, k = 0;

    if (s1->n != s2->n || s1->m != s2->m)
        return NULL;

    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->ele = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));

    while (i < s1->num && j < s2->num)
    {
        if (s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if (s1->ele[i].i > s2->ele[j].i)
            sum->ele[k++] = s2->ele[j++];
        else
        {
            if (s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++] = s1->ele[i++];
            else if (s1->ele[i].j > s2->ele[j].j)
                sum->ele[k++] = s2->ele[j++];
            else
            {
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }
    while (i < s1->num)
        sum->ele[k++] = s1->ele[i++];
    while (j < s2->num)
        sum->ele[k++] = s2->ele[j++];

    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
}

int main()
{
    struct Sparse s1, s2, *s3;

    int values1[] = {5, 8, 10};
    int rows1[] = {0, 1, 2};
    int cols1[] = {0, 1, 2};
    int num1 = sizeof(values1) / sizeof(values1[0]);

    int values2[] = {4, 7, 9};
    int rows2[] = {0, 1, 2};
    int cols2[] = {1, 2, 0};
    int num2 = sizeof(values2) / sizeof(values2[0]);

    Create(&s1, 3, 3, values1, rows1, cols1, num1);
    Create(&s2, 3, 3, values2, rows2, cols2, num2);

    s3 = Add(&s1, &s2);

    if (s3 == NULL)
    {
        printf("Matrices cannot be added\n");
        return -1;
    }

    printf("First Matrix\n");
    Display(s1);

    printf("Second Matrix\n");
    Display(s2);

    printf("Sum Matrix\n");
    Display(*s3);

    return 0;
}
