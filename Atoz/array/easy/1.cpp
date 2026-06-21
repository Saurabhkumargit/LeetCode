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


// revision (1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i <nums.size(); i++) {
            int pair = target - nums[i];
            if (mp.find(pair) != mp.end()) {
                return {mp[pair], i};
            } else {
                mp[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};


// Revision (2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int pair = target - nums[i];
            if (mp.find(pair) != mp.end()) {
                return {mp[pair], i};
            } else {
                mp[nums[i]] = i;
            }
        }
        return {};
    }
};


// Revision (3)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int pair = target - nums[i];
            if (mp.find(pair) != mp.end()) {
                return {mp[pair], i};
            } else {
                mp[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};


// Revision (4)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int pair;
        for (int i = 0; i< nums.size(); i++) {
            pair = target - nums[i];
            if (mp.find(pair) != mp.end()) {
                return {i, mp[pair]};
            } else {
                mp[nums[i]] = i;
            }
        }
        return {0,0};
    }
};


// Revision (5)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int pair = target - nums[i];
            if (mp.find(pair) != mp.end()) {
                return {mp[pair], i};
            } else {
                mp[nums[i]] = i;
            }
        }
        return {};
    }
};


// Revision (6)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sum;
        for (int i = 0; i< nums.size(); i++) {
            int pair = target - nums[i];
            if (sum.find(pair) != sum.end()) {
                return {sum[pair], i};
            } else {
                sum[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};


// Revision (7)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> pair;

        for (int i = 0; i < n; i ++) {
            if (n == 0) return {-1, -1};

            int x = target - nums[i];
            if (pair.find(x) != pair.end()) {
                return {pair[x], i};
            } else {
                pair[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};

// Revision (8)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int pair = target - nums[i];

            if (mp.find(pair) != mp.end()) {
                return {mp[pair], i};
            } else {
                mp[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};