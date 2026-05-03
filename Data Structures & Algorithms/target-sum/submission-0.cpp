class Solution {
public:
    int OFFSET = 1000;
    int helper(int i, int n, vector<int>& nums, int target, vector<vector<int>>&dp) {
        if((target == 0) && (i>=n)) return 1;
        if(i>=n) return 0;
        if(dp[i][target+OFFSET]!=-1) return dp[i][target+OFFSET];
        int op1 = helper(i+1, n, nums, target - nums[i], dp);
        int op2 = helper(i+1, n, nums, target + nums[i], dp);
        return dp[i][target+OFFSET] = op1 + op2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for (int x : nums) totalSum += x;
        if (abs(target) > totalSum) return 0;
        int offset = totalSum;
        vector<vector<int>>dp(n+1, vector<int>(5*totalSum+1, -1));
        OFFSET = totalSum;
        return helper(0, n, nums, target, dp);
    }
};