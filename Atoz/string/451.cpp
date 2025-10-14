// 451. Sort Characters By Frequency

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }

        vector<string> buckets(s.length() + 1, "");
        for (auto const &[character, count] : freq)
        {
            buckets[count].append(count, character);
        }

        string result = "";
        for (int i = s.length(); i >= 1; --i)
        {
            if (!buckets[i].empty())
            {
                result += buckets[i];
            }
        }
        return result;
    }
};