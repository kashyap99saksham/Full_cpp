/*
  Description : Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
                find all unique combinations in candidates where the candidate numbers sums to target.
                The same repeated number may be chosen from candidates unlimited number of times.
  Note:         All numbers (including target) will be positive integers.
                The solution set must not contain duplicate combinations.
  Example 1:
                Input: candidates = [2,3,6,7], target = 7,
                A solution set is:[[7],[2,2,3]]
  Example 2:
                Input: candidates = [2,3,5], target = 8,
                A solution set is:[[2,2,2,2],[2,3,3],[3,5]]
  Constraints:
                1 <= candidates.length <= 30
                1 <= candidates[i] <= 200
                Each element of candidate is unique.
                1 <= target <= 500
*/

// Approach is to use backtracking because its asking for "all possible" solution.
// Backtracking is all about applying DFS and saving when condition is satisfied

// Code 
    void dfs(vector<int>& candidates, int target, int idx, vector<vector<int>> &result,         vector<int> &temp){
        if(target<0)return;
        if(target == 0){
            result.push_back(temp);
            return;
        }
        for(int i = idx; i<candidates.size(); i++){
            temp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, result, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        dfs(candidates, target, 0, result, temp);
        return result;
    }
