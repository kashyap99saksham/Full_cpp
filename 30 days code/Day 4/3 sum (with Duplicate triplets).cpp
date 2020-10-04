     vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // vector<int> :: iterator it;
        // it = unique(nums.begin(), nums.end()); 
        // nums.resize(distance(nums.begin(), it));
        // n = nums.size();
        vector<vector<int>> result;
        for(int i = 0; i<n-2; i++){
            vector<int> v;
            int low = i+1; 
            int high = n-1;
            while(low<high){
                if(nums[low] + nums[high] == -1*nums[i]){
                    v.push_back(nums[i]);
                    v.push_back(nums[low]);
                    v.push_back(nums[high]);
                    break;
                }
                else if(nums[low] + nums[high] > -1*nums[i])
                    high--;
                else
                    low++;
            }
            if(v.size()!=0)
                result.push_back(v);
        }
        return result;
    }
