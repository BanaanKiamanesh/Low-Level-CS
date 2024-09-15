#include <iostream>
#include <queue>

/////////////////////////////// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

//////////////////////////////// Queue using Array
class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q;

public:
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new Node *[size];
    }

    bool IsFull() { return (rear == size - 1); }
    bool IsEmpty() { return (front == rear); }

    void EnQueue(Node *treeNode)
    {
        if (IsFull())
            std::cout << "Queue is Full\n";
        else
            Q[++rear] = treeNode;
    }

    Node *DeQueue()
    {
        Node *treeNode = nullptr;
        if (IsEmpty())
            std::cout << "Queue is Empty\n";
        else
            treeNode = Q[++front];
        return treeNode;
    }
};

//////////////////////////////// Tree
Node *CreateTreeNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node *InitializeTree()
{
    Node *root = CreateTreeNode(1);

    root->left = CreateTreeNode(2);
    root->right = CreateTreeNode(3);

    root->left->left = CreateTreeNode(4);
    root->left->right = CreateTreeNode(5);

    root->right->left = CreateTreeNode(6);
    root->right->right = CreateTreeNode(7);

    return root;
}

Node *CreateTree()
{
    Queue q(100);
    Node *root = InitializeTree();
    q.EnQueue(root);

    while (!q.IsEmpty())
    {
        Node *current = q.DeQueue();

        if (current->left != nullptr)
            q.EnQueue(current->left);

        if (current->right != nullptr)
            q.EnQueue(current->right);
    }

    return root;
}

void InOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    InOrderTraversal(root->left);
    std::cout << root->data << " ";
    InOrderTraversal(root->right);
}

void LevelOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    std::queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        std::cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }

    std::cout << "\n";
}

int CountNodes(Node *root)
{
    if (root == nullptr)
        return 0;

    return 1 + CountNodes(root->left) + CountNodes(root->right);
}

int GetTreeHeight(Node *root)
{
    if (root == nullptr)
        return 0;

    int leftHeight = GetTreeHeight(root->left);
    int rightHeight = GetTreeHeight(root->right);

    return 1 + std::max(leftHeight, rightHeight);
}

int main()
{
    Node *root = CreateTree();

    std::cout << "In-order traversal of the tree: ";
    InOrderTraversal(root);
    std::cout << "\n";

    std::cout << "Level-order traversal of the tree: ";
    LevelOrderTraversal(root);
    std::cout << "\n";

    int totalNodes = CountNodes(root);
    std::cout << "Total number of nodes in the tree: " << totalNodes << "\n";

    int treeHeight = GetTreeHeight(root);
    std::cout << "Height of the tree: " << treeHeight << "\n";

    return 0;
}
