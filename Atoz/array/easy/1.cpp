// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sum;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(sum.find(complement) != sum.end()) {
                return {sum[complement], i};
            } else {
                sum[nums[i]] = i;
            }
        }
        return {};
    }
};