// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;
        for (int i = 0; i< prices.size(); i++) {
            if( prices[i] < buy) {
                buy= prices[i];
            } 
            if ( prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }

        }
        return profit;
    }
};


// Revision(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min = prices[0];
        int profit = 0;
        for ( int i =0; i < prices.size(); i++) {
            if (prices[i] < min) {
                min = prices[i];
            }
            if (prices[i] - min > profit){
                profit = prices[i] - min;
            }

        }
        return profit;
    }
};