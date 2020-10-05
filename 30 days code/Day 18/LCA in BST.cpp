// Approach is to use property of BST
/*
  1.  Create a recursive function that takes a node and the two values n1 and n2.
  2.  If the value of the current node is less than both n1 and n2, then LCA lies in the right subtree. Call the recursive function for thr right subtree.
  3.  If the value of the current node is greater than both n1 and n2, then LCA lies in the left subtree. Call the recursive function for thr left subtree.
  4.  If both the above cases are false then return the current node as LCA.
*/

// Code TC O(height) SC O(1) if not talking about recursive stack
  struct node *lca(struct node* root, int n1, int n2) 
{ 
    if (root == NULL) return NULL; 
  
    // If both n1 and n2 are smaller than root, then LCA lies in left 
    if (root->data > n1 && root->data > n2) 
        return lca(root->left, n1, n2); 
  
    // If both n1 and n2 are greater than root, then LCA lies in right 
    if (root->data < n1 && root->data < n2) 
        return lca(root->right, n1, n2); 
  
    return root; 
} 

// Iterative approach
  struct node *lca(struct node* root, int n1, int n2) 
{ 
    while (root != NULL) 
    { 
        // If both n1 and n2 are smaller than root, then LCA lies in left 
        if (root->data > n1 && root->data > n2) 
        root = root->left; 
  
        // If both n1 and n2 are greater than root, then LCA lies in right 
        else if (root->data < n1 && root->data < n2) 
        root = root->right; 
  
        else break; 
    } 
    return root; 
} 
  
