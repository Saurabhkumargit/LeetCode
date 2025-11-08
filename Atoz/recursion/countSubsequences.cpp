// Count all subsequences with sum K

class Solution
{
public:
    int countSubsequenceWithTargetSum(vector<int> &nums, int k)
    {
        // your code goes here
        return helper(0, nums, k);
    }

    int helper(int index, vector<int> &nums, int remaining)
    {
        if (index == nums.size())
        {
            return (remaining == 0) ? 1 : 0;
        }

        int include = helper(index + 1, nums, remaining - nums[index]);

        int exclude = helper(index + 1, nums, remaining);

        return include + exclude;
    }
};