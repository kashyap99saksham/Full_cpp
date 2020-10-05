/*
  Description  :  Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
                  Return the length of the longest (contiguous) subarray that contains only 1s. 
  Example 1:      Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
                  Output: 6
                  Explanation: 
                  [1,1,1,0,0,1,1,1,1,1,1]
                  Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
  Example 2:      Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
                  Output: 10
                  Explanation: 
                  [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
                  Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
  Note:
                  1 <= A.length <= 20000
                  0 <= K <= A.length
                  A[i] is 0 or 1  
                  
*/

// code O(n*k) solution
     int longestOnes(vector<int>& a, int k) {
        int n = a.size();
        if(n == 0)return 0;
        // if(k>n-1)return n;
        int ans = 0, j = 0;
        for(int i = 0; j<n; i++){
            j = i;
            int temp = k;
            while(j<n && (a[j] == 1 || temp>0)){
                if(a[j] == 0)temp--;
                j++;
            }
            if(j-i > ans) ans = j-i;
            if(ans == n)return ans;
        }
        return ans;
      }
      
// Code O(n) solution using 2 pointer approach main idea is to make subarray which has at most k zeroes.

     int longestOnes(vector<int>& a, int k) {
        int n = a.size();
        int cnt0 = 0; 
        int l = 0; 
        int max_len = 0; 

        // i decides current ending point 
        for (int i = 0; i < n; i++) { 
            if (a[i] == 0) 
                cnt0++; 

            // If there are more 0's move 
            // left point for current ending 
            // point. 
            while (cnt0 > k) { 
                if (a[l] == 0) 
                    cnt0--; 
                l++; 
            } 

            max_len = max(max_len, i - l + 1); 
        } 

        return max_len; 
    }
