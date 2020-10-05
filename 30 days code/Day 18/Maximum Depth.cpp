    void find_depth(TreeNode* root, int level, int* ans){
        if(!root->right && !root->left){
            *ans = max(*ans, level);
        }
        if(root->left)find_depth(root->left, level+1, ans);
        if(root->right)find_depth(root->right, level+1, ans);

    }
    int maxDepth(TreeNode* root) {
        int ans = 0;
        if(!root)return ans;
        find_depth(root, 1, &ans);
        return ans;
    }
    
// Another way same approach

    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
