#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int pow;
    struct Node *next;
};

struct Node *Create(int A[], int N)
{
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *last = NULL;

    for (int i = 0; i < N; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->coeff = A[i];
        temp->pow = N - i - 1;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            last = head;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
    return head;
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%dx^%d", p->coeff, p->pow);
        if (p->next != NULL)
        {
            printf(" + ");
        }
        p = p->next;
    }
    printf("\n");
}

int Eval(struct Node *p, int x)
{
    int result = 0;
    while (p != NULL)
    {
        result += p->coeff * pow(x, p->pow);
        p = p->next;
    }
    return result;
}

int main()
{
    int A[] = {1, 2, 2, 2};
    int N = sizeof(A) / sizeof(A[0]);

    struct Node *poly = Create(A, N);

    printf("Polynomial: ");
    Display(poly);

    int x = 10;
    int result = Eval(poly, x);
    printf("Polynomial evaluated at x = %d: %d\n", x, result);

    return 0;
}
