// Recursive code
     void traverse(TreeNode* root, vector<int> &res){
        res.push_back(root->val);
        if(root->left != NULL)
            traverse(root->left, res);
        if(root->right != NULL)
            traverse(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)return res;
        traverse(root, res);
        return res;
    }
    
//  Iterative using stack
     vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)return res;
        stack<TreeNode* > s;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            res.push_back(temp->val);
            if(temp->right != NULL)s.push(temp->right);
            if(temp->left != NULL)s.push(temp->left);
        }
        return res;
    }
    
