#include <stdio.h>
#include <stdlib.h>

// Diagonal Matrix
struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i == j)
        m->A[i - 1] = x;
}

int Get(struct Matrix m, int i, int j)
{
    if (i == j)
        return m.A[i - 1];
    else
        return 0;
}

void Display(struct Matrix m)
{
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i == j)
                printf("%d ", m.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void Create(struct Matrix *m, int arr[], int size)
{
    m->n = size;
    m->A = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        m->A[i] = arr[i];
}

int main()
{
    struct Matrix m;

    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    Create(&m, arr, size);

    printf("Matrix:\n");
    Display(m);

    printf("\nElement at (2,2): %d \n", Get(m, 2, 2));

    return 0;
}
