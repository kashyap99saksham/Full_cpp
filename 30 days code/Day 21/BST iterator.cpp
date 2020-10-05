/*
  Description : Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
                Calling next() will return the next smallest number in the BST.
  Example:
                BSTIterator iterator = new BSTIterator(root);
                iterator.next();    // return 3
                iterator.next();    // return 7
                iterator.hasNext(); // return true
                iterator.next();    // return 9
                iterator.hasNext(); // return true
                iterator.next();    // return 15
                iterator.hasNext(); // return true
                iterator.next();    // return 20
                iterator.hasNext(); // return false
  Note:
                next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
                You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.
*/

// Approach 1 is to do inorder traversal and put it in an array and keep at pointer initially at -1 and until ptr != length of array hasNext will give true
// and next will give value at that pointer O(n) and O(n)

// Approach 2 is using stack first we will go to left most node and while going we will push node on stack and after reaching when next will be called we will pop node 
// if node doesnt have any right child then simply pop but if it has right child then perform same process as we did for root mean go to leftmost child in current nodes right

// code
      bstit(node* root) 
    { 
        // Initializing stack 
        node* curr = root; 
        while (curr != NULL) 
            q.push(curr), curr = curr->left; 
    } 
  
    // Function to return 
    // current element iterator 
    // is pointing to 
    node* curr() 
    { 
        return q.top(); 
    } 
  
    // Function to iterate to next 
    // element of BST 
    void next() 
    { 
        node* curr = q.top()->right; 
        q.pop(); 
        while (curr != NULL) 
            q.push(curr), curr = curr->left; 
    } 
  
    // Function to check if 
    // stack is empty 
    bool isEnd() 
    { 
        return !(q.size()); 
    } 
    
// this will have O(n) and O(logn)
