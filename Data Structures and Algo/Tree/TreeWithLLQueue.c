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

struct QueueNode
{
    struct Node *treeNode;
    struct QueueNode *next;
};

struct Queue
{
    struct QueueNode *front;
    struct QueueNode *rear;
};

struct QueueNode *CreateQueueNode(struct Node *treeNode)
{
    struct QueueNode *newQueueNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;
    return newQueueNode;
}

void CreateQueue(struct Queue *q) { q->front = q->rear = NULL; }

void EnQueue(struct Queue *q, struct Node *treeNode)
{
    struct QueueNode *newQueueNode = CreateQueueNode(treeNode);
    if (q->rear == NULL)
        q->front = q->rear = newQueueNode;
    else
    {
        q->rear->next = newQueueNode;
        q->rear = newQueueNode;
    }
}

struct Node *DeQueue(struct Queue *q)
{
    if (q->front == NULL)
        return NULL;

    struct QueueNode *temp = q->front;
    struct Node *treeNode = temp->treeNode;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return treeNode;
}

int IsQueueEmpty(struct Queue *q) { return q->front == NULL; }

/////////////////////////////‌ Tree
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
    if (root == NULL)
        return;

    struct Queue q;
    CreateQueue(&q);

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
    struct Node *root = InitializeTree();

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
