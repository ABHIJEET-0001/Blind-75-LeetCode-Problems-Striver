class Solution {
public:
    long long climbStairs(int n, vector<int>& costs) {

        // dp[i] = minimum cost to reach step i
        vector<long long> dp(n + 1, LLONG_MAX);

        // Starting point
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {

            // Jump from i-1
            if (i - 1 >= 0) {
                dp[i] = min(dp[i],
                            dp[i - 1] + costs[i - 1] + 1LL);
            }

            // Jump from i-2
            if (i - 2 >= 0) {
                dp[i] = min(dp[i],
                            dp[i - 2] + costs[i - 1] + 4LL);
            }

            // Jump from i-3
            if (i - 3 >= 0) {
                dp[i] = min(dp[i],
                            dp[i - 3] + costs[i - 1] + 9LL);
            }
        }

        return dp[n];
    }
};