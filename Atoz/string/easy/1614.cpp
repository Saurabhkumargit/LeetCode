// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int depth = 0;

        for (int i = 0; i< s.length(); i++) {
            if (s[i] == '(') {
                depth++;
            } else if (s[i] == ')') {
                maxDepth = max(depth, maxDepth);
                depth--;
            }
        }
        return maxDepth;
    }
};