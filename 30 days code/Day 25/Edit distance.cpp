/*
  Description : Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
                You have the following 3 operations permitted on a word:
                Insert a character
                Delete a character
                Replace a character
  Example 1:
                Input: word1 = "horse", word2 = "ros"
                Output: 3
                Explanation: 
                horse -> rorse (replace 'h' with 'r')
                rorse -> rose (remove 'r')
                rose -> ros (remove 'e')
  Example 2:
                Input: word1 = "intention", word2 = "execution"
                Output: 5
                Explanation: 
                intention -> inention (remove 't')
                inention -> enention (replace 'i' with 'e')
                enention -> exention (replace 'n' with 'x')
                exention -> exection (replace 'n' with 'c')
                exection -> execution (insert 'u')
*/
// recursive code
      int dp(string s1, string s2, int m, int n){
        if(m == 0)
            return n;
        if(n == 0)
            return m;
        if(s1[m-1] == s2[n-1])
            return dp(s1, s2, m-1, n-1);
        else
            return 1 + min(min(dp(s1, s2, m, n-1),
                            dp(s1, s2, m-1, n)),
                            dp(s1, s2, m-1, n-1));
    }
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        return dp(word1, word2, m, n);
    }
};
// memoize solution 
    int dp(string s1, string s2, int m, int n, vector<vector<int>> &dpa){
        if(dpa[m][n])
            return dpa[m][n];
        if(m == 0)
            return dpa[m][n] = n;
        if(n == 0)
            return dpa[m][n] = m;
        if(s1[m-1] == s2[n-1])
            return dpa[m][n] = dp(s1, s2, m-1, n-1, dpa);
        else
            return dpa[m][n] = 1 + min(min(dp(s1, s2, m, n-1, dpa),
                            dp(s1, s2, m-1, n, dpa)),
                            dp(s1, s2, m-1, n-1, dpa));
    }
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dpa(m+1, vector<int> (n+1, 0));
        return dp(word1, word2, m, n, dpa);
    }
    
// DP approach
      int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dpa(m+1, vector<int> (n+1, 0));
        for(int i = 0; i<=m; i++){
            for(int j = 0; j<=n; j++){
                if(i == 0)
                    dpa[i][j] = j;
                else if(j == 0)
                    dpa[i][j] = i;
                else if(word1[i-1] == word2[j-1])
                    dpa[i][j] = dpa[i-1][j-1];
                else
                    dpa[i][j] = 1 + min(min(dpa[i][j-1], dpa[i-1][j]), dpa[i-1][j-1]);
            }
        }
        return dpa[m][n];
    }
// space complexity can be reduces by taking only 2 rows
