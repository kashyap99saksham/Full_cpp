/*
  Description:  Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
  Follow up:    Your algorithm should run in O(n) complexity.
  Example:
          Input: [100, 4, 200, 1, 3, 2]
          Output: 4
          Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

// Code

      int longestConsecutive(vector<int>& nums) {
        set <int> mp;
        int n = nums.size();
        for(int i = 0; i<n; i++)
                mp.insert(nums[i]);
        int longest = 0;
        set <int> :: iterator it;
        for(it = mp.begin(); it!=mp.end(); it++){
            int longg = 1;
            bool find = true;
            int k = *it;
            if(mp.find(k-1) == mp.end()){
                while(find){
                    if(mp.find(k+1)!=mp.end()){
                        longg++;
                        k++;
                    }
                    else
                        find = false;
                }
                if(longg>longest)
                    longest = longg;
            }
        }
        return longest;
     }
     
/*
  There can be many approach but to make them in log(n) we have to use hash but after using hash there is one more optimization 
  after making hash set dont iterate over input array because it can contain duplicates which will just increase time. So to avoid
  Duplicate iteration iterate over Set you created this will optimize more
*/
