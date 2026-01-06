// Minimum Window Subsequence

class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int minLen = INT_MAX;
        int start = -1;

        int i = 0;
        while (i < n) {
            int j = 0;

            while (i < n) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == m) break;
                }
                i++;
            }

            if (j < m) break; 

            int end = i;
            j = m - 1;
            while (i >= 0) {
                if (s1[i] == s2[j]) {
                    j--;
                    if (j < 0) break;
                }
                i--;
            }

            if (end - i + 1 < minLen) {
                minLen = end - i + 1;
                start = i;
            }

            i = i + 1;
        }

        return start == -1 ? "" : s1.substr(start, minLen);
    }
};
