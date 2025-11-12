// Subsets 1

class Solution
{
public:
    vector<int> subsetSums(vector<int> &nums)
    {
        // your code goes here
        vector<int> result;
        helper(0, 0, nums, result);
        return result;
    }

    void helper(int index, int currSum, vector<int> &nums, vector<int> &result)
    {
        if (index == nums.size())
        {
            result.push_back(currSum);
            return;
        }

        helper(index + 1, currSum + nums[index], nums, result);

        helper(index + 1, currSum, nums, result);
    }
};