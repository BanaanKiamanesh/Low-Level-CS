#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Deque
{
private:
    Node *front;
    Node *rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    void InsertFront(int x)
    {
        Node *t = new Node(x);
        if (!t)
        {
            cout << "Memory allocation failed\n";
            return;
        }

        if (front == nullptr)
        {
            front = rear = t;
        }
        else
        {
            t->next = front;
            front->prev = t;
            front = t;
        }
    }

    void InsertRear(int x)
    {
        Node *t = new Node(x);
        if (!t)
        {
            cout << "Memory allocation failed\n";
            return;
        }

        if (rear == nullptr)
            front = rear = t;
        else
        {
            rear->next = t;
            t->prev = rear;
            rear = t;
        }
    }

    int DeleteFront()
    {
        if (front == nullptr)
        {
            cout << "Deque is Empty\n";
            return -1;
        }

        Node *t = front;
        int x = t->data;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        else
            front->prev = nullptr;

        delete t;
        return x;
    }

    int DeleteRear()
    {
        if (rear == nullptr)
        {
            cout << "Deque is Empty\n";
            return -1;
        }

        Node *t = rear;
        int x = t->data;
        rear = rear->prev;
        if (rear == nullptr)
            front = nullptr;
        else
            rear->next = nullptr;

        delete t;
        return x;
    }

    void Display()
    {
        if (front == nullptr)
        {
            cout << "Deque is Empty\n";
            return;
        }

        Node *p = front;
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
    Deque d;

    d.InsertRear(10);
    d.InsertRear(20);
    d.InsertFront(30);
    d.InsertFront(40);

    cout << "Deque elements: ";
    d.Display();

    cout << "Deleted from front: " << d.DeleteFront() << endl;
    cout << "Deque elements after deleting from front: ";
    d.Display();

    cout << "Deleted from rear: " << d.DeleteRear() << endl;
    cout << "Deque elements after deleting from rear: ";
    d.Display();

    d.InsertRear(50);
    d.InsertFront(60);

    cout << "Deque elements after adding more elements: ";
    d.Display();

    return 0;
}
