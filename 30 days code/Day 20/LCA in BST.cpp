// recursive approach
/*
  Start traversing the tree from the root node.
  If both the nodes p and q are in the right subtree, then continue the search with right subtree starting step 1.
  If both the nodes p and q are in the left subtree, then continue the search with left subtree starting step 1.
  If both step 2 and step 3 are not true, this means we have found the node which is common to node p's and q's subtrees. and hence we return this common node as the LCA.
*/

// code
      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int parentVal = root->val;

        // Value of p
        int pVal = p->val;

        // Value of q;
        int qVal = q->val;

        if (pVal > parentVal && qVal > parentVal) {
            // If both p and q are greater than parent
            return lowestCommonAncestor(root->right, p, q);
        } else if (pVal < parentVal && qVal < parentVal) {
            // If both p and q are lesser than parent
            return lowestCommonAncestor(root->left, p, q);
        } else {
            // We have found the split point, i.e. the LCA node.
            return root;
        }
    }
    
// Iterative code
      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         // Value of p
        int pVal = p->val;
        // Value of q;
        int qVal = q->val;
        // Start from the root node of the tree
        TreeNode* node = root;
        // Traverse the tree
        while (node != nullptr) {
            // Value of ancestor/parent node.
            int parentVal = node->val;
            if (pVal > parentVal && qVal > parentVal) {
                // If both p and q are greater than parent
                node = node->right;
            } else if (pVal < parentVal && qVal < parentVal) {
                // If both p and q are lesser than parent
                node = node->left;
            } else {
                // We have found the split point, i.e. the LCA node.
                return node;
            }
        }
        return nullptr;
    }
