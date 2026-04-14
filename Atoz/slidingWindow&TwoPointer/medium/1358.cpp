// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0};
        int left = 0;
        int result = 0;
        int n = s.size();

        for (int right = 0; right < n; right++) {
            count[s[right] - 'a']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                result += (n - right);
                count[s[left] - 'a']--;
                left++;
            }
        }
        return result;
    }
};