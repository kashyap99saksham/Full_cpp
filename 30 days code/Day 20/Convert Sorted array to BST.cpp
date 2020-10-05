// recursive approach
      TreeNode* make_tree(vector<int> &nums, int start, int end){
        if(start>end)return NULL;
        if(start == end) return new TreeNode(nums[(start+end)/2]);
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = make_tree(nums,start, mid-1);
        root->right = make_tree(nums,mid+1, end);
        return root;        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(!n)return NULL;
        if(nums.size() == 1)return new TreeNode(nums[0]);
        return make_tree(nums, 0, n-1);
    }
