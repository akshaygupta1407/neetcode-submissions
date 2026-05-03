class Solution {
public:
    int helper(string &s, int i, int n, vector<int>&dp) {
        if(i>=n) return 1;
        if(i==n-1 && s[i]!='0') return 1;
        else if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int op1=0, op2=0;
        op1 = helper(s, i+1, n, dp);
        string joinStrr = "";
        joinStrr.push_back(s[i]);
        joinStrr.push_back(s[i+1]);
        if(joinStrr >= "1" && joinStrr <= "26") {
            op2 = helper(s, i+2, n, dp);
        }
        return dp[i] = op1 + op2;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n, -1);
        return helper(s, 0, n, dp);
    }
};