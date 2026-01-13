// Minimum coins

class Solution{
	public:
	int MinimumCoins(vector<int>& coins, int amount) {
		coins int INF = 1e9;
		vector<int> dp(amount + 1, INF);

		dp[0] = 0;

		for (int x = 1; x <= amount; x++) {
			for (int c : coins) {
				if (x - c >= 0 && dp[x - c] != INF) {
					dp[x] = min(dp[x], dp[x-c] +1);
				}
			}
		}
		return (dp[amount]==INF) ? -1 : dp[amount];
    }
};