// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;

        for (int num : s) {
            if (!s.count(num-1)) {
                int current = num;
                int length = 1;

                while (current != INT_MAX && s.count(current + 1)) {
                    current++;
                    length++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }
};