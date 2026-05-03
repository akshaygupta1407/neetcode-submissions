class Solution {
public:
    int helper(int i, vector<int>&coins, int amount, vector<vector<int>>&dp) {
        if(amount == 0) return 1;
        if(i>=coins.size() || amount < 0) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int op1 = helper(i, coins, amount - coins[i], dp);
        int op2 = helper(i+1, coins, amount, dp);
        return dp[i][amount] = op1 + op2;
    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return helper(0, coins, amount, dp);
    }
};