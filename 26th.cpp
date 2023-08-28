#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

vector<int> largestValuesInLevels(TreeNode *root)
{
    vector<int> result;
    if (root == nullptr)
    {
        return result;
    }

    queue<TreeNode *> levelQueue;
    levelQueue.push(root);

    while (!levelQueue.empty())
    {
        int levelSize = levelQueue.size();
        int maxVal = INT_MIN;

        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *currentNode = levelQueue.front();
            levelQueue.pop();

            maxVal = max(maxVal, currentNode->val);

            if (currentNode->left)
            {
                levelQueue.push(currentNode->left);
            }
            if (currentNode->right)
            {
                levelQueue.push(currentNode->right);
            }
        }

        result.push_back(maxVal);
    }

    return result;
}

// Helper function to create a binary tree
TreeNode *createBinaryTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    return root;
}

int main()
{
    TreeNode *root = createBinaryTree();
    vector<int> result = largestValuesInLevels(root);

    cout << "Largest values in each level: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
