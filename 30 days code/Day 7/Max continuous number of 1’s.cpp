    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, temp = 0;
        for(int i = 0; i<n ; i++){
            if(nums[i]){
                temp++;
                if(temp>ans)ans = temp;
            }
            else{
                temp = 0;
            }
        }
        return ans;
    }
