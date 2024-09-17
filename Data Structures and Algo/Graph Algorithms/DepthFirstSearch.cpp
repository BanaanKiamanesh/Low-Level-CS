#include <iostream>
using namespace std;

#define SIZE 100

class Stack
{
private:
    int items[SIZE];
    int top;

public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == SIZE - 1; }

    void push(int value)
    {
        if (isFull())
            cout << "Stack is full!" << endl;
        else
            items[++top] = value;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        else
            return items[top--];
    }
};

void DFS(int graph[][SIZE], int startVertex, int numVertices)
{
    bool visited[SIZE] = {0};
    Stack s;

    s.push(startVertex);
    visited[startVertex] = true;

    while (!s.isEmpty())
    {
        int currentVertex = s.pop();
        cout << currentVertex << " ";

        for (int i = 0; i < numVertices; i++)
            if (graph[currentVertex][i] == 1 && !visited[i])
            {
                s.push(i);
                visited[i] = true;
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

    cout << "DFS starting from vertex 0:" << endl;
    DFS(graph, 0, numVertices);

    return 0;
}
