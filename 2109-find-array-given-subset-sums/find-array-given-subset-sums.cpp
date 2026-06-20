class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {

        if (n == 0)
            return {};

        sort(sums.begin(), sums.end());

        int x = sums[1] - sums[0];

        unordered_map<int, int> freq;

        for (int s : sums)
            freq[s]++;

        vector<int> left, right;

        for (int s : sums) {
            if (freq[s] == 0)
                continue;

            left.push_back(s);
            right.push_back(s + x);

            freq[s]--;
            freq[s + x]--;
        }

        bool zeroInLeft = false;

        for (int num : left) {
            if (num == 0) {
                zeroInLeft = true;
                break;
            }
        }

        vector<int> ans;

        if (zeroInLeft) {
            ans = recoverArray(n - 1, left);
            ans.push_back(x);
        } else {
            ans = recoverArray(n - 1, right);
            ans.push_back(-x);
        }

        return ans;
    }
};