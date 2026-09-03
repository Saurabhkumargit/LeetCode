// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution
{
public:
    void backtrack(int index, string &digits, string &current, vector<string> &ans, vector<string> &mapping)
    {
        if (index == digits.size())
        {
            ans.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char ch : letters)
        {
            current.push_back(ch);
            backtrack(index + 1, digits, current, ans, mapping);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.empty())
            return ans;

        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        string current = "";
        backtrack(0, digits, current, ans, mapping);
        return ans;
    }
};


// Revision (1)
class Solution {
public:
    vector<string> ans;

    void solve(int idx, string& digits,
               unordered_map<char, string>& mp,
               string& curr) {

        if (curr.size() == digits.size()) {
            ans.push_back(curr);
            return;
        }

        char ch = digits[idx];
        string str = mp[ch];

        for (int i = 0; i < str.length(); i++) {
            curr.push_back(str[i]);

            solve(idx + 1, digits, mp, curr);

            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        string curr = "";

        solve(0, digits, mp, curr);

        return ans;
    }
};