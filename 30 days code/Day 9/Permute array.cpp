/*
  Description : Given a collection of distinct integers, return all possible permutations.
  Example   :   Input: [1,2,3]
                Output:[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
// code

  vector<vector<int>> v;
    void permuteUtil(vector<int> num, int l, int r){
        if(l == r){
            v.push_back(num);
            return;
        }
        for(int i = l; i<=r; i++){
            swap(num[l], num[i]);
            permuteUtil(num, l+1, r);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        permuteUtil(nums, 0, n-1);
        return v;
    }
};
