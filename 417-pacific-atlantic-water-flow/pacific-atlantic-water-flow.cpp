class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& vis) {
        int m = heights.size();
        int n = heights[0].size();
        vis[r][c] = true;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
               !vis[nr][nc] &&
               heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        if(m == 0) return {};
        int n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        // Pacific: top row and left column
        for(int i = 0; i < m; i++) {
            dfs(i, 0, heights, pac);
        }
        for(int j = 0; j < n; j++) {
            dfs(0, j, heights, pac);
        }

        // Atlantic: bottom row and right column
        for(int i = 0; i < m; i++) {
            dfs(i, n - 1, heights, atl);
        }
        for(int j = 0; j < n; j++) {
            dfs(m - 1, j, heights, atl);
        }

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};