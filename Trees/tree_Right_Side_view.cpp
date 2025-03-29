vector<int> rightSideView(TreeNode* root) {
    vector<int>ans;
    queue<TreeNode*>que;
    if(!root){
        return ans;
    }
    que.push(root);

    while(!que.empty()){
        int size= que.size();
         TreeNode* temp= que.front();

        ans.push_back(temp->val);
        
        for(int i=0; i<size; i++){
            TreeNode* temp= que.front();
            que.pop();
            
            if(temp->right){
                que.push(temp->right);
            }
            if(temp->left){
                que.push(temp->left);
            }
        }

    }
    return ans;

}