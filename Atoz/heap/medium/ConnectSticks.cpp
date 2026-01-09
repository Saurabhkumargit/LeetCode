// Minimum Cost to Connect Sticks

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        // Your Code Goes Here
        priority_queue<int, vector<int>, greater<int>> minHeap (
            sticks.begin(), sticks.end();
        );

        int totalCost = 0;

        while (minHeap.size() > 1) {
            int a = minHeap.top(); minHeap.pop();
            int b = minHeap.top(); minHeap.pop();

            int cost = a+b;
            totalCost += cost;

            minHeap.push(cost);
        }
        return totalCost;
    }
};