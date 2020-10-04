/*
Description:
     Given an array with n objects colored red, white or blue, 
     sort them in-place so that objects of the same color are adjacent,
     with the colors in the order red, white and blue.
     Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
constraints:
  1. O(n) solution with O(1) space
  
  */
  
  // code
  
      void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        
        for(int i = 0; i<n; i++){
            while(mid<=high){
                switch(nums[mid]){
                    case 0: swap(nums[low++], nums[mid++]);
                            break;
                    case 1: mid++;
                            break;
                    case 2: swap(nums[mid], nums[high--]);
                }
            }
        }
        for(int i = 0; i<n; i++)
            cout<<nums[i];
    }
    
    //other approach is to count number of 0,1 and 2 present in array and then simply print them
