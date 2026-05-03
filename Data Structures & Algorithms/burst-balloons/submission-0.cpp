class Solution {
public:
    int helper(vector<int>&nums, int i, int j, vector<vector<int>>&dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int k = i + 1; k < j; k++) {
            ans = max(ans, (nums[i] * nums[k] * nums[j]) + helper(nums, i, k, dp) + helper(nums, k, j, dp));
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n+2, 1);
        for(int i=0; i<n; i++) {
            res[i+1] = nums[i];
        }
        n+=2;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(res, 0, n-1, dp);
    }
};