#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Deque
{
    struct Node *front;
    struct Node *rear;
};

void Create(struct Deque *d) { d->front = d->rear = NULL; }

void InsertFront(struct Deque *d, int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    t->data = x;
    t->next = d->front;
    t->prev = NULL;
    if (d->front == NULL)
        d->front = d->rear = t;
    else
        d->front->prev = t;
    d->front = t;
}

void InsertRear(struct Deque *d, int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    t->data = x;
    t->next = NULL;
    if (d->rear == NULL)
    {
        d->front = d->rear = t;
        t->prev = NULL;
    }
    else
    {
        d->rear->next = t;
        t->prev = d->rear;
        d->rear = t;
    }
}

int DeleteFront(struct Deque *d)
{
    int x = -1;
    if (d->front == NULL)
        printf("Deque is Empty\n");
    else
    {
        struct Node *t = d->front;
        x = t->data;
        d->front = d->front->next;
        if (d->front == NULL)
            d->rear = NULL;
        else
            d->front->prev = NULL;
        
        free(t);
    }
    return x;
}

int DeleteRear(struct Deque *d)
{
    int x = -1;
    if (d->rear == NULL)
        printf("Deque is Empty\n");
    else
    {
        struct Node *t = d->rear;
        x = t->data;
        d->rear = d->rear->prev;
        if (d->rear == NULL)
            d->front = NULL;
        else
            d->rear->next = NULL;

        free(t);
    }
    return x;
}

void Display(struct Deque d)
{
    struct Node *p = d.front;
    if (p == NULL)
    {
        printf("Deque is Empty\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct Deque d;
    Create(&d);

    InsertRear(&d, 10);
    InsertRear(&d, 20);
    InsertFront(&d, 30);
    InsertFront(&d, 40);

    printf("Deque elements: ");
    Display(d);

    printf("Deleted from front: %d\n", DeleteFront(&d));
    printf("Deque elements after deleting from front: ");
    Display(d);

    printf("Deleted from rear: %d\n", DeleteRear(&d));
    printf("Deque elements after deleting from rear: ");
    Display(d);

    InsertRear(&d, 50);
    InsertFront(&d, 60);

    printf("Deque elements after adding more elements: ");
    Display(d);

    return 0;
}
