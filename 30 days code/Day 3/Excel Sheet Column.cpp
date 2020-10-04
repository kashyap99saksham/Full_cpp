/*
  Description:
      Given a column title as appear in an Excel sheet, return its corresponding column number.
  For example:
          A -> 1
          B -> 2
          C -> 3
          ...
          Z -> 26
          AA -> 27
          AB -> 28 
          ...
  Example 1:
          Input: "A"
          Output: 1
  Example 2:
          Input: "AB"
          Output: 28
  Example 3:
          Input: "ZY"
          Output: 701
Constraints:
      1 <= s.length <= 7
      s consists only of uppercase English letters.
      s is between "A" and "FXSHRXW".
*/

// CODE

    int titleToNumber(string s) {
        int n = s.length();
        int i = n-1;
        int num = 0;
        while(i>-1){
            num += (s[i] - 'A' + 1) * pow(26, n-i-1);
            i--;
        }
        
        return num;
    }
