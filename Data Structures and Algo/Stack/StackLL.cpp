#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
};

template <typename T>
class Stack
{
private:
    Node<T> *top;

public:
    Stack() { top = nullptr; }

    void Push(T x)
    {
        Node<T> *t = new Node<T>;
        if (t == nullptr)
            cout << "Stack overflow\n";
        else
        {
            t->data = x;
            t->next = top;
            top = t;
        }
    }

    T Pop()
    {
        T x = -1;
        if (top == nullptr)
            cout << "Stack underflow\n";
        else
        {
            Node<T> *t = top;
            x = top->data;
            top = top->next;
            delete t;
        }
        return x;
    }

    T Peek(int index)
    {
        Node<T> *p = top;
        for (int i = 0; p != nullptr && i < index - 1; i++)
            p = p->next;
        if (p != nullptr)
            return p->data;
        else
            return -1;
    }

    void Display()
    {
        Node<T> *p = top;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    bool isEmpty() { return top == nullptr; }
    T StackTop() { return (top != nullptr) ? top->data : -1; }
};

int main()
{
    // Integer stack test
    Stack<int> intStack;
    intStack.Push(10);
    intStack.Push(20);
    intStack.Push(30);
    intStack.Push(40);

    cout << "Integer Stack: ";
    intStack.Display();

    cout << "Popped: " << intStack.Pop() << endl;
    intStack.Display();

    // Character stack test
    Stack<char> charStack;
    charStack.Push('A');
    charStack.Push('B');
    charStack.Push('C');
    charStack.Push('D');

    cout << "\nCharacter Stack: ";
    charStack.Display();

    cout << "Popped: " << charStack.Pop() << endl;
    charStack.Display();

    return 0;
}
