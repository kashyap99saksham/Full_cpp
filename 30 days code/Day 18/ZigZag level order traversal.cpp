/*
  Description : Given a binary tree, return the zigzag level order traversal of its nodes' values. 
                (ie, from left to right, then right to left for the next level and alternate between).
  For example:
                Given binary tree [3,9,20,null,null,15,7],
                    3
                   / \
                  9  20
                    /  \
                   15   7
                return its zigzag level order traversal as:
                [[3],[20,9],[15,7]]
                
*/

// Code
      vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            for(int i = 0; i<n; i++){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
                // if(flag){
                //     if(t->right)q.push(t->right);
                //     if(t->left)q.push(t->left);
                //     // flag = false;
                // }else{
                //     if(t->left)q.push(t->left);
                //     if(t->right)q.push(t->right);
                //     // flag = true;
                // }
            }
            if(!flag)reverse(temp.begin(), temp.end());
            flag = !flag;
            res.push_back(temp);
        }
        return res;
    }
    
// Other approach if you dont want to use reverse start filling temp array from back if normal then normally otherwise start filling from back
