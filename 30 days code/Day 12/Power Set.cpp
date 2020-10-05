/*
  Decription  : Given a string of length n, print all the possible subsets of the string in a lexiographically-sorted order.
  Input:        The first line of input contains an integer T denoting the number of test cases. 
                Then T test cases follow. The first line of each test case contains an integer n denoting the length of the string. 
                The second line of each test case contains the string consisting of lower-case english alphabets.
  Output:
                For each testcase, in a new line, print all the possible subsets (except the null subset) in a sorted order with a space between each subset.
  Constraints:
                1 <= T <= 100
                1 <= n <= 16
  Example:
        Input:
                1
                3
                abc
        Output:
                a ab abc ac b bc c
*/
// code

#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int set_size;
        cin>>set_size;
        string s;
        cin>>s;
        unsigned int pow_set_size = pow(2, set_size); 
        int counter, j; 
  
        vector<string> ans;
        /*Run from counter 000..0 to 111..1*/
        for(counter = 1; counter < pow_set_size; counter++){
            string str;
            for(j = 0; j < set_size; j++){ 
                /* Check if jth bit in the counter is set 
                    If set then print jth element from set */
                if(counter & (1 << j)) 
                    str+=s[j]; 
            }
            ans.push_back(str);
        // cout << endl;
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        // code
        cout<<endl;
    }
	
	return 0;
}
