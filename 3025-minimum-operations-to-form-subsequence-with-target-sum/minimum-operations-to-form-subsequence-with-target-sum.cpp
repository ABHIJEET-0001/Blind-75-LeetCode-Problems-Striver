class Solution {
public:
    int minOperations(vector<int>& nums, int target) {

        vector<long long> cnt(32, 0);
        long long sum = 0;

        for (int x : nums) {
            sum += x;
            int bit = __builtin_ctz(x); // position of set bit
            cnt[bit]++;
        }

        if (sum < target)
            return -1;

        int ans = 0;

        for (int i = 0; i < 31; i++) {

            // If target needs this bit
            if ((target >> i) & 1) {

                if (cnt[i] > 0) {
                    cnt[i]--;
                } else {

                    int j = i + 1;

                    while (j < 31 && cnt[j] == 0)
                        j++;

                    while (j > i) {
                        cnt[j]--;
                        cnt[j - 1] += 2;
                        ans++;
                        j--;
                    }

                    cnt[i]--;
                }
            }

            // Carry extra pairs upward
            cnt[i + 1] += cnt[i] / 2;
        }

        return ans;
    }
};