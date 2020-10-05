// first approach is to use sorting and other is to use fix array or hash map

// Code
 bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m!=n)return false;
        int al[26];
        memset(al, 0, sizeof(al));
        for(int i = 0; i<m; i++)
            al[s[i]-'a']++;
        for(int i = 0; i<n; i++)
            al[t[i]-'a']--;
        for(int i = 0; i<26; i++)
            if(al[i])
                return false;
        return true;
    }
