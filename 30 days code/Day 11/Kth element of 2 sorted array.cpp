// Code
  #include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int m, n, k;
        cin>>m>>n>>k;
        vector<int> num1;
        for(int i = 0; i<m; i++){
            int v;
            cin>>v;
            num1.push_back(v);
        }
        vector<int> num2;
        for(int i = 0; i<n; i++){
            int v;
            cin>>v;
            num2.push_back(v);
        }
        int i = 0, j = 0;
        int count = 0;
        bool flag = false;
        while(i<m && j<n){
            // cout<<count<<"-"<<min(num1[i], num2[j])<<" ";
            if(count == k-1){
                cout<<min(num1[i], num2[j])<<endl;
                flag = true;
                break;
            }
            if(num1[i]<=num2[j]){
                i++;
                count++;
            }
            else{
                j++;
                count++;
            }
        }
        if(i<m && !flag)cout<<num1[i+k-count-1]<<endl;
        if(j<n && !flag)cout<<num2[j+k-count-1]<<endl;
        // code
    }
	
	return 0;
}

// above approach is O(n)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int helper(int A[],int B[],int n,int m,int k)
{
    if(n==0)return B[k];
    
    if(m==0)return A[k];
    
    int mid1=n/2;
    int mid2=m/2;    
    
    if(mid1+mid2<k)
    {
        if(A[mid1]<B[mid2])
        return helper(A+mid1+1,B,n-mid1-1,m,k-mid1-1);
        else
        return helper(A,B+mid2+1,n,m-mid2-1,k-mid2-1);
    }
    else
    {
        if(A[mid1]<B[mid2])
        {
            return helper(A,B,n,mid2,k);
        }
        else
        return helper(A,B,mid1,m,k);
    }
    
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m,k;
	    cin>>n>>m>>k;
	    int A[n];
	    int B[m];
	    
	    for(int i=0;i<n;i++)
	    cin>>A[i];
	    for(int i=0;i<m;i++)
	    cin>>B[i];
	    
	    cout<<helper(A,B,n,m,k-1)<<endl;
	}
	return 0;
}

// This is (logn) approach
