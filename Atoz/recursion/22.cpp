// https://leetcode.com/problems/generate-parentheses/

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    void backtrack(int n, int open, int close, string current, vector<string> &result)
    {
        // Base case: if the string is complete
        if ((int)current.size() == 2 * n)
        {
            result.push_back(current);
            return;
        }

        // Add '(' if we can still add one
        if (open < n)
            backtrack(n, open + 1, close, current + "(", result);

        // Add ')' if valid (can't close more than we open)
        if (close < open)
            backtrack(n, open, close + 1, current + ")", result);
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        backtrack(n, 0, 0, "", result);
        return result;
    }
};
