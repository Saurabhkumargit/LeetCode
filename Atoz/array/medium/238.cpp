// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);

        int prefix = 1;
        for (int i =  0; i<n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n-1; i>= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        return ans;
    }
};


// Revision (1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();
       vector<int> result(n,1);

       int prefix = 1;
       for (int i = 0; i< n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
       }

       int suffix = 1;
       for (int i = n-1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
       }
       return result;
    }
};


// Revision (2)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prd(n);
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            prd[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n-1; i >= 0; i--) {
            prd[i] *= suffix;
            suffix *= nums[i]; 
        }
        return prd;
    }
};


// Revision (3)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prd(n);
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            prd[i] = prefix;
            prefix*=nums[i];
        }

        int suffix = 1;
        for (int i = n-1; i >= 0; i--) {
            prd[i] *= suffix;
            suffix*=nums[i];
        }
        return prd;
    }
};


// Revision (4)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prd(n);
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            prd[i] = prefix;
            prefix*=nums[i];
        }

        int suffix = 1;
        for (int i = n-1; i >= 0; i--) {
            prd[i] *= suffix;
            suffix*=nums[i];
        }
        return prd;
    }
};


// Revision (5)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prd(n);
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            prd[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n-1; i >= 0; i--) {
            prd[i] *= suffix;
            suffix *= nums[i];
        
        }
        return prd;
    }
};