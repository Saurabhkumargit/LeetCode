// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

class Solution
{
public:
    int beautySum(string s)
    {
        int totalBeautySum = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i)
        {
            vector<int> freq(26, 0);

            for (int j = i; j < n; ++j)
            {
                freq[s[j] - 'a']++;

                int maxFreq = 0;
                int minFreq = INT_MAX;

                for (int k = 0; k < 26; ++k)
                {
                    if (freq[k] > 0)
                    {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                totalBeautySum += (maxFreq - minFreq);
            }
        }

        return totalBeautySum;
    }
};