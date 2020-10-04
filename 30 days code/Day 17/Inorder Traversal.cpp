// InOrder Traversal of binary tree

// Recursive code
      void traverse(TreeNode* root, vector<int> &res){
        if(root->left != NULL)traverse(root->left, res);
        res.push_back(root->val);
        if(root->right != NULL)traverse(root->right, res);

    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if(root == NULL) return res;
        traverse(root, res);
        return res;
    }
    
// Iterative approach with O(n)
     vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while (curr != NULL || !s.empty()) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
    
//  We have one more iterative approach with O(1) space complexity -  Morris Traversal // in it for backtracking we create link from rightmost child of next left to parent

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        TreeNode* pre;
        while (curr != NULL) {
            if (curr->left == NULL) {
                res.push_back(curr->val);
                curr = curr->right; // move to next right node
            } else { // has a left subtree
                pre = curr->left;
                while (pre->right != NULL) { // find rightmost
                    pre = pre->right;
                }
                pre->right = curr; // put cur after the pre node
                TreeNode* temp = curr; // store cur node
                curr = curr->left; // move cur to the top of the new tree
                temp->left = NULL; // original cur left be null, avoid infinite loops
            }
        }
        return res;
    }
