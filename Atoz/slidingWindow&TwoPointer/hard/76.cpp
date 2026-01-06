// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        int required = need.size();   // number of unique chars needed
        int formed = 0;

        unordered_map<char, int> window;
        int left = 0, right = 0;

        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {
            char c = s[right];
            window[c]++;

            if (need.count(c) && window[c] == need[c])
                formed++;

            // Try shrinking window
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char lc = s[left];
                window[lc]--;
                if (need.count(lc) && window[lc] < need[lc])
                    formed--;

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
