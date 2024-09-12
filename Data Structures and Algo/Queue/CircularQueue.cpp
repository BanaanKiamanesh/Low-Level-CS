#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue(int s)
    {
        size = s;
        front = rear = 0;
        Q = new int[size];
    }

    void EnQueue(int x)
    {
        int next = (rear + 1) % size;
        if (next == front)
            cout << "Queue is Full\n";
        else
        {
            Q[rear] = x;
            rear = next;
        }
    }

    int DeQueue()
    {
        int x = -1;
        if (isEmpty())
            cout << "Queue is Empty\n";
        else
        {
            x = Q[front];
            front = (front + 1) % size;
        }
        return x;
    }

    void Display()
    {
        int i = front;
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        while (i != rear)
        {
            cout << Q[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }

    bool isFull() { return (rear + 1) % size == front; }
    bool isEmpty() { return front == rear; }
};

int main()
{
    Queue q(5);

    q.EnQueue(10);
    q.EnQueue(20);
    q.EnQueue(30);
    q.EnQueue(40);

    cout << "Queue elements: ";
    q.Display();

    cout << "Dequeued element: " << q.DeQueue() << endl;
    cout << "Queue elements after dequeue: ";
    q.Display();

    q.EnQueue(50);
    q.EnQueue(60);

    cout << "Queue elements after adding more elements: ";
    q.Display();

    return 0;
}
