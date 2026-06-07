class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void solve(int start, vector<int>& nums) {
        ans.push_back(subset);

        for(int i = start; i < nums.size(); i++) {

            // Skip duplicates
            if(i > start && nums[i] == nums[i - 1])
                continue;

            subset.push_back(nums[i]);

            solve(i + 1, nums);

            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        solve(0, nums);

        return ans;
    }
};
