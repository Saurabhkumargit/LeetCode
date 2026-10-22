// https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        vector<int> pos(n);
        for(int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        bool increasing = true;
        bool decreasing = true;

        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;

            if (nums[next] != (nums[i] + 1) % n) {
                increasing = false;
            }

            if (nums[next] != (nums[i] - 1 + n) % n) {
                decreasing = false;
            }
        }

        if (increasing) {
            int k = pos[0];
            return min(k, n - k + 2);
        }

        if (decreasing) {
            return min(pos[n-1], n - 1 - pos[0]) + 1;
        }

        return -1;
    }
};