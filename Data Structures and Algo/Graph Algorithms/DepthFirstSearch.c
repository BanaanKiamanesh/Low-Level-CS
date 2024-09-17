#include <stdio.h>

#define SIZE 100

struct Stack
{
    int items[SIZE];
    int top;
};

void initStack(struct Stack *s) { s->top = -1; }
int isEmpty(struct Stack *s) { return s->top == -1; }
int isFull(struct Stack *s) { return s->top == SIZE - 1; }

void push(struct Stack *s, int value)
{
    if (isFull(s))
        printf("Stack is full!\n");
    else
        s->items[++(s->top)] = value;
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    else
        return s->items[(s->top)--];
}

void DFS(int graph[SIZE][SIZE], int startVertex, int numVertices)
{
    int visited[SIZE] = {0};
    struct Stack s;
    initStack(&s);

    push(&s, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(&s))
    {
        int currentVertex = pop(&s);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++)
            if (graph[currentVertex][i] == 1 && !visited[i])
            {
                push(&s, i);
                visited[i] = 1;
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

    printf("DFS starting from vertex 0:\n");
    DFS(graph, 0, numVertices);

    return 0;
}
