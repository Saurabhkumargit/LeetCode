// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int presum = 0;
        int cnt = 0;
        mp[0] = 1;
        for (int i = 0; i<nums.size(); i++) {
            presum += nums[i];
            int remove = presum - k;
            cnt += mp[remove];
            mp[presum] +=1;
        }
            return cnt;
    }
};

// Revision (1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        int cnt = 0;
        int sum = 0;
        prefix[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int req = sum - k;
            if (prefix.find(req) != prefix.end()) {
                cnt += prefix[req];
            }
            prefix[sum] += 1;
        }
        return cnt;
    }
};