#include <stdio.h>
#include <stdlib.h>

/////////////////////////////// AVL Tree Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

int NodeHeight(struct Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int BalanceFactor(struct Node *node)
{
    if (node == NULL)
        return 0;
    return NodeHeight(node->left) - NodeHeight(node->right);
}

int Max(int a, int b) { return (a > b) ? a : b; }

struct Node *CreateNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1; // New node is initially added at leaf
    return node;
}

/////////////////////////////// Rotations
struct Node *RightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = Max(NodeHeight(y->left), NodeHeight(y->right)) + 1;
    x->height = Max(NodeHeight(x->left), NodeHeight(x->right)) + 1;

    return x;
}

    struct Node *LeftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = Max(NodeHeight(x->left), NodeHeight(x->right)) + 1;
    y->height = Max(NodeHeight(y->left), NodeHeight(y->right)) + 1;

    return y;
}

/////////////////////////////// Insert Function
struct Node *Insert(struct Node *node, int key)
{
    if (node == NULL)
        return CreateNode(key);

    if (key < node->data)
        node->left = Insert(node->left, key);
    else if (key > node->data)
        node->right = Insert(node->right, key);
    else // Duplicate keys are not allowed in BST
        return node;

    node->height = 1 + Max(NodeHeight(node->left), NodeHeight(node->right));

    int balance = BalanceFactor(node);

    if (balance > 1 && key < node->left->data)
        return RightRotate(node);

    if (balance < -1 && key > node->right->data)
        return LeftRotate(node);

    if (balance > 1 && key > node->left->data)
    {
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }

    if (balance < -1 && key < node->right->data)
    {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    return node;
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

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **array;
};

void CreateQueue(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->array = (struct Node **)malloc(size * sizeof(struct Node *));
}

int IsQueueEmpty(struct Queue *q) { return q->front == q->rear; }

void EnQueue(struct Queue *q, struct Node *node)
{
    if (q->rear == q->size - 1)
        return; // Queue is full
    q->array[++q->rear] = node;
}

struct Node *DeQueue(struct Queue *q)
{
    if (IsQueueEmpty(q))
        return NULL;
    return q->array[++q->front];
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
        struct Node *node = DeQueue(&q);
        printf("%d ", node->data);

        if (node->left != NULL)
            EnQueue(&q, node->left);

        if (node->right != NULL)
            EnQueue(&q, node->right);
    }

    free(q.array);
}

int main()
{
    struct Node *root = NULL;

    // Insert nodes into the AVL tree
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 40);
    root = Insert(root, 50);
    root = Insert(root, 25);

    // Test Pre-order Traversal
    printf("Pre-order Traversal: ");
    PreOrderTraversal(root);
    printf("\n");

    // Test In-order Traversal
    printf("In-order Traversal: ");
    InOrderTraversal(root);
    printf("\n");

    // Test Level-order Traversal
    printf("Level-order Traversal: ");
    LevelOrderTraversal(root);
    printf("\n");

    return 0;
}
