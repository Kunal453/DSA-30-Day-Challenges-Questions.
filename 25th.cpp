#include <iostream>
#include <cmath>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

int height(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return 1 + std::max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode *root)
{
    if (root == nullptr)
        return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (std::abs(leftHeight - rightHeight) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    if (isBalanced(root))
    {
        std::cout << "The binary tree is balanced." << std::endl;
    }
    else
    {
        std::cout << "The binary tree is not balanced." << std::endl;
    }

    return 0;
}
