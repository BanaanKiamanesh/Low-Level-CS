#include <stdio.h>
#include <stdlib.h>

/////////////////////////////// Tree Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *CreateTreeNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/////////////////////////////// Queue
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void CreateQueue(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (struct Node **)malloc(size * sizeof(struct Node *));
}

int IsQueueEmpty(struct Queue *q) { return q->front == q->rear; }

int IsQueueFull(struct Queue *q) { return q->rear == q->size - 1; }

void EnQueue(struct Queue *q, struct Node *treeNode)
{
    if (IsQueueFull(q))
        printf("Queue is Full\n");
    else
        q->Q[++q->rear] = treeNode;
}

struct Node *DeQueue(struct Queue *q)
{
    if (IsQueueEmpty(q))
        return NULL;
    else
    {
        q->front++;
        return q->Q[q->front];
    }
}

/////////////////////////////// Insert into BST
struct Node *Insert(struct Node *root, int key)
{
    struct Node *newNode = CreateTreeNode(key);

    if (root == NULL)
        return newNode;

    struct Node *current = root;
    struct Node *parent = NULL;

    while (current != NULL)
    {
        parent = current;
        if (key < current->data)
            current = current->left;
        else if (key > current->data)
            current = current->right;
        else
            return root; // No duplicates in BST
    }

    if (key < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

/////////////////////////////// Search (Iterative)
struct Node *SearchIterative(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

/////////////////////////////// Search (Recursive)
struct Node *SearchRecursive(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return SearchRecursive(root->left, key);
    else
        return SearchRecursive(root->right, key);
}

/////////////////////////////// Traversals
void InOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        InOrderTraversal(root->left);
        printf("%d ", root->data);
        InOrderTraversal(root->right);
    }
}

void PreOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void LevelOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    struct Queue q;
    CreateQueue(&q, 100);

    EnQueue(&q, root);

    while (!IsQueueEmpty(&q))
    {
        struct Node *current = DeQueue(&q);
        printf("%d ", current->data);

        if (current->left != NULL)
            EnQueue(&q, current->left);

        if (current->right != NULL)
            EnQueue(&q, current->right);
    }

    free(q.Q);
}

struct Node *FindMin(struct Node *root)
{
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

struct Node *Delete(struct Node *root, int key)
{
    if (root == NULL)
        return root;

    // Search for the node to be deleted
    if (key < root->data)
        root->left = Delete(root->left, key);
    else if (key > root->data)
        root->right = Delete(root->right, key);
    else
    {
        // Case 1: Node with no child (leaf node)
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // Case 2: Node with one child
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Node with two children
        struct Node *temp = FindMin(root->right);      // Find the in-order successor
        root->data = temp->data;                       // Replace with in-order successor's data
        root->right = Delete(root->right, temp->data); // Delete the in-order successor
    }
    return root;
}

int main()
{
    struct Node *root = NULL;

    // Insert elements into the BST
    root = Insert(root, 50);
    root = Insert(root, 30);
    root = Insert(root, 70);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 60);
    root = Insert(root, 80);

    // Test In-Order Traversal
    printf("In-order Traversal: ");
    InOrderTraversal(root);
    printf("\n");

    // Test Pre-Order Traversal
    printf("Pre-order Traversal: ");
    PreOrderTraversal(root);
    printf("\n");

    // Test Level-Order Traversal
    printf("Level-order Traversal: ");
    LevelOrderTraversal(root);
    printf("\n");

    // Test Iterative Search
    struct Node *searchResultIter = SearchIterative(root, 40);
    if (searchResultIter != NULL)
        printf("Iterative Search: Found %d\n", searchResultIter->data);
    else
        printf("Iterative Search: Not Found\n");

    // Test Recursive Search
    struct Node *searchResultRec = SearchRecursive(root, 25);
    if (searchResultRec != NULL)
        printf("Recursive Search: Found %d\n", searchResultRec->data);
    else
        printf("Recursive Search: Not Found\n");

    // Test Delete
    printf("Deleting 20\n");
    root = Delete(root, 20);
    printf("In-order Traversal after Deletion: ");
    InOrderTraversal(root);
    printf("\n");

    printf("Deleting 30\n");
    root = Delete(root, 30);
    printf("In-order Traversal after Deletion: ");
    InOrderTraversal(root);
    printf("\n");

    printf("Deleting 50\n");
    root = Delete(root, 50);
    printf("In-order Traversal after Deletion: ");
    InOrderTraversal(root);
    printf("\n");

    return 0;
}