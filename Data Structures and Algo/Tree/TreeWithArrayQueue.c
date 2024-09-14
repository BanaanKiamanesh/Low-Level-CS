#include <stdio.h>
#include <stdlib.h>

/* Impl of of Trees inside a Queue that is made by an Array..
   I wanna keep everything inside a single file so... */

/////////////////////////////// Queue
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

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
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

int IsFull(struct Queue *q) { return (q->rear == q->size - 1); }
int IsEmpty(struct Queue *q) { return (q->front == q->rear); }

void EnQueue(struct Queue *q, struct Node *treeNode)
{
    if (IsFull(q))
        printf("Queue is Full\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = treeNode;
    }
}

struct Node *DeQueue(struct Queue *q)
{
    struct Node *treeNode = NULL;
    if (IsEmpty(q))
        printf("Queue is Empty\n");
    else
        treeNode = q->Q[++q->front];

    return treeNode;
}

//////////////////////////////// Tree
struct Node *CreateTreeNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *InitializeTree()
{
    struct Node *root = CreateTreeNode(1);

    root->left = CreateTreeNode(2);
    root->right = CreateTreeNode(3);

    root->left->left = CreateTreeNode(4);
    root->left->right = CreateTreeNode(5);

    root->right->left = CreateTreeNode(6);
    root->right->right = CreateTreeNode(7);

    return root;
}

struct Node *CreateTree()
{
    struct Queue q;
    CreateQueue(&q, 100);

    struct Node *root = InitializeTree();
    EnQueue(&q, root);

    while (!IsEmpty(&q))
    {
        struct Node *current = DeQueue(&q);

        if (current->left != NULL)
            EnQueue(&q, current->left);

        if (current->right != NULL)
            EnQueue(&q, current->right);
    }

    return root;
}

void InOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    InOrderTraversal(root->left);
    printf("%d ", root->data);
    InOrderTraversal(root->right);
}

void LevelOrderTraversal(struct Node *root)
{
    struct Queue q;
    CreateQueue(&q, 100);
    EnQueue(&q, root);

    while (!IsEmpty(&q))
    {
        struct Node *current = DeQueue(&q);
        printf("%d ", current->data);

        if (current->left != NULL)
            EnQueue(&q, current->left);

        if (current->right != NULL)
            EnQueue(&q, current->right);
    }

    printf("\n");
}

int CountNodes(struct Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + CountNodes(root->left) + CountNodes(root->right);
}

int GetTreeHeight(struct Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = GetTreeHeight(root->left);
    int rightHeight = GetTreeHeight(root->right);

    // Height = 1 (current node) + max(Height of left subtree, Height of right subtree)
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main()
{
    struct Node *root = CreateTree();

    printf("In-order traversal of the tree: ");
    InOrderTraversal(root);
    printf("\n");

    printf("Level-order traversal of the tree: ");
    LevelOrderTraversal(root);
    printf("\n");

    int totalNodes = CountNodes(root);
    printf("Total number of nodes in the tree: %d\n", totalNodes);

    int treeHeight = GetTreeHeight(root);
    printf("Height of the tree: %d\n", treeHeight);

    return 0;
}