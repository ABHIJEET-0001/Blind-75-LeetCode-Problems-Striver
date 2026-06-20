class Solution {
public:
    
    int solve(int idx, vector<int>& nums, int currXor)
    {
        if(idx == nums.size())
            return currXor;

        int take =
            solve(idx + 1, nums, currXor ^ nums[idx]);

        int notTake =
            solve(idx + 1, nums, currXor);

        return take + notTake;
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(0, nums, 0);
    }
};