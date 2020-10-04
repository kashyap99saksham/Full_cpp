    int pre = 0;
    TreeNode* make_tree(vector<int>& preorder, vector<int>& inorder, int Start, int End){
        if(Start > End)
            return NULL;
        TreeNode* node = new TreeNode(preorder[pre++]);
        if(Start == End) return node;
        int rootIndex = Start;
        for(; rootIndex <= End; rootIndex++){
            if(inorder[rootIndex] == node->val)
                break;
        }
        int leftTreeSize = rootIndex - Start;
        int rightTreeSize = End - rootIndex;
        node->left = make_tree(preorder, inorder, Start, rootIndex -1);
        node->right = make_tree(preorder, inorder, rootIndex+1, End);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m = preorder.size();
        if(!m) return NULL;
        // TreeNode* root = TreeNode(inorder[m-1]);
        return make_tree(preorder, inorder, 0, m-1);

    }
    
    // We can save the searching time by saving index of each element in a map but it will cost memory
