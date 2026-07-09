// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]] > 1) {
                return true;
            }
        }
        return false;
    }
};

// Alt Method (set)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num))
                return true;

            seen.insert(num);
        }
        return false;
    }
};


// Revision (1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) 
                return true;
            seen.insert(num);
        }
        return false;
    }
};


// Revision (2)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for (int i = 0; i < nums.size(); i++) {
            if (set.count(nums[i])) {
                return true;
            } else {
                set.insert(nums[i]);
            }
        }
        return false;
    }
};