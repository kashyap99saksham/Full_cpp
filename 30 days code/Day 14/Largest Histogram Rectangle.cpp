// Understand this 3 4 times its very imp

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(!n) return 0;
        if(n == 1)return heights[0];
        
        stack<int> s;
        s.push(0);
        int res = 0;
        int i;
        for( i = 1; i<n; i++){
            if(s.empty() || heights[i] >= heights[s.top()])
                s.push(i);
            else{
                while(!s.empty() && heights[i] < heights[s.top()]){
                    int top = s.top();
                    s.pop();
                    res = max(res, heights[top]*(s.empty() ? i : i - s.top() - 1));
                }
                s.push(i);
            }
        }
        while(!s.empty()){
            int top = s.top();
            s.pop();
            res = max(res, heights[top]*(s.empty() ? i : i - s.top() - 1));
        }
        return res;
    }
