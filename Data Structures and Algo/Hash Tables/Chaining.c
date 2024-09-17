#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *CreateNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int HashFunction(int key) { return key % 10; }

void Insert(struct Node *HashTable[], int key)
{
    int index = HashFunction(key);
    struct Node *newNode = CreateNode(key);

    if (HashTable[index] == NULL)
        HashTable[index] = newNode;
    else
    {
        struct Node *temp = HashTable[index];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void DeleteNode(struct Node *hashTable[], int key)
{
    int index = HashFunction(key);
    struct Node *temp = hashTable[index];
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Key %d not found in hash table\n", key);
        return;
    }

    if (prev == NULL)
        hashTable[index] = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

struct Node *Search(struct Node *hashTable[], int key)
{
    int index = HashFunction(key);
    struct Node *temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->data == key)
            return temp;
        temp = temp->next;
    }

    return NULL;
}

void DisplayHashTable(struct Node *hashTable[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("Hash index %d: ", i);
        struct Node *temp = hashTable[i];
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    struct Node *HashTable[10] = {NULL};

    Insert(HashTable, 10);
    Insert(HashTable, 20);
    Insert(HashTable, 15);
    Insert(HashTable, 35);
    Insert(HashTable, 50);

    printf("Initial Hash Table:\n");
    DisplayHashTable(HashTable);

    DeleteNode(HashTable, 35);
    printf("Hash Table after deleting 35:\n");
    DisplayHashTable(HashTable);

    struct Node *result = Search(HashTable, 15);
    if (result != NULL)
        printf("15 found in the hash table\n");
    else
        printf("15 not found in the hash table\n");

    return 0;
}
