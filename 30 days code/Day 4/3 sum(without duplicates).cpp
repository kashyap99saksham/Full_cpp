/*
  Decription: Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
  Note      : The solution set must not contain duplicate triplets.
  Example   : Given array nums = [-1, 0, 1, 2, -1, -4],
              A solution set is:[[-1, 0, 1],[-1, -1, 2]]
*/
// Code
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        set<pair<int,int>> s;
        for(int i = 0; i<n-2; i++){
            vector<int> v;
            int low = i+1; 
            int high = n-1;
            while(low<high){
                if(nums[low] + nums[high] == -1*nums[i] && s.find(make_pair(nums[i], nums[low])) == s.end()){
                    v.push_back(nums[i]);
                    v.push_back(nums[low]);
                    v.push_back(nums[high]);
                    s.insert(make_pair(nums[i], nums[low]));
                    // break;
                    low++;
                    high--;
                    if(v.size()!=0)
                        result.push_back(v);
                    v.clear();
                }
                else if(nums[low] + nums[high] > -1*nums[i])
                    high--;
                else
                    low++;   
            }       
        }
        return result;
    }
    
/*
  To get rid of duplicates we store pairs of each solution in set and check them for duplicacy
*/
