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

void Create(struct Queue *q) { q->front = q->rear = NULL; }

void EnQueue(struct Queue *q, int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    t->data = x;
    if (q->front == NULL)
    {
        q->front = q->rear = t;
        t->next = q->front;
    }
    else
    {
        t->next = q->front;
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
        if (q->front == q->rear)
        {
            free(t);
            q->front = q->rear = NULL;
        }
        else
        {
            q->front = q->front->next;
            q->rear->next = q->front;
            free(t);
        }
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
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != q.front);
    printf("\n");
}

int main()
{
    struct Queue q;
    Create(&q);

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
