// https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > st.top().first) {
                int idx = st.top().second;
                ans[idx] = i - idx;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return ans;
    }
};