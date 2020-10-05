// Recursive approach
/*
  Input: root node, key
  output: predecessor node, successor node
  1. If root is NULL
        then return
  2. if key is found then
      a. If its left subtree is not null
          Then predecessor will be the right most 
          child of left subtree or left child itself.
      b. If its right subtree is not null
          The successor will be the left most child 
          of right subtree or right child itself.
      return
  3. If key is smaller then root node
          set the successor as root
          search recursively into left subtree
      else
          set the predecessor as root
          search recursively into right subtree
*/

// code
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) 
{ 
    // Base case 
    if (root == NULL)  return ; 
  
    // If key is present at root 
    if (root->key == key) 
    { 
        // the maximum value in left subtree is predecessor 
        if (root->left != NULL) 
        { 
            Node* tmp = root->left; 
            while (tmp->right) 
                tmp = tmp->right; 
            pre = tmp ; 
        } 
  
        // the minimum value in right subtree is successor 
        if (root->right != NULL) 
        { 
            Node* tmp = root->right ; 
            while (tmp->left) 
                tmp = tmp->left ; 
            suc = tmp ; 
        } 
        return ; 
    } 
  
    // If key is smaller than root's key, go to left subtree 
    if (root->key > key) 
    { 
        suc = root ; 
        findPreSuc(root->left, pre, suc, key) ; 
    } 
    else // go to right subtree 
    { 
        pre = root ; 
        findPreSuc(root->right, pre, suc, key) ; 
    } 
} 

// Another approach   
/*
  We can also find the inorder successor and inorder predecessor using inorder traversal . 
  Check if the current node is smaller than the given key for predecessor and for successor, 
  check if it is greater than the given key . If it is greater than the given key then, 
  check if it is smaller than the already stored value in successor then, update it . 
  At last, get the predecessor and successor stored in q(successor) and p(predecessor).
*/

// Code
  void find_p_s(Node* root,int a,  
              Node** p, Node** q) 
{ 
    // If root is null return  
    if(!root) 
        return ; 
          
    // traverse the left subtree     
    find_p_s(root->left, a, p, q); 
      
    // root data is greater than a 
    if(root&&root->data > a) 
    { 
          
        // q stores the node whose data is greater 
        // than a and is smaller than the previously 
        // stored data in *q which is sucessor 
        if((!*q) || (*q) && (*q)->data > root->data) 
                *q = root; 
    } 
      
    // if the root data is smaller than 
    // store it in p which is predecessor 
    else if(root && root->data < a) 
    { 
        *p = root; 
    } 
      
    // traverse the right subtree 
    find_p_s(root->right, a, p, q); 
} 


// To solve the problem iteratively, the three cases while searching for the key has to be dealt with which are as described below:
/*
  Root is the given key:    In this case, if the left subtree is not NULL, 
                            then predecessor is the rightmost node in left subtree and if right subtree is not NULL, 
                            then successor is the leftmost node in right subtree.
  Root is greater than key: In this case, the key is present in left subtree of root. 
                            So search for the key in left subtree by setting root = root->left. 
                            Note that root could be an inorder successor of given key. In case the key has no right subtree, the root will be its successor.
  Root is less than key:    In this case, key is present in right subtree of root. 
                            So search for the key in right subtree by setting root = root->right. 
                            Note that root could be an inorder predecessor of given key. In case the key has no left subtree, the root will be its predecessor.
*/

// code
  void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) 
{ 
    if (root == NULL) 
        return; 
  
    // Search for given key in BST. 
    while (root != NULL) { 
  
        // If root is given key. 
        if (root->key == key) { 
  
            // the minimum value in right subtree 
            // is predecessor. 
            if (root->right) { 
                suc = root->right; 
                while (suc->left) 
                    suc = suc->left; 
            } 
  
            // the maximum value in left subtree 
            // is successor. 
            if (root->left) { 
                pre = root->left; 
                while (pre->right) 
                    pre = pre->right; 
            } 
  
            return; 
        } 
  
        // If key is greater than root, then 
        // key lies in right subtree. Root 
        // could be predecessor if left 
        // subtree of key is null. 
        else if (root->key < key) { 
            pre = root; 
            root = root->right; 
        } 
  
        // If key is smaller than root, then 
        // key lies in left subtree. Root 
        // could be successor if right 
        // subtree of key is null. 
        else { 
            suc = root; 
            root = root->left; 
        } 
    } 
} 
