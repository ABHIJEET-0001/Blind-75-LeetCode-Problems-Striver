class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;

        // Step 1: sort by end time
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1;              // first interval keep kar liya
        int lastEnd = intervals[0][1];

        // Step 2: check बाकी intervals
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < lastEnd) {
                // overlap hai, remove kar do
                continue;
            } else {
                // no overlap, keep it
                count++;
                lastEnd = intervals[i][1];
            }
        }

        return intervals.size() - count;
    }
};