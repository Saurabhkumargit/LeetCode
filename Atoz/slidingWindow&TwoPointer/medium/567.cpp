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