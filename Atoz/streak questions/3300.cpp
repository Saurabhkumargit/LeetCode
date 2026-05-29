// https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/

class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;

        for (int x : nums) {
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            mn = min(mn, sum);
        }
        return mn;
    }
};