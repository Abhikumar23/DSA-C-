#include <iostream>
#include <vector>

using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to construct BST from sorted array
TreeNode* solve(vector<int>& nums, int s, int e) {
    if (s > e)
        return NULL;

    int mid = s + (e - s) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = solve(nums, s, mid - 1);
    root->right = solve(nums, mid + 1, e);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return solve(nums, 0, nums.size() - 1);
}

// Inorder traversal to verify BST structure
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Driver code
int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};  // Example sorted array

    TreeNode* root = sortedArrayToBST(nums);

    cout << "Inorder Traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
