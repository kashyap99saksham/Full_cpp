// This is simple approach left view will have 1st node of each level present in tree so we traverse tree level wise and print first node in each level

// Code
  void leftViewUtil(node* root, int level, int* max_level) { 
    // Base Case 
    if (root == NULL) 
        return; 
  
    // If this is the first node of its level 
    if (*max_level < level) { 
        cout << root->data << "\t"; 
        *max_level = level; 
    } 
  
    // Recur for left and right subtrees 
    leftViewUtil(root->left, level + 1, max_level); 
    leftViewUtil(root->right, level + 1, max_level); 
} 
  
// A wrapper over leftViewUtil() 
void leftView(node* root) 
{ 
    int max_level = 0; 
    leftViewUtil(root, 1, &max_level); 
} 

//  Iterative approach is to have a queue and insert a NULL delimeter after each level to mark the ending of level. and print first element in level

// Code 
  void leftViewUtil(struct node* root, queue<node*>& q) 
{ 
    if (root == NULL) 
        return; 
  
    // Push root 
    q.push(root); 
  
    // Delimiter 
    q.push(NULL); 
  
    while (!q.empty()) { 
        node* temp = q.front(); 
  
        if (temp) { 
  
            // Prints first node 
            // of each level 
            cout << temp->data << " "; 
  
            // Push children of all nodes at 
            // current level 
            while (q.front() != NULL) { 
  
                // If left child is present 
                // push into queue 
                if (temp->left) 
                    q.push(temp->left); 
  
                // If right child is present 
                // push into queue 
                if (temp->right) 
                    q.push(temp->right); 
  
                // Pop the current node 
                q.pop(); 
  
                temp = q.front(); 
            } 
  
            // Push delimiter 
            // for the next level 
            q.push(NULL); 
        } 
  
        // Pop the delimiter of 
        // the previous level 
        q.pop(); 
    } 
} 
  
// Fucntion to print the leftView 
// of Binary Tree 
void leftView(struct node* root) 
{ 
    // Queue to store all 
    // the nodes of the tree 
    queue<node*> q; 
  
    leftViewUtil(root, q); 
} 


// Other approach is to keep two parameter horizontal dist and vertical distance associated with nodes store value for each VD and give priority to less HD
