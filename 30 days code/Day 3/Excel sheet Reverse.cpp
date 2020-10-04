/*
Problem : It is reverse of Excel sheet problem.
Description:
        Given a positive integer N, print its corresponding column title as it would appear in an Excel sheet.
        For N =1 we have column A, for 27 we have AA and so on.
Example:
        Input:
        1 
        51
        Output:
        AY
*/

// Code

#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        bool flag = false;
        while(n>26){
            if(n%26 == 0){
                s.push_back('Z');
                flag = true;
            }
            else
                s.push_back(char('A' + (n%26) - 1));
            n/=26;
        }
        if(n%26 == 0)s.push_back('Z');
        else if(flag)s.push_back(char('A' + n%26 -2));
        else
            s.push_back(char('A' + (n%26) - 1));
        
        for(int i = s.length()-1;i>-1; i--)
            cout<<s[i];
        cout<<endl;
    }
	
	return 0;
}
