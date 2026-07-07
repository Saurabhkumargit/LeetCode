// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = 0, rmax = 0, total = 0;
        int l = 0;
        int r = n-1;
        while (l < r) {
            if (height[l] < height[r]) {
                if (lmax > height[l]) {
                    total += lmax - height[l];
                } else {
                    lmax = height[l];
                }
                l = l+1;
            } else {
                if (rmax > height[r]){
                    total += rmax - height[r];
                } else {
                    rmax = height[r];
                }
                r = r-1;
            }
        }
        return total;
    }
};


// Revision (1)
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int total = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= leftMax) {
                    leftMax = height[l];
                } else {
                    total += leftMax - height[l];
                }
                l++;
            } else {
                if (height[r] >= rightMax) {
                    rightMax = height[r];
                } else {
                    total += rightMax - height[r];
                }
                r--;
            }
        }

        return total;
    }
};


// Revision (2)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = 0;
        int rmax = 0;
        int l = 0;
        int r = n-1;
        int water = 0;
        while(l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= lmax) {
                    lmax = height[l];
                } else {
                    water += lmax-height[l];
                }
                l++;
            } else {
                if (height[r] >= rmax) {
                    rmax = height[r];
                } else {
                    water += rmax - height[r];
                }
                r--;
            }
        }
        return water;
    }
};


// Revision (3)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        return water;
    }
};


// Revision (4)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int lmax = 0, rmax = 0;
        int ans = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= lmax)
                    lmax = height[left];
                else
                    ans += lmax - height[left];

                left++;
            } else {
                if (height[right] >= rmax)
                    rmax = height[right];
                else
                    ans += rmax - height[right];

                right--;
            }
        }

        return ans;
    }
};