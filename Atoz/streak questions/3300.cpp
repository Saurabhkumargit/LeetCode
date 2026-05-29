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

// alt approach
class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);

            int sum = 0;
            for (int j = 0; j < s.length(); j++) {
                sum += s[j] - '0';
            }

            mn = min(mn, sum);
        }

        return mn;
    }
};