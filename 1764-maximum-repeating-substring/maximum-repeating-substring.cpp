class Solution {
public:
    int maxRepeating(string sequence, string word) {

        string temp = word;
        int count = 0;

        while (sequence.find(temp) != string::npos) {
            count++;
            temp += word;
        }

        return count;
    }
};