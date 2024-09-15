#include <cstdlib>
#include <iostream>
using namespace std;

/////////////////////////////// Tree Node Class
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

/////////////////////////////// Queue Class (Array-Based)
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
        this->front = this->rear = -1;
        this->Q = new Node *[size];
    }

    bool IsQueueEmpty() { return front == rear; }
    bool IsQueueFull() { return rear == size - 1; }

    void EnQueue(Node *treeNode)
    {
        if (IsQueueFull())
            cout << "Queue is Full\n";
        else
            Q[++rear] = treeNode;
    }

    Node *DeQueue()
    {
        if (IsQueueEmpty())
            return nullptr;
        else
            return Q[++front];
    }
};

/////////////////////////////// BST Class
class BST
{
private:
    Node *root;

    // Helper function to find the minimum node in the right subtree
    Node *FindMin(Node *node)
    {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

public:
    BST()
    {
        root = nullptr;
    }

    void Insert(int key)
    {
        Node *newNode = new Node(key);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        Node *current = root;
        Node *parent = nullptr;

        while (current != nullptr)
        {
            parent = current;
            if (key < current->data)
                current = current->left;
            else if (key > current->data)
                current = current->right;
            else
                return;
        }

        if (key < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    Node *SearchIterative(int key)
    {
        Node *current = root;
        while (current != nullptr)
        {
            if (key == current->data)
                return current;
            else if (key < current->data)
                current = current->left;
            else
                current = current->right;
        }

        return nullptr;
    }

    Node *SearchRecursive(Node *root, int key)
    {
        if (root == nullptr || root->data == key)
            return root;

        if (key < root->data)
            return SearchRecursive(root->left, key);
        else
            return SearchRecursive(root->right, key);
    }

    Node *SearchRecursive(int key)
    {
        return SearchRecursive(root, key);
    }

    // Delete a node in the BST
    Node *DeleteNode(Node *node, int key)
    {
        if (node == nullptr)
            return node;

        // Traverse left or right based on the key
        if (key < node->data)
            node->left = DeleteNode(node->left, key);
        else if (key > node->data)
            node->right = DeleteNode(node->right, key);
        else
        {
            // Case 1: No child (leaf node)
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }

            // Case 2: One child (left or right)
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            Node *temp = FindMin(node->right);                 // Find the minimum node in the right subtree
            node->data = temp->data;                           // Replace current node with the min node's data
            node->right = DeleteNode(node->right, temp->data); // Delete the min node
        }

        return node;
    }

    void Delete(int key) { root = DeleteNode(root, key); }

    void InOrderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            InOrderTraversal(node->left);
            cout << node->data << " ";
            InOrderTraversal(node->right);
        }
    }

    void InOrderTraversal()
    {
        InOrderTraversal(root);
        cout << endl;
    }

    void PreOrderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
            PreOrderTraversal(node->left);
            PreOrderTraversal(node->right);
        }
    }

    void PreOrderTraversal()
    {
        PreOrderTraversal(root);
        cout << endl;
    }

    void LevelOrderTraversal()
    {
        if (root == nullptr)
            return;

        Queue q(100);
        q.EnQueue(root);

        while (!q.IsQueueEmpty())
        {
            Node *current = q.DeQueue();
            cout << current->data << " ";

            if (current->left != nullptr)
                q.EnQueue(current->left);

            if (current->right != nullptr)
                q.EnQueue(current->right);
        }
        cout << endl;
    }
};

int main()
{
    BST tree;

    // Insert elements into the BST
    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);

    cout << "In-order Traversal: ";
    tree.InOrderTraversal();

    cout << "Pre-order Traversal: ";
    tree.PreOrderTraversal();

    cout << "Level-order Traversal: ";
    tree.LevelOrderTraversal();

    // Search for a node iteratively
    Node *searchResultIter = tree.SearchIterative(40);
    if (searchResultIter != nullptr)
        cout << "Iterative Search: Found " << searchResultIter->data << endl;
    else
        cout << "Iterative Search: Not Found\n";

    // Search for a node recursively
    Node *searchResultRec = tree.SearchRecursive(25);
    if (searchResultRec != nullptr)
        cout << "Recursive Search: Found " << searchResultRec->data << endl;
    else
        cout << "Recursive Search: Not Found\n";

    // Delete a node
    tree.Delete(20);
    cout << "In-order Traversal after deleting 20: ";
    tree.InOrderTraversal();

    tree.Delete(30);
    cout << "In-order Traversal after deleting 30: ";
    tree.InOrderTraversal();

    tree.Delete(50);
    cout << "In-order Traversal after deleting 50: ";
    tree.InOrderTraversal();

    return 0;
}
