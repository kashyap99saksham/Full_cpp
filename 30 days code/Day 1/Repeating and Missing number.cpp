//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating/0

#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int missing = 0, repeating = 0;
        vector<int> vect;
        for(int i = 0; i<n; i++){
            int v;
            cin>>v;
            vect.push_back(v);
        }
        
        for(int i = 0; i<n; i++)
            if(vect[abs(vect[i])-1]<1){
                repeating = abs(vect[i]);
                // break;
            }
            else
                vect[abs(vect[i])-1]*= -1;
                
        for(int i = 0; i<n; i++)
            if(vect[i]>0)
                missing = i+1;
                
        cout<<repeating<<" "<<missing<<endl;
    
    }
	
	return 0;
}
