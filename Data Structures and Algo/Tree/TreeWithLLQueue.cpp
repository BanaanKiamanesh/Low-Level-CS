#include <iostream>

/////////////////////////////// Tree Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

/////////////////////////////// Queue Node
class QueueNode
{
public:
    Node *treeNode;
    QueueNode *next;

    QueueNode(Node *node)
    {
        treeNode = node;
        next = nullptr;
    }
};

/////////////////////////////// Queue
class Queue
{
private:
    QueueNode *front;
    QueueNode *rear;

public:
    Queue() { front = rear = nullptr; }

    void EnQueue(Node *treeNode)
    {
        QueueNode *newQueueNode = new QueueNode(treeNode);
        if (rear == nullptr)
            front = rear = newQueueNode;
        else
        {
            rear->next = newQueueNode;
            rear = newQueueNode;
        }
    }

    Node *DeQueue()
    {
        if (front == nullptr)
            return nullptr;

        QueueNode *temp = front;
        Node *treeNode = temp->treeNode;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
        return treeNode;
    }

    bool IsQueueEmpty() { return front == nullptr; }
};

///////////////////////////// Tree
Node *InitializeTree()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

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

    Queue q;
    q.EnQueue(root);

    while (!q.IsQueueEmpty())
    {
        Node *current = q.DeQueue();
        std::cout << current->data << " ";

        if (current->left != nullptr)
            q.EnQueue(current->left);

        if (current->right != nullptr)
            q.EnQueue(current->right);
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

    // Height = 1 (current node) + max(Height of left subtree, Height of right subtree)
    return 1 + std::max(leftHeight, rightHeight);
}

int main()
{
    Node *root = InitializeTree();

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
