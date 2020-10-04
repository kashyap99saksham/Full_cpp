/*
Problem Description: Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Examples:
      Input: [-2,1,-3,4,-1,2,1,-5,4],
      Output: 6
      Explanation: [4,-1,2,1] has the largest sum = 6.
Next Task:
  If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/  
// Code

    int maxSubArray(vector<int>& nums) {
        int low = 0, high = 0, max_sum = INT_MIN;
        int n = nums.size();
        int sum = 0;
        while(high < n){
            sum += nums[high];
            if(sum > max_sum)
                max_sum = sum;
            if(sum<1){
                sum = 0;
                low = ++high;
            }
            else
                high++;
        }
        return max_sum;
    }
    
    
