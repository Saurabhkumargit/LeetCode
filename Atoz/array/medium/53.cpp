// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > maxSum) {
                maxSum = sum;
            }
            if (sum < 0) sum = 0;
        }
        return maxSum;
    }
};


// Revision(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > max) {
                max = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return max;

    }
};