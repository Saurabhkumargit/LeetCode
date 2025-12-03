// https://leetcode.com/problems/sum-of-subarray-minimums/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Count of strictly greater elements to the left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Count of greater or equal elements to the right
        for (int i = 0; i < n; i++) {
            int i2 = n - 1 - i;
            while (!st.empty() && arr[st.top()] >= arr[i2])
                st.pop();

            right[i2] = st.empty() ? n - i2 : st.top() - i2;
            st.push(i2);
        }

        long long result = 0;
        for (int i = 0; i < n; i++) {
            long long contribution = (long long) arr[i] * left[i] * right[i];
            result = (result + contribution) % MOD;
        }

        return result;
    }
};
