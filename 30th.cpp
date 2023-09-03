// Given a Binary Tree and a key, write a function that returns the level of the key?
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int findLevel(Node *root, int key, int level)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == key)
    {
        return level;
    }

    int leftLevel = findLevel(root->left, key, level + 1);
    if (leftLevel != -1)
    {
        return leftLevel;
    }

    int rightLevel = findLevel(root->right, key, level + 1);
    if (rightLevel != -1)
    {
        return rightLevel;
    }

    return -1;
}

int main()
{
    Node *root = new Node{1, new Node{2, new Node{4, NULL, NULL}, new Node{5, NULL, NULL}}, new Node{3, new Node{6, NULL, NULL}, new Node{7, NULL, NULL}}};
    int key = 5;
    int level = findLevel(root, key, 1);
    if (level != -1)
    {
        cout << "The level of the key " << key << " is " << level << endl;
    }
    else
    {
        cout << "The key " << key << " is not found in the tree" << endl;
    }
    return 0;
}
