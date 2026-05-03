class Solution {
public:
    int house(int i, int n, vector<int>&nums, vector<int>&dp) {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick = nums[i] + house(i+2, n, nums, dp);
        int nonPick = house(i+1, n, nums, dp);
        return dp[i] = max(pick, nonPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return max(house(0, n, nums, dp), house(1, n, nums, dp));
    }
};