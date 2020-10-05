/*
  Description : Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.
  Input:        The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. 
                First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.
  Output:       Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.
  Constraints:
                1 <= T <= 100
                1 <= N <= 100
                0 <= arr[i] <= 1000
  Example:
        Input:
                2
                4
                1 5 11 5
                3
                1 3 5 
        Output:
                YES
                NO

  Explanation:
       Testcase 1: There exists two subsets such that {1, 5, 5} and {11}.
*/

// here is backtracking solution to it.
#include<bits/stdc++.h>
using namespace std;
void subset(vector<int> nums, int sum,int idx, bool* flag){
    if(sum<0)
        return;
    if(sum == 0){
        *flag = true;
        return ;
    }
    // cout<<sum<<" ";
    for(int i = idx; i<nums.size(); i++){
        subset(nums, sum - nums[i], i+1, flag);
        if(*flag)break;
    }
}
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums;
        for(int i = 0; i<n; i++){
            int v;
            cin>>v;
            nums.push_back(v);
        }
        int sum = 0;
        for(int i = 0; i<n; i++)
            sum += nums[i];
        if(sum%2 != 0){
            cout<<"NO"<<endl;
        }
        else{
            // cout<<sum;
            sum = sum/2;
            sort(nums.begin(), nums.end());
            bool flag = false;
            subset(nums, sum, 0, &flag);
            if(flag)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        // code
    }
	
	return 0;
}
