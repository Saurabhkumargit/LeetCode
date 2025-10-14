// 242. Valid Anagram

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        int counts[26] = {0};

        for (char c : s)
        {
            counts[c - 'a']++;
        }

        for (char c : t)
        {
            counts[c - 'a']--;
            if (counts[c - 'a'] < 0)
            {
                return false;
            }
        }

        return true;
    }
};