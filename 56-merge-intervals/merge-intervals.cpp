class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Step 1: sort intervals
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // First interval add karo
        ans.push_back(intervals[0]);

        // Step 2: traverse
        for(int i = 1; i < intervals.size(); i++) {

            // last interval from answer
            vector<int>& last = ans.back();

            // overlap check
            if(intervals[i][0] <= last[1]) {

                // merge
                last[1] = max(last[1], intervals[i][1]);
            }
            else {

                // no overlap
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};