/*
  If given Tree is Binary Search Tree?
  If the given Binary Tree is Binary Search Tree, we can store it by either storing preorder or postorder traversal. 
  In case of Binary Search Trees, only preorder or postorder traversal is sufficient to store structure information.

  If given Binary Tree is Complete Tree?
  A Binary Tree is complete if all levels are completely filled except possibly the last level and all nodes of last level are as left as possible 
  (Binary Heaps are complete Binary Tree). For a complete Binary Tree, level order traversal is sufficient to store the tree. 
  We know that the first node is root, next two nodes are nodes of next level, next four nodes are nodes of 2nd level and so on.



  If given Binary Tree is Full Tree?
  A full Binary is a Binary Tree where every node has either 0 or 2 children. It is easy to serialize such trees as every internal node has 2 children. 
  We can simply store preorder traversal and store a bit with every node to indicate whether the node is an internal node or a leaf node.

  How to store a general Binary Tree?
  A simple solution is to store both Inorder and Preorder traversals. This solution requires requires space twice the size of Binary Tree.
  We can save space by storing Preorder traversal and a marker for NULL pointers like -1.
  
*/
// code
  void serialize(Node *root, FILE *fp) 
{ 
    // If current node is NULL, store marker 
    if (root == NULL) 
    { 
        fprintf(fp, "%d ", MARKER); 
        return; 
    } 
  
    // Else, store current node and recur for its children 
    fprintf(fp, "%d ", root->key); 
    serialize(root->left, fp); 
    serialize(root->right, fp); 
} 
  
// This function constructs a tree from a file pointed by 'fp' 
void deSerialize(Node *&root, FILE *fp) 
{ 
    // Read next item from file. If theere are no more items or next 
    // item is marker, then return 
    int val; 
    if ( !fscanf(fp, "%d ", &val) || val == MARKER) 
       return; 
  
    // Else create node with this item and recur for children 
    root = newNode(val); 
    deSerialize(root->left, fp); 
    deSerialize(root->right, fp); 
}

/*
  above code require n+1 marker for n keys we can optimize it as every leaf has 2 marker so instead we represent internal and leaf with different marker
  One simple optimization is to store a separate bit with every node to indicate that the node is internal or external. 
  This way we don’t have to store two markers with every leaf node as leaves can be identified by extra bit. 
  We still need marker for internal nodes with one child. For example in the following diagram ‘ is used to indicate an internal node set bit, 
  and ‘/’ is used as NULL marker.
  In an n-ary tree, there is no designated left or right child. We can store an ‘end of children’ marker with every node. 
  The following diagram shows serialization where ‘)’ is used as end of children marker.
*/

// code for n-ary tree
  void serialize(Node *root, FILE *fp) 
{ 
    // Base case 
    if (root == NULL) return; 
  
    // Else, store current node and recur for its children 
    fprintf(fp, "%c ", root->key); 
    for (int i = 0; i < N && root->child[i]; i++) 
         serialize(root->child[i],  fp); 
  
    // Store marker at the end of children 
    fprintf(fp, "%c ", MARKER); 
} 
  
// This function constructs N-ary tree from a file pointed by 'fp'. 
// This functionr returns 0 to indicate that the next item is a valid 
// tree key. Else returns 0 
int deSerialize(Node *&root, FILE *fp) 
{ 
    // Read next item from file. If theere are no more items or next 
    // item is marker, then return 1 to indicate same 
    char val; 
    if ( !fscanf(fp, "%c ", &val) || val == MARKER ) 
       return 1; 
  
    // Else create node with this item and recur for children 
    root = newNode(val); 
    for (int i = 0; i < N; i++) 
      if (deSerialize(root->child[i], fp)) 
         break; 
  
    // Finally return 0 for successful finish 
    return 0; 
} 
