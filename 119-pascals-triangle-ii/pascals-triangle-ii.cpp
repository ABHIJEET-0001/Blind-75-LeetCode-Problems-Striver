class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;

        long long val = 1;
        row.push_back(1);

        for (int i = 1; i <= rowIndex; i++) {
            val = val * (rowIndex - i + 1) / i;
            row.push_back(val);
        }

        return row;
    }
};