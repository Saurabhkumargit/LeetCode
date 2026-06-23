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


// Revision (1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        if (s.length() != t.length())
            return false;

        for (int i = 0; i< s.length(); i++) {
            mp[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++) {
            mp[t[i]]--;
        }
        for (int i = 0; i < mp.size(); i++) {
            if (mp[s[i]] != 0) 
                return false;
        }
        return true;
    }
};