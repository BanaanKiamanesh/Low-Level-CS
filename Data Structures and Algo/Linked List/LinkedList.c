#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void Create(int *A, int N)
{
    struct Node *tmp, *last;
    first = (struct Node *)malloc(sizeof(struct Node));

    first->data = A[0];
    first->next = NULL;

    last = first;

    for (int i = 1; i < N; i++)
    {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->data = A[i];
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int CountNodes(struct Node *p)
{
    int cnt = 0;
    while (p != NULL)
    {
        p = p->next;
        cnt++;
    }

    return cnt;
}

int Sum(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }

    return sum;
}

int Maximum(struct Node *p)
{
    int max = p->data;
    p = p->next;

    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;

        p = p->next;
    }

    return max;
}

struct Node *Search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
            return p;

        p = p->next;
    }
    return NULL;
}

void Insert(struct Node *p, int index, int value)
{
    struct Node *tmp;
    int i;

    if (index < 0 || index > CountNodes(p))
        return;

    tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->data = value;
    tmp->next = NULL;

    if (index == 0)
    {
        tmp->next = first;
        first = tmp;
    }
    else
    {
        for (i = 0; i < index - 1 && p != NULL; i++)
            p = p->next;

        if (p != NULL)
        {
            tmp->next = p->next;
            p->next = tmp;
        }
    }
}

void Delete(struct Node *p, int index)
{
    struct Node *tmp;
    int i;

    if (index < 0 || index >= CountNodes(p))
        return;

    if (index == 0)
    {
        tmp = first;
        first = first->next;
        free(tmp);
    }
    else
    {
        for (i = 0; i < index - 1 && p != NULL; i++)
            p = p->next;

        if (p != NULL && p->next != NULL)
        {
            tmp = p->next;
            p->next = tmp->next;
            free(tmp);
        }
    }
}

int IsSorted(struct Node *p)
{
    int prev = INT_MIN;

    while (p != NULL)
    {
        if (p->data < prev)
            return 0;

        prev = p->data;
        p = p->next;
    }

    return 1;
}

void Reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;
    int count = CountNodes(p); // Get the count of nodes
    A = (int *)malloc(sizeof(int) * count);
    if (!A)
        exit(1);

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
    free(A);
}

void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

/********************* Recursive Functions **********************/
void RecursiveDisplay(struct Node *p)
{
    if (p == NULL)
        return;

    printf("%d\n", p->data);
    RecursiveDisplay(p->next);
}

int RecursiveSum(struct Node *p)
{
    if (p == NULL)
        return 0;

    return p->data + RecursiveSum(p->next);
}

int RecursiveCount(struct Node *p)
{
    if (p == NULL)
        return 0;

    return 1 + RecursiveCount(p->next);
}

int RecursiveMaximum(struct Node *p)
{
    if (p == NULL)
        return INT_MIN;

    int max = RecursiveMaximum(p->next);
    return (max > p->data) ? max : p->data;
}

struct Node *RecursiveSearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;

    if (p->data == key)
        return p;

    return RecursiveSearch(p->next, key);
}

void RecursiveReverse(struct Node *q, struct Node *p)
{
    if (p)
    {
        RecursiveReverse(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

int main()
{
    int A[] = {12, 2, 13, 4};
    int B[] = {1, 2, 3, 4, 5};

    int N = sizeof(A) / sizeof(int);
    int M = sizeof(B) / sizeof(int);
    Create(A, N);
    // Create(B, M);

    /*  >>>>>>>>>>> Test Reverse
    Display(first);
    RecursiveReverse(NULL, first);
    printf("\nList after Reverse1:\n");
    Display(first);
    */

    /*  >>>>>>>>>>> Test IsSorted
    Create(A, N);
    printf("\nList A is sorted: %d", IsSorted(first));

    Create(B, M);
    printf("\nList B is sorted: %d", IsSorted(first));
    */

    /*  >>>>>>>>>>> Test Delete
    Delete(first, 0);
    Delete(first, 2);
    Delete(first, 1);

    Display(first);
    */

    /*  >>>>>>>>>>> Test Insert
    Insert(first, 0, 25);
    Insert(first, 2, 30);
    Insert(first, 5, 50);

    Display(first);
    */

    /*  >>>>>>>>>>> Test Display
    // Display(first);
    // printf("\n====================\n");
    // RecursiveDisplay(first);
    */

    /*  >>>>>>>>>>> Test Functionlaities
    printf("\nNumber of All Nodes = %d", CountNodes(first));
    printf("\nNumber of All Nodes(Recursive) = %d", CountNodes(first));
    printf("\nSum of All Elements = %d", Sum(first));
    printf("\nSum of All Elements(Recursive) = %d", RecursiveSum(first));
    printf("\nMax Element = %d", Maximum(first));
    printf("\nMax Element(Recursive) = %d", RecursiveMaximum(first));
    */

    /*  >>>>>>>>>>> Test Search

    // Search for a Key
    struct Node *tmp = Search(first, 25);
    if (tmp)
        printf("\nKey found with the value = %d", tmp->data);
    else
        printf("\nKey not found!");

    // Search for a Key (Recursive)
    struct Node *tmp2 = RecursiveSearch(first, 13);
    if (tmp2)
        printf("\nKey found with the value = %d", tmp2->data);
    else
        printf("\nKey not found!");
    */

    return 0;
}
