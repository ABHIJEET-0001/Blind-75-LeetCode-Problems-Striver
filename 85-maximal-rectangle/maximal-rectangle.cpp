class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int curr = (i == n) ? 0 : heights[i];

            while (!st.empty() && curr < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();
                int width = right - left - 1;

                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};