// https://leetcode.com/problems/subsets/

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }

private:
    void backtrack(int index, vector<int> &nums, vector<int> &current, vector<vector<int>> &result)
    {
        // Add the current subset
        result.push_back(current);

        // Explore further elements
        for (int i = index; i < nums.size(); i++)
        {
            current.push_back(nums[i]);              // include nums[i]
            backtrack(i + 1, nums, current, result); // recurse
            current.pop_back();                      // backtrack (remove last element)
        }
    }
};
