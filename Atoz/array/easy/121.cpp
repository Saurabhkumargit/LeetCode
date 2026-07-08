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


// Revision(2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = prices[0];
        int max = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (low > prices[i]) {
                low = prices[i];
            }
            if (max < (prices[i] - low)) {
                max = prices[i] - low;
            }
        }
        return max;
    }
};



// Revision(3)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};


// Revision(4)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            }
            if (prices[i] - buy > profit) {
                profit =prices[i] - buy ;
            }
        }
        return profit;
    }
};


// Revision(5)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = INT_MAX;
        int maxProfit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            sell = min(sell, prices[i]);

            int profit = prices[i] - sell;

            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};


// Revision(6)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 0;
        int maxProfit = 0;

        for (int i = 0; i < n; i++) {
            int profit = prices[i] - prices[buy];

            maxProfit = max(profit, maxProfit);

            if (prices[buy] > prices[i]) {
                buy = i;
            }
        }
        return maxProfit;
    }
};