#include <iostream>
using namespace std;

#define SIZE 100

class Queue
{
private:
    int items[SIZE];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty() { return front == -1; }
    bool isFull() { return rear == SIZE - 1; }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }
        if (isEmpty())
            front = 0;
        rear++;
        items[rear] = value;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int value = items[front];
        front++;
        if (front > rear)
            front = rear = -1;

        return value;
    }
};

void BFS(int graph[][SIZE], int startVertex, int numVertices)
{
    bool visited[SIZE] = {0};
    Queue q;

    visited[startVertex] = true;
    q.enqueue(startVertex);

    while (!q.isEmpty())
    {
        int currentVertex = q.dequeue();
        cout << currentVertex << " ";

        for (int i = 0; i < numVertices; i++)
            if (graph[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.enqueue(i);
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

    cout << "BFS starting from vertex 0:" << endl;
    BFS(graph, 0, numVertices);

    return 0;
}
