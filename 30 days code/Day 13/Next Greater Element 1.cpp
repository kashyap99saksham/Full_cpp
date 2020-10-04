/*
  Description : You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. 
                Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
                The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.
  Example 1:
    Input:      nums1 = [4,1,2], nums2 = [1,3,4,2].
    Output:     [-1,3,-1]
    Explanation:
                For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
                For number 1 in the first array, the next greater number for it in the second array is 3.
                For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
  Example 2:
    Input:      nums1 = [2,4], nums2 = [1,2,3,4].
    Output:     [3,-1]
    Explanation:
                For number 2 in the first array, the next greater number for it in the second array is 3.
                For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
    Note:
                All elements in nums1 and nums2 are unique.
                The length of both nums1 and nums2 would not exceed 1000.
*/

// Simple approach is using loop O(n3) Another is using stack and map . You can use two stacks also but in that you have to keep switching stack repeatedly
//  Code
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int> s;
        unordered_map<int, int> mp;
        if(n2 != 0)
            s.push(nums2[0]);
        for(int i = 1; i<n2; i++){
            if(s.empty())
                s.push(nums2[i]);
            while(!s.empty() && s.top()<nums2[i]){
                mp.insert({s.top(), nums2[i]});
                s.pop();
            }
            s.push(nums2[i]);
        }
        while(!s.empty()){
            mp.insert({s.top(), -1});
            s.pop();
        }
        vector<int> res;
        for(int i = 0; i<n1; i++){
            if(mp.find(nums1[i]) != mp.end())
                res.push_back(mp[nums1[i]]);
            else
                res.push_back(-1);
        }
        return res;
    }
