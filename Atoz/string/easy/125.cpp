// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int end = s.length() - 1;

        while (st <= end) {
            if (!isalnum(static_cast<unsigned char>(s[st]))) {
                st++;
                continue;
            }
            if (!isalnum(static_cast<unsigned char>(s[end]))) {
                end--;
                continue;
            }

            if (tolower(static_cast<unsigned char>(s[st])) != 
                tolower(static_cast<unsigned char>(s[end]))) {
                return false;
            }

            st++;
            end--;
        }
        return true;
    }
};