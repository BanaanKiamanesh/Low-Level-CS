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
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new int[size];
    }

    void EnQueue(int x)
    {
        if (rear == size - 1)
            cout << "Queue is Full\n";
        else
        {
            if (front == -1)
                front = 0;
            rear++;
            Q[rear] = x;
        }
    }

    int DeQueue()
    {
        int x = -1;
        if (front == -1 || front > rear)
            cout << "Queue is Empty\n";
        else
        {
            x = Q[front];
            front++;
            if (front > rear)
                front = rear = -1;
        }
        return x;
    }

    void Display() const
    {
        if (front == -1)
        {
            cout << "Queue is Empty\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << Q[i] << " ";
        cout << endl;
    }
};

int main()
{
    Queue q(5);

    q.EnQueue(10);
    q.EnQueue(20);
    q.EnQueue(30);

    cout << "Queue elements: ";
    q.Display();

    cout << "Dequeued element: " << q.DeQueue() << endl;

    cout << "Queue elements after dequeue: ";
    q.Display();

    return 0;
}
