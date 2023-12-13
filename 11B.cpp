/*Create binary tree. Find height of the tree and print
leaf nodes. Find mirror image, print original and
mirror image using level-wise printing. */
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int height(Node* root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

void printLeafNodes(Node* root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        cout << root->data << " ";
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

Node* mirror(Node* root)
{
    if (root == NULL)
        return NULL;
    Node* left = mirror(root->left);
    Node* right = mirror(root->right);
    root->left = right;
    root->right = left;
    return root;
}

void printLevelWise(Node* root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printLevelWise(root->left);
    printLevelWise(root->right);
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Height of tree: " << height(root) << endl;
    cout << "Leaf nodes: ";
    printLeafNodes(root);
    cout << endl;

    Node* mirrorRoot = mirror(root);
    cout << "Original tree: ";
    printLevelWise(root);
    cout << endl;
    cout << "Mirror image: ";
    printLevelWise(mirrorRoot);

    return 0;
}

