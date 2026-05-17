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


// Revision (2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (mp.find(sum - k) != mp.end()) {
                cnt += mp[sum - k];
            }
            
            mp[sum]++;
        }
        return cnt;
    }
};


// Revision (3)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int prefixSum =0;
        int cnt = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int target = prefixSum - k;

            if (freq.find(target) != freq.end()) {
                cnt += freq[target];
            }
            freq[prefixSum]++;
        }
        return cnt;
    }
};


// Revision (4)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> totalSum;
        totalSum[0] = 1;
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int target = sum - k;
            if (totalSum.find(target) != totalSum.end()) {
                cnt += totalSum[target];
            } 
            totalSum[sum]++;
            
        }
        return cnt;
    }
};