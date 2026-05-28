class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target,
               vector<int>& path, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(path);
            return;
        }

        if (target < 0) return;

        for (int i = idx; i < candidates.size(); i++) {
            path.push_back(candidates[i]);

            // i again, because same element can be reused
            solve(i, candidates, target - candidates[i], path, ans);

            path.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(0, candidates, target, path, ans);
        return ans;
    }
};