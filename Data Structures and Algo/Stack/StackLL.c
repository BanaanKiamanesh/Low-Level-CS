#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Create() { return NULL; }

void Push(struct Node **top, int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Stack is full\n");
    else
    {
        t->data = x;
        t->next = *top;
        *top = t;
    }
}

int Pop(struct Node **top)
{
    struct Node *t;
    int x = -1;
    if (*top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = *top;
        *top = (*top)->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display(struct Node *top)
{
    struct Node *p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct Node *top = Create();

    Push(&top, 10);
    Push(&top, 20);
    Push(&top, 30);

    Display(top);

    printf("%d popped from the stack\n", Pop(&top));
    Display(top);

    return 0;
}
