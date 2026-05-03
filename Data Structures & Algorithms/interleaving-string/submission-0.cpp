class Solution {
public:
    bool helper(int i, int j, int n, int m, string &s1, string &s2, string &s3, string &curr, vector<vector<int>>&dp) {
        if(i>=n && j>=m && curr == s3) return true;
        if(i>=n && j>=m) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool op1 = false, op2 = false;
        int k = i + j;
        if((i < n) && (s1[i]==s3[k])) {
            curr.push_back(s1[i]);
            op1 = helper(i+1, j, n, m, s1, s2, s3, curr, dp);
            curr.pop_back();
        }
        if((j < m) && (s2[j]==s3[k])) {
            curr.push_back(s2[j]);
            op2 = helper(i, j+1, n, m, s1, s2, s3, curr, dp);
            curr.pop_back();
        }
        return dp[i][j] = (op1 || op2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length();
        if((n + m) != s3.length())   return false;
        string curr = "";
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return helper(0, 0, n, m, s1, s2, s3, curr, dp);
    }
};