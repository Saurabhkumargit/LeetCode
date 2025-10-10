// https://leetcode.com/problems/roman-to-integer/

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> roman_values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        int total = roman_values[s.back()];

        for (int i = s.length() - 2; i >= 0; --i)
        {
            int current_val = roman_values[s[i]];
            int next_val = roman_values[s[i + 1]];

            if (current_val < next_val)
            {
                total -= current_val;
            }
            else
            {
                total += current_val;
            }
        }

        return total;
    }
};