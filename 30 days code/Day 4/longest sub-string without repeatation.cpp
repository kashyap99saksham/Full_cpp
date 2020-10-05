/*
  Description:  Given a string, find the length of the longest substring without repeating characters.
  Example 1:
        Input: "abcabcbb"
        Output: 3 
        Explanation: The answer is "abc", with the length of 3. 
  Example 2:
        Input: "bbbbb"
        Output: 1
        Explanation: The answer is "b", with the length of 1.
  Example 3:
        Input: "pwwkew"
        Output: 3
        Explanation: The answer is "wke", with the length of 3. 
  Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
  
 */
 
 // code
     int lengthOfLongestSubstring(string s) {
        int n = s.length();
        set<char> ss;
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            // try to extend the range [i, j]
            if (ss.find(s[j]) == ss.end()){
                ss.insert(s[j++]);
                ans = max(ans, j - i);
            }
            else {
                ss.erase(s[i++]);
            }
        }
        return ans;
    }
