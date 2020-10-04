/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/


// Code

  class Solution {
public:
    vector<vector<int>> v;
    void permuteUtil(vector<int> num, int l, int r){
        if(l == r){
            v.push_back(num);
            return;
        }
        for(int i = l; i<=r; i++){
            swap(num[l], num[i]);
            permuteUtil(num, l+1, r);
        }
    }
    string getPermutation(int n, int k) {
        // int n = nums.size();
        vector<int> nums;
        for(int i = 0; i<n; i++)
            nums.push_back(i+1);
        vector<vector<int>> ans;
        permuteUtil(nums, 0, n-1);
        std::stringstream result;
std::copy(v[k-1].begin(), v[k-1].end(), std::ostream_iterator<int>(result, ""));
        string res;
        result>>res;
        return res;
    }
};
