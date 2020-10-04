// Recursive code O(n) time and O(logn) space (recursive stack)
      bool isSameTree(TreeNode* p, TreeNode* q) {
            // p and q are both null
    if (p == NULL && q == NULL) return true;
    // one of p and q is null
    if (q == NULL || p == NULL) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->right, q->right) &&
            isSameTree(p->left, q->left);
    }
    
//  Iterative solution  
// We traverse both trees simultaneously and compare the data whenever we dequeue and item from queue

// Code
  bool areIdentical(Node *root1, Node *root2) 
{ 
    // Return true if both trees are empty 
    if (root1==NULL  && root2==NULL) return true; 
  
    // Return false if one is empty and other is not 
    if (root1 == NULL) return false; 
    if (root2 == NULL) return false; 
      
    // Create an empty queues for simultaneous traversals  
    queue<Node *> q1, q2; 
  
    // Enqueue Roots of trees in respective queues 
    q1.push(root1); 
    q2.push(root2); 
  
    while (!q1.empty() && !q2.empty()) 
    { 
        // Get front nodes and compare them 
        Node *n1 = q1.front(); 
        Node *n2 = q2.front(); 
  
        if (n1->data != n2->data) 
           return false; 
  
        // Remove front nodes from queues 
        q1.pop(), q2.pop(); 
  
        /* Enqueue left children of both nodes */
        if (n1->left && n2->left) 
        { 
            q1.push(n1->left); 
            q2.push(n2->left); 
        } 
  
        // If one left child is empty and other is not 
        else if (n1->left || n2->left) 
            return false; 
  
        // Right child code (Similar to left child code) 
        if (n1->right && n2->right) 
        { 
            q1.push(n1->right); 
            q2.push(n2->right); 
        } 
        else if (n1->right || n2->right) 
            return false; 
    } 
  
    return true; 
} 
  
