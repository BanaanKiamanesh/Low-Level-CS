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
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void EnQueue(struct Queue *q, int x)
{
    int next = (q->rear + 1) % q->size;
    if (next == q->front)
        printf("Queue is Full\n");
    else
    {
        q->Q[q->rear] = x;
        q->rear = next;
    }
}

int DeQueue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        x = q->Q[q->front];
        q->front = (q->front + 1) % q->size;
    }
    return x;
}

void Display(struct Queue q)
{
    int i = q.front;
    if (i == q.rear)
    {
        printf("Queue is Empty\n");
        return;
    }
    while (i != q.rear)
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    Create(&q, 5);

    EnQueue(&q, 10);
    EnQueue(&q, 20);
    EnQueue(&q, 30);
    EnQueue(&q, 40);

    printf("Queue elements: ");
    Display(q);

    printf("Dequeued element: %d\n", DeQueue(&q));
    printf("Queue elements after dequeue: ");
    Display(q);

    EnQueue(&q, 50);
    EnQueue(&q, 60);

    printf("Queue elements after adding more elements: ");
    Display(q);

    return 0;
}
