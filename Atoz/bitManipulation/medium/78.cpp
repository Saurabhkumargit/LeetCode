// https://leetcode.com/problems/subsets/

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        int total = 1 << n;
        vector<vector<int>> result;

        for (int mask = 0; mask < total; mask++)
        {
            vector<int> subset;

            for (int bit = 0; bit < n; bit++)
            {
                if (mask & (1 << bit))
                {
                    subset.push_back(nums[bit]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }
};
