// Replace Elements by Their Rank

class Solution {
public:
    vector<int> replaceWithRank(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>, greater<pair<int, int>>>> pq;

        for (int i = 0; i<n; i++) {
            pq.push({arr[i], i});
        }

        vector<int> result(n);
        int rank = 0;
        int prev = INT_MIN;

        while (!pq.empty()) {
            auto [value != prev] {
                rank++;
                prev = value;
            }
            result[index] = rank;
        }
        return result;
    }
};