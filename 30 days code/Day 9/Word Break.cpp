/*
  Description : Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
                determine if s can be segmented into a space-separated sequence of one or more dictionary words.
  Note        : The same word in the dictionary may be reused multiple times in the segmentation.
                You may assume the dictionary does not contain duplicate words.
  Example 1:
              Input: s = "leetcode", wordDict = ["leet", "code"]
              Output: true
              Explanation: Return true because "leetcode" can be segmented as "leet code".
  Example 2:
              Input: s = "applepenapple", wordDict = ["apple", "pen"]
              Output: true
              Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
                           Note that you are allowed to reuse a dictionary word.
  Example 3:
              Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
              Output: false
*/
// Backtracking code
  bool solve(string str, int n, set<string> wordDict){
    cout<<"here";
    for(int i = 1; i<= n; i++){
        string prefix = str.substr(0,i);
        if(find(wordDict.begin(), wordDict.end(), prefix) != wordDict.end()){
            if(i == n)return true;
            if(solve(str.substr(i, n-i), n-i, wordDict))
                return true;
        }
    }
    return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    set<string> se;
    for(int i = 0; i<wordDict.size();i++)
    se.insert(wordDict[i]);
    return solve(s, s.length(), se);
}

// DP code
  class Solution {
	bool isPresent(vector<string> &dict, string word)
		{
			for( string w : dict )
			{
				if( word == w )
				{
					return true;
				}
			}

			return false;
		}
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    	int n = s.length();
    	vector dp(n+1,false);
    	dp[0] = true;		// empty string is always present in dictionary

    	for( int i = 1 ; i <= n ; i++ )
    	{
    		for( int j = i-1 ; j >= 0 ; j-- )
    		{
    			if( dp[j] == true )
    			{
    				string word = s.substr(j,i-j);
    				if( isPresent(wordDict, word) )
    				{
    					dp[i] = true;
    					break;
    				}
    			}
    		}
    	}
    	
    	return dp[n];
    }
};

/* 
  First approach is use backtacking iterate over string and whenever we found any solution then iterate over more
  another is use dp 
*/
