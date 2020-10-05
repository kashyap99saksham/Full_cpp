/*
  Description:  Given an array of integers, return indices of the two numbers such that they add up to a specific target.
                You may assume that each input would have exactly one solution, and you may not use the same element twice.
  Example:  Given nums = [2, 7, 11, 15], target sum = 9,
            Because nums[0] + nums[1] = 2 + 7 = 9,
            return [0, 1].

*/
//Code
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        for(int i = 0; i<n-1; i++)
            for(int j = i+1; j<n; j++)
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
        return result;
    }
    /*
      My first thought was to sort array and make two variable 1 at begining and 1 at end but that will fail as we need to return the indexes
      and sorting will mess up indexes. so i gone for O(n2) solution.
      Other solution is to use hasmap. on iterating over array first look if its compliment exist in hashtable if it does then we have ans otherwise insert
      that number in hash table and continue.
    */

// logn approach is by using map
// code
  int getPairsCount(int arr[], int n, int sum){ 
    unordered_map<int, int> m; 
  
    // Store counts of all elements in map m 
    for (int i=0; i<n; i++) 
        m[arr[i]]++; 
  
    int twice_count = 0; 
  
    // iterate through each element and increment the 
    // count (Notice that every pair is counted twice) 
    for (int i=0; i<n; i++) 
    { 
        twice_count += m[sum-arr[i]]; 
  
        // if (arr[i], arr[i]) pair satisfies the condition, 
        // then we need to ensure that the count is 
        // decreased by one such that the (arr[i], arr[i]) 
        // pair is not considered 
        if (sum-arr[i] == arr[i]) 
            twice_count--; 
    } 
  
    // return the half of twice_count 
    return twice_count/2; 
}
