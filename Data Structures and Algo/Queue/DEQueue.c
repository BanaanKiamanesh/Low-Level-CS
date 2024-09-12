#include <stdio.h>
#include <stdlib.h>

struct Deque
{
    int size;
    int front;
    int rear;
    int *array;
};

void Create(struct Deque *d, int size)
{
    d->size = size;
    d->front = -1;
    d->rear = 0;
    d->array = (int *)malloc(d->size * sizeof(int));
}

void InsertFront(struct Deque *d, int x)
{
    if ((d->front == 0 && d->rear == d->size - 1) || (d->front == d->rear + 1))
        printf("Deque is Full\n");
    else
    {
        if (d->front == -1)
            d->front = d->rear = 0;
        else if (d->front == 0)
            d->front = d->size - 1;
        else
            d->front--;
        d->array[d->front] = x;
    }
}

void InsertRear(struct Deque *d, int x)
{
    if ((d->front == 0 && d->rear == d->size - 1) || (d->front == d->rear + 1))
        printf("Deque is Full\n");
    else
    {
        if (d->front == -1)
            d->front = d->rear = 0;
        else if (d->rear == d->size - 1)
            d->rear = 0;
        else
            d->rear++;
        d->array[d->rear] = x;
    }
}

int DeleteFront(struct Deque *d)
{
    int x = -1;
    if (d->front == -1)
        printf("Deque is Empty\n");
    else
    {
        x = d->array[d->front];
        if (d->front == d->rear)
            d->front = d->rear = -1;
        else if (d->front == d->size - 1)
            d->front = 0;
        else
            d->front++;
    }
    return x;
}

int DeleteRear(struct Deque *d)
{
    int x = -1;
    if (d->front == -1)
        printf("Deque is Empty\n");
    else
    {
        x = d->array[d->rear];
        if (d->front == d->rear)
            d->front = d->rear = -1;
        else if (d->rear == 0)
            d->rear = d->size - 1;
        else
            d->rear--;
    }
    return x;
}

void Display(struct Deque d)
{
    if (d.front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }
    int i = d.front;
    while (1)
    {
        printf("%d ", d.array[i]);
        if (i == d.rear)
            break;
        i = (i + 1) % d.size;
    }
    printf("\n");
}

int main()
{
    struct Deque d;
    Create(&d, 5);

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

    free(d.array); // Free the allocated memory for the deque

    return 0;
}
