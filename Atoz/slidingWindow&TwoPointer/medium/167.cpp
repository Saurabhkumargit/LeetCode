// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int s = 0;
        int e = n-1;
        
        while (e > s) {
            int sum = numbers[s] + numbers[e];

            if (sum == target) {
                return {s + 1, e + 1};
            } else if (sum < target) {
                s++;
            } else {
                e--;
            }
        }
        return {};
    }
};