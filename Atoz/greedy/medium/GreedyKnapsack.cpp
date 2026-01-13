// Fractional Knapsack

class Solution {
public:
    struct Item {
        long long val;
        long long wt;
    };

    static nool cmp (Item &a, Item &b) {
        return (__int128)a.val * b.wt > (__int128)b.val * a.wt;
    }

    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        // Your code goes here
        int n = val.size();
        vector<Item> items(n);

        for (int i = 0; i <n; i++) {
            items[i] = {val[i], wt[i]};
        }

        sort (items.begin(), items.end(), cmp);

        double totalValue = 0.0;
        long long remaining = capacity;

        for (auto &it : items) {
            if (remaining == 0) break;

            if (it.wt <= remaining) {
                totalValue += (double)it.val;
                remaining -= it.wt;
            } else {
                totalValue += (double)it.val * ((double)remaining / (double)it.wt);
                break;
            }
        }
        return totalValue;
    }
};