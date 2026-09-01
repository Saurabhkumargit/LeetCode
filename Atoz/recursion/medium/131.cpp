// https://leetcode.com/problems/palindrome-partitioning/

class Solution
{
public:
    vector<vector<string>> res;
    vector<string> path;

    bool isPalindrome(const string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    void backtrack(const string &s, int start)
    {
        if (start == s.size())
        {
            res.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++)
        {
            if (isPalindrome(s, start, end))
            {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        backtrack(s, 0);
        return res;
    }
};


// Revision (1)
class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r])
                return false;
            
            l++;
            r--;
        }
        return true;
    }

    void solve (string& s,
               int start,
               vector<string>& curr,
               vector<vector<string>>& ans) {
        if (start == s.length()) {
            ans.push_back(curr);
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                curr.push_back(s.substr(start, end - start + 1));

                solve(s, end+1, curr, ans);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
       vector<vector<string>> ans;
       vector<string> curr;

       solve(s, 0, curr, ans);

       return ans;
    }
};