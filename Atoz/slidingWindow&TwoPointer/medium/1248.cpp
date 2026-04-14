// https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1;

        int oddCount = 0;
        int result = 0;

        for (int num : nums) {
            if (num % 2 == 1)
            oddCount++;

            if(freq.count(oddCount - k))
            result += freq[oddCount - k];

            freq[oddCount]++;
        }

        return result;
    }
};