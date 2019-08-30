//HERE WE ARE USING A 2D DYNAMIC ARRAY.
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
    int x,q,s;
    cin>>x>>q;
//NORMAL 1D ARRAY IS MADE LIKE *P = NEW INT[X] BUT IN THIS CASE **A = NEW INT *[X] MEANS, A IS DOUBLE POINTER WHICH POINTS TO THAT POINTER WHO POINTS A 1D ARRAY 
	int **a = new int*[x];  
    for (int i = 0; i < x; i++){
		cin>>s;
        a[i] = new int[s];    //HERE IS THAT POINTER WHICH POINTS 1D ARRAY
		for (int j = 0; j < s; j++)
			cin>>a[i][j];	 
    }
    for(int i=0;i<q;i++){
		int s,k;
        cin>>s>>k;
        cout<<a[s][k]<<endl;
    }
    return 0;
}
