// https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for (int num : nums2) {
            while(!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();

            }
            st.push(num);
        }

        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        vector<int> result;
        result.reserve(nums1.size());
        for (int num :  nums1) {
            result.push_back(nextGreater[num]);
        }
        return result;
    }
};