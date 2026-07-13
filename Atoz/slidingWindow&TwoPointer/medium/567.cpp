// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();

        if (n > s2.length()) return false;

        string target = s1;
        sort(target.begin(), target.end());

        for (int i = 0; i <= s2.length() - n; i++) {
            string curr = s2.substr(i, n);
            sort(curr.begin(), curr.end());

            if (curr == target) 
                return true;
        }
        return false;
    }
};


// Optimal Solution
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if (n > m) return false;

        vector<int> need(26, 0), window(26, 0);

        for (char c : s1) {
            need[c - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            window[s2[i] - 'a']++;
        }

        if (need == window) 
            return true;
        
        for (int i = n; i < m; i++) {
            window[s2[i] - 'a']++;
            window[s2[i-n] - 'a']--;

            if (need == window)
                return true;
        }
        return false;
    }
};