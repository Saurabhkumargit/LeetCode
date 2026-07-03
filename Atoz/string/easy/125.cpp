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


// Revision (1)
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() -1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};


// Revision (2)
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int beg = 0;
        int end = n-1;
        while (beg < end) {
           while (beg<end && !isalnum(s[beg])) {
            beg++;
           }

           while (beg<end && !isalnum(s[end])) {
            end--;
           }

           if (tolower(s[beg]) != tolower(s[end])) {
            return false;
           }

           beg++;
           end--;
        }
        return true;
    }
};


// Revision (3)
class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int end = s.length() - 1;

        while (st < end) {
            while (st < end && !isalnum(s[st]))
                st++;
            while (st < end && !isalnum(s[end]))
                end--;

            if (tolower(s[st]) != tolower(s[end]))
                return false;

            st++;
            end--;
        }

        return true;
    }
};