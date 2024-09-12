#include <iostream>
using namespace std;

class Node
{
public:
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
        if (t == nullptr)
        {
            cout << "Memory allocation failed" << endl;
            return;
        }
        t->data = x;
        if (front == nullptr)
        {
            front = rear = t;
            t->next = front; // Circular link
        }
        else
        {
            t->next = front;
            rear->next = t;
            rear = t;
        }
    }

    int DeQueue()
    {
        int x = -1;
        if (front == nullptr)
            cout << "Queue is Empty" << endl;
        else
        {
            Node *t = front;
            x = t->data;
            if (front == rear)
            {
                delete t;
                front = rear = nullptr;
            }
            else
            {
                front = front->next;
                rear->next = front;
                delete t;
            }
        }
        return x;
    }

    void Display()
    {
        if (front == nullptr)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        Node *p = front;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != front);
        cout << endl;
    }
};

int main()
{
    Queue q;

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
