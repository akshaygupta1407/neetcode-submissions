class Solution {
public:
    int helper(int i, int j, int m, int n, vector<vector<int>>& matrix, int prev, vector<vector<int>>&dp) {
        if(i<0 || j<0 || i>=m || j>=n || prev >= matrix[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        ans = max(ans, 1 + helper(i+1, j, m, n, matrix, matrix[i][j], dp));
        ans = max(ans, 1 + helper(i, j+1, m, n, matrix, matrix[i][j], dp));
        ans = max(ans, 1 + helper(i-1, j, m, n, matrix, matrix[i][j], dp));
        ans = max(ans, 1 + helper(i, j-1, m, n, matrix, matrix[i][j], dp));
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        int mx = 1;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                mx = max(mx, helper(i, j, m, n, matrix, -1, dp));
            }
        }
        return mx;
    }
};