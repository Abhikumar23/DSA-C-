int Solve(TreeNode* root,int& i, int k){
    if (root==NULL)
    return -1;
    int left=Solve(root->left,i,k);
    if(left!=-1){
        return left;
    }
    i++;
    if(i==k)
    return root->val;
    return Solve(root->right,i,k);
}
int kthSmallest(TreeNode* root, int k) {
   int i=0;
    int ans=Solve(root,i,k);
     return ans;
}