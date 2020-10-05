/*
  Method 1 (Simple but inefficient)
  Start from root and do an inorder traversal of the tree. For each node N, check whether the subtree rooted with N is BST or not. 
  If BST, then return size of the subtree rooted with N. Else, recur down the left and right subtrees and return the maximum of values returned by left and right subtrees.
  O(n2)
*/
// code
  int largestBST(struct node *root) 
{ 
   if (isBST(root)) 
     return size(root);  
   else
    return max(largestBST(root->left), largestBST(root->right)); 
} 

/*
  Here we try to pass on information from down to up
  1) Whether the subtree itself is BST or not (In the following code, is_bst_ref is used for this purpose)
  2) If the subtree is left subtree of its parent, then maximum value in it. And if it is right subtree then minimum value in it.
  3) Size of this subtree if this subtree is BST (In the following code, return value of largestBSTtil() is used for this purpose)
  
  max_ref is used for passing the maximum value up the tree and min_ptr is used for passing minimum value up the tree.
  O(n)
*/
// code
  /* Returns size of the largest BST 
subtree in a Binary Tree  
(efficient version). */
int largestBST(node* node)  
{  
    // Set the initial values for 
    // calling largestBSTUtil()  
    int min = INT_MAX; // For minimum value in right subtree  
    int max = INT_MIN; // For maximum value in left subtree  
      
    int max_size = 0; // For size of the largest BST  
    bool is_bst = 0;  
      
    largestBSTUtil(node, &min, &max,  
                    &max_size, &is_bst);  
      
    return max_size;  
}  
  
/* largestBSTUtil() updates *max_size_ref 
for the size of the largest BST subtree. 
Also, if the tree rooted with node is  
non-empty and a BST, then returns size 
of the tree. Otherwise returns 0.*/
int largestBSTUtil(node* node, int *min_ref, int *max_ref,  
                    int *max_size_ref, bool *is_bst_ref)  
{  
  
    /* Base Case */
    if (node == NULL)  
    {  
        *is_bst_ref = 1; // An empty tree is BST  
        return 0; // Size of the BST is 0  
    }  
      
    int min = INT_MAX;  
      
    /* A flag variable for left subtree property  
        i.e., max(root->left) < root->data */
    bool left_flag = false;  
      
    /* A flag variable for right subtree property  
        i.e., min(root->right) > root->data */
    bool right_flag = false;  
      
    int ls, rs; // To store sizes of left and right subtrees  
      
    /* Following tasks are done by  
    recursive call for left subtree  
        a) Get the maximum value in left  
        subtree (Stored in *max_ref)  
        b) Check whether Left Subtree is  
        BST or not (Stored in *is_bst_ref)  
        c) Get the size of maximum size BST  
        in left subtree (updates *max_size) */
    *max_ref = INT_MIN;  
    ls = largestBSTUtil(node->left, min_ref, max_ref, 
                        max_size_ref, is_bst_ref);  
    if (*is_bst_ref == 1 && node->data > *max_ref)  
        left_flag = true;  
      
    /* Before updating *min_ref, store the min 
    value in left subtree. So that we have the 
    correct minimum value for this subtree */
    min = *min_ref;  
      
    /* The following recursive call 
    does similar (similar to left subtree)  
    task for right subtree */
    *min_ref = INT_MAX;  
    rs = largestBSTUtil(node->right, min_ref,  
                        max_ref, max_size_ref, is_bst_ref);  
    if (*is_bst_ref == 1 && node->data < *min_ref)  
        right_flag = true;  
      
    // Update min and max values for  
    // the parent recursive calls  
    if (min < *min_ref)  
        *min_ref = min;  
    if (node->data < *min_ref) // For leaf nodes  
        *min_ref = node->data;  
    if (node->data > *max_ref)  
        *max_ref = node->data;  
      
    /* If both left and right subtrees are BST.  
    And left and right subtree properties hold 
    for this node, then this tree is BST.  
    So return the size of this tree */
    if(left_flag && right_flag)  
    {  
        if (ls + rs + 1 > *max_size_ref)  
            *max_size_ref = ls + rs + 1;  
        return ls + rs + 1;  
    }  
    else
    {  
        // Since this subtree is not BST,  
        // set is_bst flag for parent calls  
        *is_bst_ref = 0;  
        return 0;  
    }  
} 

/*
  A Tree is BST if following is true for every node x.
  The largest value in left subtree (of x) is smaller than value of x.
  The smallest value in right subtree (of x) is greater than value of x.
  We traverse tree in bottom up manner. For every traversed node, we return maximum and minimum values in subtree rooted with it
  O(n)
*/
// code
  
// Returns Information about subtree. The 
// Information also includes size of largest 
// subtree which is a BST. 
Info largestBSTBT(Node* root) 
{ 
    // Base cases : When tree is empty or it has 
    // one child. 
    if (root == NULL) 
        return {0, INT_MIN, INT_MAX, 0, true}; // this is a struct of information type
    if (root->left == NULL && root->right == NULL) 
        return {1, root->data, root->data, 1, true}; 
  
    // Recur for left subtree and right subtrees 
    Info l = largestBSTBT(root->left); 
    Info r = largestBSTBT(root->right); 
  
    // Create a return variable and initialize its 
    // size. 
    Info ret; 
    ret.sz = (1 + l.sz + r.sz); 
  
    // If whole tree rooted under current root is 
    // BST. 
    if (l.isBST && r.isBST && l.max < root->data && 
            r.min > root->data) 
    { 
        ret.min = min(l.min, min(r.min, root->data)); 
        ret.max = max(r.max, max(l.max, root->data)); 
  
        // Update answer for tree rooted under 
        // current 'root' 
        ret.ans = ret.sz; 
        ret.isBST = true; 
  
        return ret; 
    } 
  
    // If whole tree is not BST, return maximum 
    // of left and right subtrees 
    ret.ans = max(l.ans, r.ans); 
    ret.isBST = false; 
  
    return ret; 
} 


