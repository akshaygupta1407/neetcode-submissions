class Solution {
public:
    int helper(vector<int>& prices, int i, int n, int canBuy, vector<vector<int>>&dp) {
        if (i >= n) return 0;
        if (dp[i][canBuy] != -1) return dp[i][canBuy];

        if (canBuy) {
            int buy = -prices[i] + helper(prices, i + 1, n, 0, dp);
            int skip = helper(prices, i + 1, n, 1, dp);
            return dp[i][canBuy] = max(buy, skip);
        } else {
            int sell = prices[i] + helper(prices, i + 2, n, 1, dp);
            int skip = helper(prices, i + 1, n, 0, dp);
            return dp[i][canBuy] = max(sell, skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return helper(prices, 0, n, 1, dp);
    }
};