// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
int dup[MAX][MAX];

vector<string> vect;
void solve(int m[MAX][MAX], int n, int x, int y, string s){
    if(x == n-1 && y == n-1)
        vect.push_back(s);
    // Down move
    if(m[x+1][y] == 1 && dup[x+1][y] == 0 && x<n-1){
        dup[x+1][y] = 1;
        s.push_back('D');
        solve(m, n, x+1, y, s);
        dup[x+1][y] = 0;
        s.pop_back();
    }
    // left
    if(m[x][y-1] == 1 && dup[x][y-1] == 0 && y>0){
        dup[x][y-1] = 1;
        s.push_back('L');
        solve(m, n, x, y-1, s);
        dup[x][y-1] = 0;
        s.pop_back();
    }
    // Right move
    if(m[x][y+1] == 1 && dup[x][y+1] == 0 && y<n-1){
        dup[x][y+1] = 1;
        s.push_back('R');
        solve(m, n, x, y+1, s);
        s.pop_back();
        dup[x][y+1] = 0;
    }
    // Up
    if(m[x-1][y] == 1 && dup[x-1][y] == 0 && x>0){
        dup[x-1][y] = 1;
        s.push_back('U');
        solve(m, n, x-1, y, s);
        dup[x-1][y] = 0;
        s.pop_back();
    }
}

vector<string> printPath(int m[MAX][MAX], int n) {
    
    memset(dup, 0, sizeof(dup));
    vect.clear();
    if(m[0][0] == 0)return vect;
    dup[0][0] = 1;
    string s;
    solve(m, n, 0, 0, s);
    return vect;
    // Your code goes here
}
