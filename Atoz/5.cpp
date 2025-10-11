// https://leetcode.com/problems/longest-palindromic-substring/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() < 1)
        {
            return "";
        }

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < s.length(); ++i)
        {
            int len1 = expandCenter(s, i, i);
            int len2 = expandCenter(s, i, i + 1);

            int currentMax = max(len1, len2);

            if (currentMax > maxLength)
            {
                maxLength = currentMax;
                start = i - (maxLength - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }

    int expandCenter(const string &s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
};