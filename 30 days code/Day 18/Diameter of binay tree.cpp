    int ans;
    int find_dia(TreeNode* node){
    
        if (node == NULL) return 0;
        int L = find_dia(node->left);
        int R = find_dia(node->right);
        ans = max(ans, L+R+1);
        return max(L, R) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        ans = 1;
        find_dia(root);
        return ans-1;
    }
