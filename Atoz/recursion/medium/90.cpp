// https://leetcode.com/problems/subsets-ii/

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ds, ans);
        return ans;
    }

    void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
    {
        ans.push_back(ds); // add current subset

        for (int i = ind; i < nums.size(); i++)
        {
            // skip duplicates
            if (i != ind && nums[i] == nums[i - 1])
                continue;

            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans);
            ds.pop_back();
        }
    }
};


// Revision (1)
class Solution {
public:
    void subarray(vector<int>& nums, int k,vector<vector<int>>& ans, vector<int>& current) {
        ans.push_back(current);
        for (int i = k; i < nums.size(); i++) {
            if (i != k && nums[i] == nums[i-1]) {
                continue;
            }
            current.push_back(nums[i]);
            subarray(nums, i+1, ans, current);
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(nums.begin(), nums.end());
        subarray(nums, 0, ans, current);
        return ans;
    }
};