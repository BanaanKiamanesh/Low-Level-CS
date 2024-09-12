#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue() { front = rear = nullptr; }

    void EnQueue(int x)
    {
        Node *t = new Node();
        t->data = x;
        t->next = nullptr;

        if (rear == nullptr)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }

    int DeQueue()
    {
        int x = -1;
        if (front == nullptr)
            cout << "Queue is Empty\n";
        else
        {
            Node *t = front;
            x = t->data;
            front = front->next;

            if (front == nullptr)
                rear = nullptr;

            delete t;
        }
        return x;
    }

    void Display() const
    {
        Node *p = front;
        if (p == nullptr)
        {
            cout << "Queue is Empty\n";
            return;
        }
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

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
