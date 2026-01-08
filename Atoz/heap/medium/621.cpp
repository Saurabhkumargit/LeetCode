// https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) {
            freq[c - 'A']++;
        }
        
        priority_queue<int> pq;
        for (int f : freq) {
            if (f > 0) pq.push(f);
        }
        
        int time = 0;
        
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> temp;
            
            while (cycle > 0 && !pq.empty()) {
                int cur = pq.top();
                pq.pop();
                
                cur--;        
                time++;
                cycle--;
                
                if (cur > 0) {
                    temp.push_back(cur);
                }
            }
            
            for (int t : temp) {
                pq.push(t);
            }
            
            if (!pq.empty()) {
                time += cycle;
            }
        }
        
        return time;
    }
};
