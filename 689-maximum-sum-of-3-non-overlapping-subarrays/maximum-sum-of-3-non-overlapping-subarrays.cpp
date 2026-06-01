#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: compute sum of every subarray of length k
        vector<int> window;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (i >= k) sum -= nums[i - k];
            if (i >= k - 1) window.push_back(sum);
        }
        
        int m = window.size(); // number of k-length subarrays
        
        // Step 2: left[i] = best starting index from 0 to i
        vector<int> left(m, 0);
        int best = 0;
        for (int i = 0; i < m; i++) {
            if (window[i] > window[best]) {
                best = i;
            }
            // if equal, keep smaller index -> do nothing
            left[i] = best;
        }
        
        // Step 3: right[i] = best starting index from i to m-1
        vector<int> right(m, 0);
        best = m - 1;
        for (int i = m - 1; i >= 0; i--) {
            if (window[i] >= window[best]) {
                best = i;
            }
            // >= gives lexicographically smaller index on tie
            right[i] = best;
        }
        
        // Step 4: try every middle subarray
        vector<int> ans(3, -1);
        int maxSum = 0;
        
        // middle must leave space for left and right
        // left ends before middle starts
        // right starts after middle ends
        for (int mid = k; mid < m - k; mid++) {
            int l = left[mid - k];
            int r = right[mid + k];
            
            int total = window[l] + window[mid] + window[r];
            
            if (total > maxSum) {
                maxSum = total;
                ans = {l, mid, r};
            }
            // if equal, do nothing because we scan mid from left to right,
            // and left/right arrays already ensure lexicographical order
        }
        
        return ans;
    }
};