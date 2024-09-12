#include <iostream>
using namespace std;

class Deque
{
private:
    int size;
    int front;
    int rear;
    int *array;

public:
    Deque(int size)
    {
        this->size = size;
        front = -1;
        rear = 0;
        array = new int[this->size];
    }

    void InsertFront(int x)
    {
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
            cout << "Deque is Full\n";
        else
        {
            if (front == -1)
                front = rear = 0;
            else if (front == 0)
                front = size - 1;
            else
                front--;

            array[front] = x;
        }
    }

    void InsertRear(int x)
    {
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
            cout << "Deque is Full\n";
        else
        {
            if (front == -1)
                front = rear = 0;
            else if (rear == size - 1)
                rear = 0;
            else
                rear++;

            array[rear] = x;
        }
    }

    int DeleteFront()
    {
        if (front == -1)
        {
            cout << "Deque is Empty\n";
            return -1;
        }
        int x = array[front];
        if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;
        else
            front++;

        return x;
    }

    int DeleteRear()
    {
        if (front == -1)
        {
            cout << "Deque is Empty\n";
            return -1;
        }
        int x = array[rear];
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = size - 1;
        else
            rear--;

        return x;
    }

    void Display()
    {
        if (front == -1)
        {
            cout << "Deque is Empty\n";
            return;
        }
        int i = front;
        while (true)
        {
            cout << array[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    Deque d(5);

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
