#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void Create(struct Queue *q)
{
    q->front = q->rear = NULL;
}

void EnQueue(struct Queue *q, int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (q->rear == NULL)
        q->front = q->rear = t;
    else
    {
        q->rear->next = t;
        q->rear = t;
    }
}

int DeQueue(struct Queue *q)
{
    int x = -1;
    if (q->front == NULL)
        printf("Queue is Empty\n");
    else
    {
        struct Node *t = q->front;
        x = t->data;
        q->front = q->front->next;
        if (q->front == NULL)
            q->rear = NULL;

        free(t);
    }
    return x;
}

void Display(struct Queue q)
{
    struct Node *p = q.front;
    if (p == NULL)
    {
        printf("Queue is Empty\n");
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
    struct Queue q;
    Create(&q);

    EnQueue(&q, 10);
    EnQueue(&q, 20);
    EnQueue(&q, 30);

    printf("Queue elements: ");
    Display(q);

    printf("Dequeued element: %d\n", DeQueue(&q));
    printf("Queue elements after dequeue: ");
    Display(q);

    return 0;
}
