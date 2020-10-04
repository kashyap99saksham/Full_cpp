/*
  Description : Given an input string, reverse the string word by word.
  Example 1:    Input: "the sky is blue"
                Output: "blue is sky the"
  Example 2:    Input: "  hello world!  "
                Output: "world! hello"
                Explanation: Your reversed string should not contain leading or trailing spaces.
  Example 3:    Input: "a good   example"
                Output: "example good a"
                Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
  Note:
                A word is defined as a sequence of non-space characters.
                Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
                You need to reduce multiple spaces between two words to a single space in the reversed string.
  Follow up:
                For C programmers, try to solve it in-place in O(1) extra space.
                
*/

// Approach with O(number of words) space and O(n) time

    string reverseWords(string s) {
        int n = s.length();
        string str;
        if(!n) return "";
        vector<string> res;
        for(int i = 0; i<n; i++){
            if(s[i] == ' '){
                if(str.length()){
                    res.push_back(str);
                    str.clear();
                }
            } else{
                str += s[i];
            }
        }
        if(str.length())
            res.push_back(str);
        string ans;
        for(int i = res.size()-1; i>-1; i--){
            ans += res[i];
            ans += ' ';
        }
        return ans.substr(0, ans.length()-1);
    }
    
// Another O(1) space is 
//  Initially, reverse the individual words of the given string one by one, for the above example,
//  after reversing individual words the string should be “i ekil siht margorp yrev hcum”.
//  Reverse the whole string from start to end to get the desired output “much very program this like i” in the above example.
