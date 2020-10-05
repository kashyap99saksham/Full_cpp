/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

// CODE

void reverse(vector<int>& nums, int start){
    int size = nums.size()-1;
    // int i = start;
    while(start<size){
        swap(nums[start], nums[size]);
        start++; size--;
    }
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while(i>-1 && nums[i]>nums[i+1]-1)
            i--;
        if(i>-1){
            int j = nums.size()-1;
            while(j>-1 && nums[i]>nums[j]-1)
                j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums, i+1);
        for(int i = 0; i<nums.size(); i++)
            cout<<nums[i];
    }
};

/*
  Approach is to find first number from right that is not in increasing order (num1). now find 1st number just greater than num1 (also from right) (lets call it num2)
  now swap num1 and num2 and then reverse all number after num1.
*/
