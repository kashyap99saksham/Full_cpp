bool isValid(string s) {
        int n = s.length();
        if(!n)return true;
        stack<char> ss;
        for(char c: s){
            if(c == '(' || c == '{' || c == '[')
                ss.push(c);
            else if(ss.empty())return false;
            else if(c == ')' && ss.top() == '(' )
                ss.pop();
            else if(c == '}' && ss.top() == '{' )
                ss.pop();
            else if(c == ']' && ss.top() == '[' )
                ss.pop();
            else
                return false;
        }
        return ss.empty()?true: false;
    }
