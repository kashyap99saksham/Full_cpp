// Code
  int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n)return -1;
        int l = 0, r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid]>=nums[l]){
                if(nums[mid]>=target && target >=nums[l])
                    r = mid-1;
                else
                    l = mid+1;
            }
            else{
                if(target>=nums[mid] && target <= nums[r])
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        return -1;
    }
