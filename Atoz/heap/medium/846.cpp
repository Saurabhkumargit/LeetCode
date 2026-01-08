// https://leetcode.com/problems/hand-of-straights/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        
        unordered_map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& [card, count] : freq) {
            pq.push(card);
        }
        
        while (!pq.empty()) {
            int start = pq.top();
            
            for (int i = 0; i < groupSize; i++) {
                int card = start + i;
                
                if (freq[card] == 0) return false;
                
                freq[card]--;
                
                if (freq[card] == 0) {
                    if (card != pq.top()) return false;
                    pq.pop();
                }
            }
        }
        
        return true;
    }
};



