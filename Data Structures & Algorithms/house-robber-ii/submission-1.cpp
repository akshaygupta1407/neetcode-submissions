class Solution {
public:
    // int helper(int i, int n, vector<int>&nums, vector<int>&dp) {
    //     if(i>=n) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int pick = nums[i] + helper(i+2, n, nums, dp);
    //     int nonPick = helper(i+1, n, nums, dp);
    //     return dp[i] = max(pick, nonPick);
    // }
    int bottomup(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;
        for(auto x : nums) {
            int current = max(prev1, prev2 + x);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        // int n = nums.size();
        // if(n==1) return nums[0];
        // vector<int>dp1(n, -1), dp2(n, -1);
        // return max(helper(0, n-1, nums, dp1), helper(1, n, nums, dp2));
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<int> firstRange(nums.begin(), nums.end() - 1);
        vector<int> secondRange(nums.begin() + 1, nums.end());
        
        return max(bottomup(firstRange), bottomup(secondRange));
    }
};