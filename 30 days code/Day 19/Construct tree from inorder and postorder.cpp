    TreeNode* make_tree(vector<int>& postorder, vector<int>& inorder, int Start, int End, int *pre){
        if(Start > End)
            return NULL;
        TreeNode* node = new TreeNode(postorder[*pre]);
        (*pre)--;
        if(Start == End) return node;
        int rootIndex = Start;
        for(; rootIndex <= End; rootIndex++){
            if(inorder[rootIndex] == node->val)
                break;
        }
        node->right = make_tree(postorder, inorder, rootIndex+1, End, pre);
        node->left = make_tree(postorder, inorder, Start, rootIndex - 1, pre);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int m = postorder.size();
            int pre = m-1;
        if(!m) return NULL;
        return make_tree(postorder, inorder, 0, m-1, &pre);
    }
