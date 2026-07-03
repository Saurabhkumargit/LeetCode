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


// Revision (1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {
            if (st.find(num-1) == st.end()) {
                int curr = num;
                int len = 1;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};


// Revision (2)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int num : st) {
            if (!st.count(num - 1)) {
                int curr = num;
                int length = 1;

                while (st.count(curr + 1)) {
                    curr++;
                    length++;
                }

                longest = max(longest, length);
            }
        }
        return longest;
    }
};