// https://leetcode.com/problems/combination-sum-ii/

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }

    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++)
        {
            // Skip duplicates
            if (i > ind && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
};


// Revision (1)
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;
    int sum = 0;

    void backtrack(vector<int>& candidates, int target, int sum, int pos) {
        if (sum == target) {
            ans.push_back(current);
            return;
        }

        for (int i = pos; i < candidates.size(); i++) {
            if (i > pos && candidates[i] == candidates[i - 1])
                continue;

            if (sum + candidates[i] > target)
                break;

            current.push_back(candidates[i]);

            backtrack(candidates, target, sum + candidates[i], i + 1);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, sum, 0);
        return ans;
    }
};