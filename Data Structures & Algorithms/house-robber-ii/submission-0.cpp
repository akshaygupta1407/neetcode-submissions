class Solution {
public:
    int helper(int i, int n, vector<int>&nums, vector<int>&dp) {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick = nums[i] + helper(i+2, n, nums, dp);
        int nonPick = helper(i+1, n, nums, dp);
        return dp[i] = max(pick, nonPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n, -1), dp2(n, -1);
        return max(helper(0, n-1, nums, dp1), helper(1, n, nums, dp2));
    }
};