// Lowest common ancestor of Binary Tree

// Approach 1 is to store path from root to n1 and root to n2. Now in that path last matching node is LCA. TC is O(n) and SC is also O(n)
// Code
  bool findPath(Node *root, vector<int> &path, int k) 
{ 
    // base case 
    if (root == NULL) return false; 
  
    // Store this node in path vector. The node will be removed if 
    // not in path from root to k 
    path.push_back(root->key); 
  
    // See if the k is same as root's key 
    if (root->key == k) 
        return true; 
  
    // Check if k is found in left or right sub-tree 
    if ( (root->left && findPath(root->left, path, k)) || 
         (root->right && findPath(root->right, path, k)) ) 
        return true; 
  
    // If not present in subtree rooted with root, remove root from 
    // path[] and return false 
    path.pop_back(); 
    return false; 
} 
  
// Returns LCA if node n1, n2 are present in the given binary tree, 
// otherwise return -1 
int findLCA(Node *root, int n1, int n2) 
{ 
    // to store paths to n1 and n2 from the root 
    vector<int> path1, path2; 
  
    // Find paths from root to n1 and root to n1. If either n1 or n2 
    // is not present, return -1 
    if ( !findPath(root, path1, n1) || !findPath(root, path2, n2)) 
          return -1; 
  
    /* Compare the paths to get the first different value */
    int i; 
    for (i = 0; i < path1.size() && i < path2.size() ; i++) 
        if (path1[i] != path2[i]) 
            break; 
    return path1[i-1]; 
} 


// Another approach is to traverse tree and if one element is in left subtree and one in right then root is ancestor. if both values are in same subtree then LCA 
// also in that subtree here TC is O(n) and SC is O(1).

// Code
  struct Node *findLCA(struct Node* root, int n1, int n2) 
{ 
    // Base case 
    if (root == NULL) return NULL; 
  
    // If either n1 or n2 matches with root's key, report 
    // the presence by returning root (Note that if a key is 
    // ancestor of other, then the ancestor key becomes LCA 
    if (root->key == n1 || root->key == n2) 
        return root; 
  
    // Look for keys in left and right subtrees 
    Node *left_lca  = findLCA(root->left, n1, n2); 
    Node *right_lca = findLCA(root->right, n1, n2); 
  
    // If both of the above calls return Non-NULL, then one key 
    // is present in once subtree and other is present in other, 
    // So this node is the LCA 
    if (left_lca && right_lca)  return root; 
  
    // Otherwise check if left subtree or right subtree is LCA 
    return (left_lca != NULL)? left_lca: right_lca; 
}

//  Above method assume that values are present in tree . so it will give wrong ans if any value is not present so to deal with it we can have 2 bool variable
//  n1 and n2 and set them true when corresponding node found and return ans only if both are true

// Code
  struct Node *findLCAUtil(struct Node* root, int n1, int n2, bool &v1, bool &v2) 
{ 
    // Base case 
    if (root == NULL) return NULL; 
  
    // If either n1 or n2 matches with root's key, report the presence 
    // by setting v1 or v2 as true and return root (Note that if a key 
    // is ancestor of other, then the ancestor key becomes LCA) 
    if (root->key == n1) 
    { 
        v1 = true; 
        return root; 
    } 
    if (root->key == n2) 
    { 
        v2 = true; 
        return root; 
    } 
  
    // Look for keys in left and right subtrees 
    Node *left_lca  = findLCAUtil(root->left, n1, n2, v1, v2); 
    Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2); 
  
    // If both of the above calls return Non-NULL, then one key 
    // is present in once subtree and other is present in other, 
    // So this node is the LCA 
    if (left_lca && right_lca)  return root; 
  
    // Otherwise check if left subtree or right subtree is LCA 
    return (left_lca != NULL)? left_lca: right_lca; 
} 

// Returns true if key k is present in tree rooted with root 
bool find(Node *root, int k) 
{ 
    // Base Case 
    if (root == NULL) 
        return false; 
  
    // If key is present at root, or in left subtree or right subtree, 
    // return true; 
    if (root->key == k || find(root->left, k) ||  find(root->right, k)) 
        return true; 
  
    // Else return false 
    return false; 
} 
  
// This function returns LCA of n1 and n2 only if both n1 and n2 are present 
// in tree, otherwise returns NULL; 
Node *findLCA(Node *root, int n1, int n2) 
{ 
    // Initialize n1 and n2 as not visited 
    bool v1 = false, v2 = false; 
  
    // Find lca of n1 and n2 using the technique discussed above 
    Node *lca = findLCAUtil(root, n1, n2, v1, v2); 
  
    // Return LCA only if both n1 and n2 are present in tree 
    if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1)) 
        return lca; 
  
    // Else return NULL 
    return NULL; 
} 

// Another is to use parent pointer method
/*
  Create an empty hash table.
  Insert n1 and all of its ancestors in hash table.
  Check if n2 or any of its ancestors exist in hash table, if yes return the first existing ancestor.
*/
//  Code
  Node *insert(Node *node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
    { 
        node->left  = insert(node->left, key); 
        node->left->parent = node; 
    } 
    else if (key > node->key) 
    { 
        node->right = insert(node->right, key); 
        node->right->parent = node; 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  
// To find LCA of nodes n1 and n2 in Binary Tree 
Node *LCA(Node *n1, Node *n2) 
{ 
   // Creata a map to store ancestors of n1 
   map <Node *, bool> ancestors; 
  
   // Insert n1 and all its ancestors in map 
   while (n1 != NULL) 
   { 
       ancestors[n1] = true; 
       n1 = n1->parent; 
   } 
  
   // Check if n2 or any of its ancestors is in 
   // map. 
   while (n2 != NULL) 
   { 
       if (ancestors.find(n2) != ancestors.end()) 
           return n2; 
       n2 = n2->parent; 
   } 
  
   return NULL; 
} 

// Another is to find both node and traverse back until they met each other when they meet then that node is ancestor but first bring these n1 and n2 on same level
