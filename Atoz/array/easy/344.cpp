// https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int beg = 0;
        int end = n-1;
        while (beg<end) {
            char temp = s[beg];
            s[beg] = s[end];
            s[end] = temp;
            beg++;
            end--;
        }
    }
};

// Alt Method
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;

        while(left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};