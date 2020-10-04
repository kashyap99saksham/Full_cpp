/*
  Description : Given a circular array (the next element of the last element is the first element of the array), 
                print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, 
                which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.
  Example 1:
    Input:      [1,2,1]
    Output:     [2,-1,2]
    Explanation:The first 1's next greater number is 2; 
                The number 2 can't find next greater number; 
                The second 1's next greater number needs to search circularly, which is also 2.
    Note:       The length of given array won't exceed 10000.
*/
// Approach 1st approach is copy array and append it to its last O(n2) and space O(n)
// Approach 2 is to dont copy but iterate twice using mod operator i = 2*n-1 to 0 using i%length
// Approach 3 is stack below implemented
 
// Code
     vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        stack<int> s;
        for(int i = 2*n-1; i>-1; i--){
            while(!s.empty() && nums[s.top()] <= nums[i%n])
                s.pop();
            res[i%n] = s.empty()?-1:nums[s.top()];
            s.push(i%n);
        }
        return res;
    }
