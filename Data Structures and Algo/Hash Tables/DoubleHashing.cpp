#include <iostream>
using namespace std;

#define SIZE 10

int HashFunction1(int key) { return key % SIZE; }
int HashFunction2(int key) { return 7 - (key % 7); }

void Insert(int HashTable[], int key)
{
    int index = HashFunction1(key);
    int i = 0;

    while (HashTable[(index + i * HashFunction2(key)) % SIZE] != -1) i++;
    HashTable[(index + i * HashFunction2(key)) % SIZE] = key;
}

int Search(int hashTable[], int key)
{
    int index = HashFunction1(key);
    int i = 0;

    while (hashTable[(index + i * HashFunction2(key)) % SIZE] != -1)
    {
        if (hashTable[(index + i * HashFunction2(key)) % SIZE] == key)
            return (index + i * HashFunction2(key)) % SIZE;
        i++;
    }

    return -1;
}

void DeleteKey(int hashTable[], int key)
{
    int index = Search(hashTable, key);

    if (index != -1)
        hashTable[index] = -1;
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
