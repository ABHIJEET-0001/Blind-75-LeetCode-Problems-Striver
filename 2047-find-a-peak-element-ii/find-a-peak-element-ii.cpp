class Solution {
public:
    
    int findMaxRow(vector<vector<int>>& mat, int col) {
        int row = 0;

        for (int i = 0; i < mat.size(); i++) {
            if (mat[i][col] > mat[row][col]) {
                row = i;
            }
        }

        return row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int row = findMaxRow(mat, mid);

            int left =
                (mid - 1 >= 0) ? mat[row][mid - 1] : -1;

            int right =
                (mid + 1 < n) ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left &&
                mat[row][mid] > right) {

                return {row, mid};
            }
            else if (right > mat[row][mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return {-1, -1};
    }
};