#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        if(m == 0 || m == 1){
            cout<<m<<endl;
            continue;
        }
        int l = 1, r = m/2;
        int res = 0;
        while(l<=r){
            int mid = (l+r)/2;
            if(pow(mid, n) == m){
                res = mid;
                break;
            }
            else if(pow(mid, n)<m){
                l = mid+1;
            }
            else
                r = mid-1;
        }
        if(res)cout<<res;
        else
            cout<<-1;
            cout<<endl;
    }
	
	return 0;
}
