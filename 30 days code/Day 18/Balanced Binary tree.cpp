// Tree is balanced if height differencece between left subtree and right subtree of any node is not greater than 1

// Code
   bool isBalanced(TreeNode* root) {
        if(root){
            int left = getheight(root->left);
            int right = getheight(root->right);
            return left != -1 && right != -1 && abs(left - right) < 2;
        }
        return true;
    }
    int getheight(TreeNode* root){
        if(root){
            int left = getheight(root->left);
            int right = getheight(root->right);
            return left != -1 && right != -1 && abs(left - right) < 2 ? max(left, right) + 1 : -1; 
        }
        return 0;
    }
