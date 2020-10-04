/*
  Approach 1: 
        is to do an inorder traversal and save values in an array this will give us the sorted array now we can simple return kth value from array O(n) and O(n)
  Approach 2:
        here we can keep track of number of nodes in left tree in for every root in subtree
        if (k == count+1) root is key if(k<count) key is in left else right O(height) O(height)
  Approach 3:
        convert tree in LL n apply LRU O(height) and O(1)
*/

        
