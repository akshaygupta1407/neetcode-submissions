class Solution {
public:
    int helper(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
        int m = word1.size(), n = word2.size();

        if (i == m) return n - j; 
        if (j == n) return m - i;

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) {
            return dp[i][j] = helper(i + 1, j + 1, word1, word2, dp);
        }

        int insertOp = 1 + helper(i, j + 1, word1, word2, dp);
        int deleteOp = 1 + helper(i + 1, j, word1, word2, dp);
        int replaceOp = 1 + helper(i + 1, j + 1, word1, word2, dp);

        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 0, word1, word2, dp);
    }
};