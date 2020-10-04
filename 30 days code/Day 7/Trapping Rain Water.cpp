/*
  Description : Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
                The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
                In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
  Example:      Input: [0,1,0,2,1,0,1,3,2,1,2,1]
                Output: 6
*/
//  Code O(n2) solution.
    int trap(vector<int>& height) {
        int total = 0;
        int n = height.size();
        for(int i = 1; i<n; i++){
            int lmax = 0, rmax = 0;
            for(int j = 0; j<i; j++)
                if(height[j]>lmax) lmax = height[j];
            for(int j = i+1; j<n; j++)
                if(height[j]>rmax) rmax = height[j];
            int min_height = min(lmax, rmax);
            if(min_height - height[i] > 0)
                total += min_height - height[i];
        }
        return total;
    }
    
// Code O(n) solution using dp.
    int trap(vector<int>& height) {
        if(!height.size())return 0;
        int ans = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }

// Two pointer approach
int findWater(int arr[], int n) 
{ 
    // initialize output 
    int result = 0; 
  
    // maximum element on left and right 
    int left_max = 0, right_max = 0; 
  
    // indices to traverse the array 
    int lo = 0, hi = n - 1; 
  
    while (lo <= hi) { 
        if (arr[lo] < arr[hi]) { 
            if (arr[lo] > left_max) 
                // update max in left 
                left_max = arr[lo]; 
            else
                // water on curr element = max - curr 
                result += left_max - arr[lo]; 
            lo++; 
        } 
        else { 
            if (arr[hi] > right_max) 
                // update right maximum 
                right_max = arr[hi]; 
            else
                result += right_max - arr[hi]; 
            hi--; 
        } 
    } 
  
    return result; 
} 
    
// Approach first approach is to find max left height and max right height for every index. then water stored will be min(lmax, rmax) - h[i]
// but this will take O(n2) as we are finding lmax and rmax for every iteration so O(n2) but if we save lmax and rmax for each i. then we will have the DP approach  
