// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int beg = 0;
        int end = n-1;
        while (end > beg) {
            if (!isalnum(s[beg])) {
                beg++;
            } else if (!isalnum(s[end])) {
                end--;
            } else if (tolower(s[beg]) != tolower(s[end])) {
                return false;
            } else {
                beg++;
                end--;
            }
        }
        return true;
    }
};