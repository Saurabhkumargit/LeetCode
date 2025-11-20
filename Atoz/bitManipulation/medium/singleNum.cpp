// Single Number - III

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        // your code goes here
        long long xorAll = 0;

        for (int num : nums)
            xorAll ^= num;

        long long diffBit = xorAll & -xorAll;

        int a = 0, b = 0;
        for (int num : nums)
        {
            if (num & diffBit)
                a ^= num;
            else
                b ^= num;
        }

        if (a < b)
            return {a, b};
        return {b, a};
    }
};