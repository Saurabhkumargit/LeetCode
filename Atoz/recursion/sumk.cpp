// Check if there exists a subsequence with sum K

class Solution
{
public:
    bool checkSubsequenceSum(vector<int> &nums, int k)
    {
        // your code goes here
        return helper(0, nums, k);
    }

    bool helper(int index, vector<int> &nums, int remaining)
    {
        if (remaining == 0)
            return true;

        if (index == nums.size())
            return false;

        if (nums[index] <= remaining)
        {
            if (helper(index + 1, nums, remaining - nums[index]))
                return true;
        }

        if (helper(index + 1, nums, remaining))
            return true;

        return false;
    }
};