// https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        // Count frequencies
        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Handle 1 separately
        if (freq.count(1))
            ans = max(ans, (freq[1] % 2 == 0) ? freq[1] - 1 : freq[1]);

        // Try every possible starting value
        for (auto &[x, cnt] : freq) {
            if (x == 1)
                continue;

            long long cur = x;
            int len = 0;

            while (true) {
                auto it = freq.find(cur);

                if (it == freq.end() || it->second < 2)
                    break;

                len += 2;

                if (cur * cur > 1000000000LL)
                    break;

                cur *= cur;
            }

            auto it = freq.find(cur);

            if (it != freq.end() && it->second == 1)
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};