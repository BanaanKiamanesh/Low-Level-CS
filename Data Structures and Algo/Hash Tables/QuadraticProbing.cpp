#include <iostream>
using namespace std;

#define SIZE 10

int HashFunction(int key) { return key % SIZE; }

void Insert(int HashTable[], int key)
{
    int index = HashFunction(key);
    int i = 1;

    while (HashTable[index] != -1)
    {
        index = (index + i * i) % SIZE;
        i++;
    }

    HashTable[index] = key;
}

int Search(int HashTable[], int key)
{
    int index = HashFunction(key);
    int i = 1;

    while (HashTable[index] != -1)
    {
        if (HashTable[index] == key)
            return index;
        index = (index + i * i) % SIZE;
        i++;
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
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    Insert(hashTable, 10);
    Insert(hashTable, 20);
    Insert(hashTable, 15);
    Insert(hashTable, 35);
    Insert(hashTable, 50);

    cout << "Initial Hash Table:" << endl;
    DisplayHashTable(hashTable);

    int searchResult = Search(hashTable, 15);
    if (searchResult != -1)
        cout << "15 found at index " << searchResult << endl;
    else
        cout << "15 not found in the hash table" << endl;

    DeleteKey(hashTable, 35);
    cout << "Hash Table after deleting 35:" << endl;
    DisplayHashTable(hashTable);

    return 0;
}
