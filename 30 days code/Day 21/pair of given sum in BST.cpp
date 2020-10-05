// approach is to use set and search for complementary element in tree O(n) O(n)
// code
      bool find(TreeNode* root, int k, set <int> &s) {
        if (root == nullptr)
            return false;
        if (s.find(k - root->val)!=s.end())
            return true;
        s.insert(root->val);
        return find(root->left, k, s) || find(root->right, k, s);
    }
    bool findTarget(TreeNode* root, int k) {
        set <int> s;
        return find(root, k, s); 
    }

//  Other approach is to inorder traversal and store in vector it will sorted then perform 2 sum approach here O(n) O(n)

//  Other approach is The idea was to first in-place convert BST to Doubly Linked List (DLL), then find pair in sorted DLL in O(n) time. 
//  This solution takes O(n) time and O(Logn) extra space, but it modifies the given BST.


/*
      The idea is same as finding the pair in sorted array (See method 1 of this for details). We traverse BST in Normal Inorder and Reverse Inorder simultaneously. 
      In reverse inorder, we start from the rightmost node which is the maximum value node. In normal inorder, we start from the left most node which is minimum value node. 
      We add sum of current nodes in both traversals and compare this sum with given target sum. If the sum is same as target sum, we return true. 
      If the sum is more than target sum, we move to next node in reverse inorder traversal, otherwise we move to next node in normal inorder traversal. 
      If any of the traversals is finished without finding a pair
*/
// code
      bool isPairPresent(node* root, int target) 
{ 
    // Create two stacks. s1 is used for 
    // normal inorder traversal and s2 is 
    // used for reverse inorder traversal 
    Stack* s1 = createStack(MAX_SIZE); 
    Stack* s2 = createStack(MAX_SIZE); 
  
    // Note the sizes of stacks is MAX_SIZE, 
    // we can find the tree size and fix stack size 
    // as O(Logn) for balanced trees like AVL and Red Black 
    // tree. We have used MAX_SIZE to keep the code simple 
  
    // done1, val1 and curr1 are used for 
    // normal inorder traversal using s1 
    // done2, val2 and curr2 are used for 
    // reverse inorder traversal using s2 
    bool done1 = false, done2 = false; 
    int val1 = 0, val2 = 0; 
    node *curr1 = root, *curr2 = root; 
  
    // The loop will break when we either find a pair or one of the two 
    // traversals is complete 
    while (1) { 
        // Find next node in normal Inorder 
        // traversal. See following post 
        // https:// www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/ 
        while (done1 == false) { 
            if (curr1 != NULL) { 
                push(s1, curr1); 
                curr1 = curr1->left; 
            } 
            else { 
                if (isEmpty(s1)) 
                    done1 = 1; 
                else { 
                    curr1 = pop(s1); 
                    val1 = curr1->val; 
                    curr1 = curr1->right; 
                    done1 = 1; 
                } 
            } 
        } 
  
        // Find next node in REVERSE Inorder traversal. The only 
        // difference between above and below loop is, in below loop 
        // right subtree is traversed before left subtree 
        while (done2 == false) { 
            if (curr2 != NULL) { 
                push(s2, curr2); 
                curr2 = curr2->right; 
            } 
            else { 
                if (isEmpty(s2)) 
                    done2 = 1; 
                else { 
                    curr2 = pop(s2); 
                    val2 = curr2->val; 
                    curr2 = curr2->left; 
                    done2 = 1; 
                } 
            } 
        } 
  
        // If we find a pair, then print the pair and return. The first 
        // condition makes sure that two same values are not added 
        if ((val1 != val2) && (val1 + val2) == target) { 
            cout << "Pair Found: " << val1 << "+ " << val2 << " = " << target << endl; 
            return true; 
        } 
  
        // If sum of current values is smaller, 
        // then move to next node in 
        // normal inorder traversal 
        else if ((val1 + val2) < target) 
            done1 = false; 
  
        // If sum of current values is greater, 
        // then move to next node in 
        // reverse inorder traversal 
        else if ((val1 + val2) > target) 
            done2 = false; 
  
        // If any of the inorder traversals is 
        // over, then there is no pair 
        // so return false 
        if (val1 >= val2) 
            return false; 
    } 
} 
  
