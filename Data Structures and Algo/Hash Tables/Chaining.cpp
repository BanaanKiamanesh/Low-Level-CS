#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *CreateNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

int HashFunction(int key) { return key % 10; }

void Insert(Node *HashTable[], int key)
{
    int index = HashFunction(key);
    Node *newNode = CreateNode(key);

    if (HashTable[index] == nullptr)
        HashTable[index] = newNode;
    else
    {
        Node *temp = HashTable[index];
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteNode(Node *HashTable[], int key)
{
    int index = HashFunction(key);
    Node *temp = HashTable[index];
    Node *prev = nullptr;

    while (temp != nullptr && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Key " << key << " not found in hash table" << endl;
        return;
    }

    if (prev == nullptr)
        HashTable[index] = temp->next;
    else
        prev->next = temp->next;

    delete temp;
}

Node *search(Node *HashTable[], int key)
{
    int index = HashFunction(key);
    Node *temp = HashTable[index];

    while (temp != nullptr)
    {
        if (temp->data == key)
            return temp;
        temp = temp->next;
    }

    return nullptr;
}

void DisplayHashTable(Node *HashTable[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Hash index " << i << ": ";
        Node *temp = HashTable[i];
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

int main()
{
    Node *HashTable[10] = {nullptr};

    Insert(HashTable, 10);
    Insert(HashTable, 20);
    Insert(HashTable, 15);
    Insert(HashTable, 35);
    Insert(HashTable, 50);

    cout << "Initial Hash Table:" << endl;
    DisplayHashTable(HashTable);

    deleteNode(HashTable, 35);
    cout << "Hash Table after deleting 35:" << endl;
    DisplayHashTable(HashTable);

    Node *result = search(HashTable, 15);
    if (result != nullptr)
        cout << "15 found in the hash table" << endl;
    else
        cout << "15 not found in the hash table" << endl;

    return 0;
}
