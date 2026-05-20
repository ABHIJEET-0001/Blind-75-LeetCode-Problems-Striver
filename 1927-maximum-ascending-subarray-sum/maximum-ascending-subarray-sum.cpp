class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int curSum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            // increasing condition
            if(nums[i] > nums[i-1]) {
                curSum += nums[i];
            }
            else {
                // start new subarray
                curSum = nums[i];
            }

            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};