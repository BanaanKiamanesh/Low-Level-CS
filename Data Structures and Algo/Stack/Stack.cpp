#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    int size;
    int top;
    T *S;

public:
    Stack(int Size)
    {
        size = Size;
        top = -1;
        S = new T[size];
    }

    void Display()
    {
        for (int i = top; i >= 0; i--)
            cout << S[i] << " ";
        cout << endl;
    }

    void Push(T x)
    {
        if (top == size - 1)
            cout << "Stack overflow\n";
        else
            S[++top] = x;
    }

    T Pop()
    {
        T x = -1;
        if (top == -1)
            cout << "Stack Underflow\n";
        else
            x = S[top--];
        return x;
    }

    T Peek(int index)
    {
        T x = -1;
        if (top - index + 1 < 0)
            cout << "Invalid Index\n";
        else
            x = S[top - index + 1];
        return x;
    }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == size - 1; }
    T StackTop() { return (!isEmpty()) ? S[top] : -1; }
};

int main()
{
    // Integer stack test
    Stack<int> intStack(4);

    cout << "Integer Stack:\n";
    cout << "Is Empty: " << intStack.isEmpty() << endl;
    cout << "Is Full: " << intStack.isFull() << endl;

    intStack.Push(10);
    intStack.Push(20);
    intStack.Push(30);
    intStack.Push(40);

    cout << "Is Empty: " << intStack.isEmpty() << endl;
    cout << "Is Full: " << intStack.isFull() << endl;

    cout << "Stack Top: " << intStack.StackTop() << endl;
    cout << "Element at index 2: " << intStack.Peek(2) << endl;

    intStack.Display();

    // Character stack test
    Stack<char> charStack(4);

    cout << "\nCharacter Stack:\n";
    cout << "Is Empty: " << charStack.isEmpty() << endl;
    cout << "Is Full: " << charStack.isFull() << endl;

    charStack.Push('A');
    charStack.Push('B');
    charStack.Push('C');
    charStack.Push('D');

    cout << "Is Empty: " << charStack.isEmpty() << endl;
    cout << "Is Full: " << charStack.isFull() << endl;

    cout << "Stack Top: " << charStack.StackTop() << endl;
    cout << "Element at index 2: " << charStack.Peek(2) << endl;

    charStack.Display();

    return 0;
}
