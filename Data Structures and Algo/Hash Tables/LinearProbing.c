#include <stdio.h>

#define SIZE 10

int HashFunction(int key) { return key % SIZE; }

void Insert(int HashTable[], int key)
{
    int index = HashFunction(key);

    while (HashTable[index] != -1)
        index = (index + 1) % SIZE;

    HashTable[index] = key;
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
        printf("Key %d not found\n", key);
}

void DisplayHashTable(int HashTable[])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (HashTable[i] == -1)
            printf("Hash index %d: NULL\n", i);
        else
            printf("Hash index %d: %d\n", i, HashTable[i]);
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

    printf("Initial Hash Table:\n");
    DisplayHashTable(HashTable);

    int searchResult = Search(HashTable, 15);
    if (searchResult != -1)
        printf("15 found at index %d\n", searchResult);
    else
        printf("15 not found in the hash table\n");

    DeleteKey(HashTable, 35);
    printf("Hash Table after deleting 35:\n");
    DisplayHashTable(HashTable);

    return 0;
}
