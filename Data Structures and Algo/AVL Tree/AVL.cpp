#include <iostream>
#include <queue>
using namespace std;

/////////////////////////////// AVL Tree Node Class
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
        height = 1; // New node is initially added at leaf
    }
};

/////////////////////////////// AVL Tree Class
class AVLTree
{
public:
    int NodeHeight(Node *node) { return node ? node->height : 0; }

    int BalanceFactor(Node *node)
    {
        if (node == nullptr)
            return 0;
        return NodeHeight(node->left) - NodeHeight(node->right);
    }

    int Max(int a, int b) { return (a > b) ? a : b; }

    Node *RightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = Max(NodeHeight(y->left), NodeHeight(y->right)) + 1;
        x->height = Max(NodeHeight(x->left), NodeHeight(x->right)) + 1;

        return x;
    }

    Node *LeftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = Max(NodeHeight(x->left), NodeHeight(x->right)) + 1;
        y->height = Max(NodeHeight(y->left), NodeHeight(y->right)) + 1;

        return y;
    }

    Node *Insert(Node *node, int key)
    {
        if (node == nullptr)
            return new Node(key);

        if (key < node->data)
            node->left = Insert(node->left, key);
        else if (key > node->data)
            node->right = Insert(node->right, key);
        else
            return node; // No duplicates allowed in AVL tree

        node->height = 1 + Max(NodeHeight(node->left), NodeHeight(node->right));

        int balance = BalanceFactor(node);

        // Left Left Case
        if (balance > 1 && key < node->left->data)
            return RightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->data)
            return LeftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->data)
        {
            node->left = LeftRotate(node->left);
            return RightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->data)
        {
            node->right = RightRotate(node->right);
            return LeftRotate(node);
        }

        return node; // Return the unchanged node
    }

    void InOrderTraversal(Node *root)
    {
        if (root != nullptr)
        {
            InOrderTraversal(root->left);
            cout << root->data << " ";
            InOrderTraversal(root->right);
        }
    }

    void PreOrderTraversal(Node *root)
    {
        if (root != nullptr)
        {
            cout << root->data << " ";
            PreOrderTraversal(root->left);
            PreOrderTraversal(root->right);
        }
    }

    void LevelOrderTraversal(Node *root)
    {
        if (root == nullptr)
            return;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }
};

int main()
{
    AVLTree tree;
    Node *root = nullptr;

    // Insert nodes into the AVL tree
    root = tree.Insert(root, 10);
    root = tree.Insert(root, 20);
    root = tree.Insert(root, 30);
    root = tree.Insert(root, 40);
    root = tree.Insert(root, 50);
    root = tree.Insert(root, 25);

    // Test Pre-order Traversal
    cout << "Pre-order Traversal: ";
    tree.PreOrderTraversal(root);
    cout << endl;

    // Test In-order Traversal
    cout << "In-order Traversal: ";
    tree.InOrderTraversal(root);
    cout << endl;

    // Test Level-order Traversal
    cout << "Level-order Traversal: ";
    tree.LevelOrderTraversal(root);
    cout << endl;

    return 0;
}
