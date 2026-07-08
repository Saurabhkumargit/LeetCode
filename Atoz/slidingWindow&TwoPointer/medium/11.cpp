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


// Revision (1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ans = 0;

        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);

            if (height[l] < height[r])
                l++;
            else
                r--;
        }

        return ans;
    }
};