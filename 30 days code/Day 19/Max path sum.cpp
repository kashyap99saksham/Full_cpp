/*
  Description : Given a non-empty binary tree, find the maximum path sum.
                For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
                The path must contain at least one node and does not need to go through the root.
  Example 1:
                Input: [1,2,3]

                       1
                      / \
                     2   3

                Output: 6
  Example 2:
                Input: [-10,9,20,null,null,15,7]

                   -10
                   / \
                  9  20
                    /  \
                   15   7

                Output: 42
                
*/

// Code
      int max_path(TreeNode* root, int *ans){
        if(!root)return 0;
        int L=0, R = 0;
        L = max_path(root->left, ans);
        R = max_path(root->right, ans);
        int temp = max(max(L, R) + root->val, root->val);
        int temp2 = max(temp, L+R+root->val);
        *ans = max(*ans, temp2);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        max_path(root, &ans);
        return ans;
    }
