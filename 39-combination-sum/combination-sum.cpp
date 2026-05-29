class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& current, vector<vector<int>>& result) {
        
        // Base case 1: exact match found
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Try every number from 'start' onward
        for (int i = start; i < candidates.size(); i++) {
            // If current number is bigger than remaining target, skip it
            if (candidates[i] > target) {
                continue;
            }

            // Choose the number
            current.push_back(candidates[i]);

            // Recurse:
            // i is passed again because the same number can be used unlimited times
            backtrack(candidates, target - candidates[i], i, current, result);

            // Undo the choice (backtracking step)
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};