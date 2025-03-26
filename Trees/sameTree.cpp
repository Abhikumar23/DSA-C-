#include <iostream>

using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check if two trees are identical
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL) {
        return false;
    }

    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    bool value = (p->val == q->val);

    return left && right && value;
}

// Driver code
int main() {
    // Creating Tree 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    // Creating Tree 2 (identical to Tree 1)
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    // Check if trees are identical
    if (isSameTree(root1, root2)) {
        cout << "The two trees are the same." << endl;
    } else {
        cout << "The two trees are different." << endl;
    }

    return 0;
}
