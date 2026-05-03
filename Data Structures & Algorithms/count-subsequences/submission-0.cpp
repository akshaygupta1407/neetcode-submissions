class Solution {
public:
    int helper(int i, int j, int m, int n, string &s, string &t, vector<vector<int>>&dp) {
        if(j==n) return 1;
        if(i==m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int op1 = 0;
        op1 = helper(i+1, j, m, n, s, t, dp);
        if(s[i] == t[j]) {
            op1 += helper(i+1, j+1, m, n, s, t, dp);
        }

        return dp[i][j] = op1;
    }
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return helper(0, 0, m, n, s, t, dp);
    }
};