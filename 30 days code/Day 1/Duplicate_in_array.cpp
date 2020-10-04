/*
Problem : Find the duplicate in an array of N+1 integers.
Description:  Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
              prove that at least one duplicate number must exist. 
              Assume that there is only one duplicate number, find the duplicate one.
Examples:
  1.  Input: [1,3,4,2,2]
      Output: 2
  2.  Input: [3,1,3,4,2]
      Output: 3
Constraints:
  1.  You must not modify the array (assume the array is read only).
  2.  You must use only constant, O(1) extra space.
  3.  Your runtime complexity should be less than O(n2).
  4.  There is only one duplicate number in the array, but it could be repeated more than once.
*/

//Code 

  int findDuplicate(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      for(int i = 1; i<nums.size(); i++)
          if(nums[i] == nums[i-1])
              return nums[i];
      return -1;
  }
// Sorting doesnt meet the not modifying constraint so we will use below given approach it will satisfy all constraints
//  Also revise the turtle and hare finding cycle approach this can be applied here also 
