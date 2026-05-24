class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, INT_MAX);

        // Base case
        dp[0] = 0;

        // Build DP
        for (int i = 1; i <= amount; i++) {

            for (int coin : coins) {

                // If coin can be used
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {

                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If impossible
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};