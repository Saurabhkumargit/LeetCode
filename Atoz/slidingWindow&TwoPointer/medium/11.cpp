// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int st = 0;
        int end = n-1;
        int maxWater = 0;
        
        while (end > st) {
            int cap = (end - st) * min(height[st], height[end]);
            maxWater = max(maxWater, cap);

            if (height[st] < height[end])
                st++;
            else
                end--;
        }
        return maxWater;
    }
};