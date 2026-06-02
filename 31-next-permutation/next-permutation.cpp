class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: find pivot
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        // If pivot does not exist, reverse whole array
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Step 2: find rightmost element greater than nums[i]
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        
        // Step 3: swap pivot and successor
        swap(nums[i], nums[j]);
        
        // Step 4: reverse suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};