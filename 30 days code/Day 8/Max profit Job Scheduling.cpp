/*
  Description : We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
                You're given the startTime , endTime and profit arrays, 
                you need to output the maximum profit you can take such that there are no 2 jobs in the subset with overlapping time range.
                If you choose a job that ends at time X you will be able to start another job that starts at time X.
  Example 1 :
        Input:  startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
        Output: 120
        Explanation: The subset chosen is the first and fourth job. 
        Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
  Example 2 :
        Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
        Output: 150
        Explanation: The subset chosen is the first, fourth and fifth job. 
        Profit obtained 150 = 20 + 70 + 60.
  Example 3 :
        Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
        Output: 6
  Constraints:
                1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
                1 <= startTime[i] < endTime[i] <= 10^9
                1 <= profit[i] <= 10^4
*/

// Code also try job scheduling approach where you keep track of free slots

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n= startTime.size(),i=0,ans=0;
        vector< pair<int,int> >v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({startTime[i],i});
        }
        sort(v.begin(),v.end());
        vector<int> dp(n,0);
        
        for(i=n-1;i>=0;i--)
        {
            int f= v[i].first;
            int ii=v[i].second;
            int val=0;
            
            val+=profit[ii];
            
            int x= endTime[ii];
            
            auto it= lower_bound(v.begin(),v.end(),x,[](const pair<int,int> &p, const int &value){
                return p.first<value;
            });       //searching for next Starttime which is greater than the current endtime
            
            if(it!=v.end())
            {
                int j=it-v.begin();
                
                val+=dp[j];
            }
            
            if(i==n-1)
            dp[i]=max(dp[i],val);
            
            else
            {
                dp[i]=max(dp[i],max(val, dp[i+1]));//either take the ith job or skip it and take the next one
            }
            
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
