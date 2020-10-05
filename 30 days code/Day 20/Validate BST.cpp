// Recursive solution
      bool isValidBST(TreeNode* root, long long lower = LONG_MIN, long long upper = LONG_MIN){
        if(!root) return true;
        if(lower != LONG_MIN && root->val <= lower) return false;
        if(upper != LONG_MIN && root->val >= upper) return false;
        if(!isValidBST(root->right, root->val, upper))return false;
        if(!isValidBST(root->left, lower, root->val)) return false;
        return true;
    }
