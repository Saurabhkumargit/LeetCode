// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};

// Min-Heap Approach

// Revision (1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (int x : nums) {
            pq.push(x);
        }

        for (int i = 1; i < k; i++) {
            pq.pop();
        }

        return pq.top();
    } 
};