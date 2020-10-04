// Recursive code

     void traverse(TreeNode* root, vector<int> &res){
        if(root->left)traverse(root->left, res);
        if(root->right)traverse(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)return res;
        traverse(root, res);
        return res;
    }
    
// Iterative using stack
      vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)return res;
        stack<TreeNode* > s;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            res.push_back(temp->val);
            if(temp->left != NULL)s.push(temp->left);
            if(temp->right != NULL)s.push(temp->right);

        }
        reverse(res.begin(), res.end());
        return res;
    }
    
// Without using reverse function
      vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)return res;
        stack<TreeNode* > s;
        TreeNode* current = root;
        while(current != NULL || !s.empty()){
            if(current != NULL){
                s.push(current);
                current = current->left;
            }else{
                TreeNode* temp = s.top()->right;
                if (temp == NULL) {
                    temp = s.top();
                    s.pop();
                    res.push_back(temp->val);
                    while (!s.empty() && temp == s.top()->right) {
                        temp = s.top();
                        res.push_back(temp->val);
                        s.pop();
                    }
                } else {
                    current = temp;
                }
            }
        }
        return res;
    }
