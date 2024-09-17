#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct Queue
{
    int items[SIZE];
    int front;
    int rear;
};

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue *q)
{
    return q->front == -1;
}

void enqueue(struct Queue *q, int value)
{
    if (q->rear == SIZE - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
        return -1;
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    return item;
}

void BFS(int graph[][SIZE], int startVertex, int numVertices)
{
    int visited[SIZE] = {0};
    struct Queue *q = createQueue();

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q))
    {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++)
        {
            if (graph[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
}

int main()
{
    int numVertices = 6;
    int graph[SIZE][SIZE] = {{0, 1, 1, 0, 0, 0},
                             {1, 0, 1, 1, 1, 0},
                             {1, 1, 0, 0, 1, 0},
                             {0, 1, 0, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1},
                             {0, 0, 0, 1, 1, 0}};

    printf("BFS starting from vertex 0:\n");
    BFS(graph, 0, numVertices);

    return 0;
}
