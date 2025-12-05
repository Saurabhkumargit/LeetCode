// https://leetcode.com/problems/sum-of-subarray-ranges/

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;

        // ---------- max contribution ----------
        {
            vector<int> st;
            for (int i = 0; i <= n; i++) {
                while (!st.empty() && (i == n || nums[st.back()] < nums[i])) {
                    int mid = st.back(); 
                    st.pop_back();
                    int left = st.empty() ? -1 : st.back();
                    long long cnt = (long long)(mid - left) * (i - mid);
                    res += cnt * nums[mid];
                }
                st.push_back(i);
            }
        }

        // ---------- min contribution ----------
        {
            vector<int> st;
            for (int i = 0; i <= n; i++) {
                while (!st.empty() && (i == n || nums[st.back()] > nums[i])) {
                    int mid = st.back(); 
                    st.pop_back();
                    int left = st.empty() ? -1 : st.back();
                    long long cnt = (long long)(mid - left) * (i - mid);
                    res -= cnt * nums[mid];
                }
                st.push_back(i);
            }
        }

        return res;
    }
};
