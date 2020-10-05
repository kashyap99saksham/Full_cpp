/*
  Description : Given a binary tree, flatten it to a linked list in-place.
                For example, given the following tree:
                    1
                   / \
                  2   5
                 / \   \
                3   4   6
                The flattened tree should look like:
                1
                 \
                  2
                   \
                    3
                     \
                      4
                       \
                        5
                         \
                          6
*/

// iterative code
      void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* curr = root;
        while(curr){
            TreeNode* nxt = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
            TreeNode* temp = curr;
            while(temp->right)
                temp = temp->right;
            temp->right = nxt;
            curr = curr->right;
        }
    }
