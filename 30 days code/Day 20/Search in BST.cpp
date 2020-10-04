// Recursive code
     TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root->val == val)return root;
        else if(root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
        return NULL;
    }
    
// Iterative approach
          while (root != nullptr && root->val != val) {
            root = (root->val > val) ? root->left : root->right;
        }
        
        return root;
