#include <iostream>

using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check if a root-to-leaf path equals targetSum
bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    }
    if (root->val == targetSum && root->left == NULL && root->right == NULL) {
        return true;
    }

    bool ans1 = hasPathSum(root->left, targetSum - root->val);
    bool ans2 = hasPathSum(root->right, targetSum - root->val);
    return ans1 || ans2;
}

// Driver code
int main() {


    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22; // Example: 5 -> 4 -> 11 -> 2 = 22

    if (hasPathSum(root, targetSum)) {
        cout << "There is a root-to-leaf path with sum " << targetSum << "." << endl;
    } else {
        cout << "No root-to-leaf path found with sum " << targetSum << "." << endl;
    }

    return 0;
}
