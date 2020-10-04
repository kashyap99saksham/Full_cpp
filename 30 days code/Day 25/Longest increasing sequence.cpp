// recursive code O(2n) O(n2)
    int lis(vector<int> nums, int prev, int curr){
        if(curr == nums.size())
            return 0;
        int taken = 0;
        if(nums[curr] > prev)
            taken = lis(nums, nums[curr], curr+1) + 1;
        int nottaken = lis(nums, prev, curr+1);
        return max(taken, nottaken);
    }
    int lengthOfLIS(vector<int>& nums) {
        return lis(nums, INT_MIN, 0);
    }
    
// if we want to memoize above then we have to use prevIndex instead of direct prev so we can memoize this way O(n2) O(n2)
// DP approach O(n2) O(n)
      int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int res = 1;
        for(int i = 1; i<nums.size(); i++){
            int v = 0;
            for(int j = 0; j<i; j++)
                if(nums[i]>nums[j])
                    v = max(v, dp[j]);
            dp[i] = v+1;
            res = max(res, dp[i]);
        }
        return res;
    }
    
// DP with binary search
      int lengthOfLIS(vector<int>& nums) {
        // vector<int> dp(nums.size(), 0);
        vector<int> lis;
        for(const int& num: nums) {
            // find the first number greater than current in LIS
            auto it = lower_bound(lis.begin(), lis.end(), num);
            
            // if no such number is found, we can add the current
            if(it == lis.end()) {
                lis.emplace_back(num);
            }
            // if a number greater exists, then replace it with current, this is
            // because putting the smaller number in place of a bigger number will allow
            // more numbers greater than current to be part of LIS
            else if(*it > num)
                *it = num;
        }
        return lis.size();
    }
    
