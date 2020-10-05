/*
Problem: Merge two sorted array
Description:
          Merge two sorted array int O(1) extra space

Input:
      nums1 = [1,2,3,0,0,0], m = 3
      nums2 = [2,5,6],       n = 3
Output:       [1,2,2,3,5,6]

Constraints:
    -10^9 <= nums1[i], nums2[i] <= 10^9
      nums1.length == m + n
      nums2.length == n
*/

// CODE

 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x = m;
        int i = 0, j = 0;
        while(i<x && j<n){
            if(nums1[i]<nums2[j]+1)
                i++;
            else{
                int k = x-i;
                while(x > i){
                    nums1[x] = nums1[x-1];
                    x--;
                }
                x += k+1;
                nums1[i++] = nums2[j++];
            }
        }
        while(x<m+n)
            nums1[x++] = nums2[j++];
        
        for(int i = 0; i<m+n; i++)
            cout<<nums1[i];
    }
/*
  My approach is to compare element of both array and if element of array 1 is smaller or equal than simple move forward but when it is greater than 
  element of 2nd array then shift all element in array1 to 1 position right and bring smaller element from array2 to array1.
  TC = O(m*n)
  Another approach is using gap approach intially gap = m+n/2
  push all element of arr2 in last of arr1 then compare arr1[i], arr[i+gap] if former is greater than swap otherwise increase i by 1 until i+gap<n;
  then reduce gap to half and perform again eventually array will get sort
  TC =  O((n+m)*log(n+m)) 
 
 */
  
  
