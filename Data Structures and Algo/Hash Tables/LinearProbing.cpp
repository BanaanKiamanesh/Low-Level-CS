#include <iostream>
using namespace std;

#define SIZE 10

int HashFunction(int key) { return key % SIZE; }

void Insert(int hashTable[], int key)
{
    int index = HashFunction(key);

    while (hashTable[index] != -1)
        index = (index + 1) % SIZE;

    hashTable[index] = key;
}

int Search(int HashTable[], int key)
{
    int index = HashFunction(key);

    while (HashTable[index] != -1)
    {
        if (HashTable[index] == key)
            return index;
        index = (index + 1) % SIZE;
    }

    return -1;
}

void DeleteKey(int HashTable[], int key)
{
    int index = Search(HashTable, key);

    if (index != -1)
        HashTable[index] = -1;
    else
        cout << "Key " << key << " not found" << endl;
}

void DisplayHashTable(int hashTable[])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            cout << "Hash index " << i << ": NULL" << endl;
        else
            cout << "Hash index " << i << ": " << hashTable[i] << endl;
    }
}

int main()
{
    int HashTable[SIZE];
    for (int i = 0; i < SIZE; i++)
        HashTable[i] = -1;

    Insert(HashTable, 10);
    Insert(HashTable, 20);
    Insert(HashTable, 15);
    Insert(HashTable, 35);
    Insert(HashTable, 50);

    cout << "Initial Hash Table:" << endl;
    DisplayHashTable(HashTable);

    int searchResult = Search(HashTable, 15);
    if (searchResult != -1)
        cout << "15 found at index " << searchResult << endl;
    else
        cout << "15 not found in the hash table" << endl;

    DeleteKey(HashTable, 35);
    cout << "Hash Table after deleting 35:" << endl;
    DisplayHashTable(HashTable);

    return 0;
}
