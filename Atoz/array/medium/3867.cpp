// https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> gcd;
        int mx = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            mx = max(nums[i], mx);
            gcd.push_back(__gcd(mx, nums[i]));
        }

        sort(gcd.begin(), gcd.end());
        int n = gcd.size();
        int st = 0;
        int end = n-1;
        long long sum = 0;

        while (end > st) {
            sum += __gcd(gcd[st], gcd[end]);
            st++;
            end--;
        }

        return sum;
    } 
};