class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> need(128, 0);

        // Store frequency of characters in t
        for(char c : t)
            need[c]++;

        int left = 0;
        int right = 0;

        int count = t.size();

        int minLen = INT_MAX;
        int start = 0;

        while(right < s.size()) {

            // If current character is needed
            if(need[s[right]] > 0)
                count--;

            // Include current character in window
            need[s[right]]--;

            // Window contains all characters
            while(count == 0) {

                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                need[s[left]]++;

                // If removed character was required
                if(need[s[left]] > 0)
                    count++;

                left++;
            }

            right++;
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};