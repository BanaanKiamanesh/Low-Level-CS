#include <stdio.h>

#define SIZE 10

int HashFunction1(int key) { return key % SIZE; }
int HashFunction2(int key) { return 7 - (key % 7); }

void Insert(int hashTable[], int key)
{
    int index = HashFunction1(key);
    int i = 0;

    while (hashTable[(index + i * HashFunction2(key)) % SIZE] != -1)
        i++;
    hashTable[(index + i * HashFunction2(key)) % SIZE] = key;
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
        printf("Key %d not found\n", key);
}

void DisplayHashTable(int hashTable[])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("Hash index %d: NULL\n", i);
        else
            printf("Hash index %d: %d\n", i, hashTable[i]);
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
