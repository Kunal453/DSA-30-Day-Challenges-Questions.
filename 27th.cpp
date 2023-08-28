#include <iostream>

using namespace std;

// Binary tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to perform reverse in-order traversal to find Kth largest element
void kthLargestUtil(TreeNode* root, int& k, int& result) {
    if (!root || k == 0) {
        return;
    }

    kthLargestUtil(root->right, k, result); // Traverse right subtree

    if (--k == 0) {
        result = root->val; // Kth largest element found
        return;
    }

    kthLargestUtil(root->left, k, result); // Traverse left subtree
}

// Function to find Kth largest element in a BST
int kthLargest(TreeNode* root, int k) {
    int result = -1; // Initialize result to an invalid value
    kthLargestUtil(root, k, result);
    return result;
}

// Helper function to create a binary search tree
TreeNode* insert(TreeNode* root, int value) {
    if (!root) {
        return new TreeNode(value);
    }
    if (value < root->val) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int k = 3;
    int kthLargestElement = kthLargest(root, k);
    if (kthLargestElement != -1) {
        cout << "Kth largest element: " << kthLargestElement << endl;
    } else {
        cout << "Invalid input for K." << endl;
    }

    return 0;
}
