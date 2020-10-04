// Repetitions not allowed

    void dfs(vector<int>& candidates, int target, int idx, set<vector<int>> &result,vector<int> &temp){
        if(target < 0)
            return;
        if(target == 0){
            result.insert(temp);
            return;
        }
        for(int i = idx; i<candidates.size(); i++){
            temp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i+1, result, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> result;
        vector<int> temp;
        dfs(candidates, target, 0, result, temp);
        vector<vector<int>> fin;
        for(auto i: result)
            fin.push_back(i);
        return fin;
    }
