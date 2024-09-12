#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void EnQueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
        printf("Queue is Full\n");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int DeQueue(struct Queue *q)
{
    int x = -1;
    if (q->front == -1 || q->front > q->rear)
        printf("Queue is Empty\n");
    else
    {
        x = q->Q[q->front++];
        if (q->front > q->rear)
            q->front = q->rear = -1; // Reset the queue if it becomes empty
    }
    return x;
}

void Display(struct Queue q)
{
    int i;
    if (q.front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    for (i = q.front; i <= q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}

int main()
{
    struct Queue q;
    Create(&q, 5);

    EnQueue(&q, 10);
    EnQueue(&q, 20);
    EnQueue(&q, 30);

    Display(q);

    printf("Dequeued element: %d\n", DeQueue(&q));
    Display(q);

    return 0;
}
