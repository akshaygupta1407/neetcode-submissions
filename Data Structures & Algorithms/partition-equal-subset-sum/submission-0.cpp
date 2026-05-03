class Solution {
public:
    bool helper(vector<int>&nums, int i, int n, int sum, vector<vector<int>>&dp) {
        if(sum==0) return true;
        if(sum < 0) return false;
        if(i>=n) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum] = (helper(nums, i+1, n, sum - nums[i], dp) || helper(nums, i+1, n, sum, dp));
    }
    bool canPartition(vector<int>& nums) {
        int total = 0, n = nums.size();
        for(auto x : nums) total += x;
        if(total%2) return false;
        int half = total/2;
        vector<vector<int>>dp(n+1, vector<int>(half+1, -1));
        return helper(nums, 0, n, half, dp);
    }
};