class Solution {
public:
    vector<vector<int>> memo;

    bool solve(string &s, string &p, int i, int j) {
        if (j == p.size()) {
            return i == s.size();
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        bool firstMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        bool ans;
        if (j + 1 < p.size() && p[j + 1] == '*') {
            ans = solve(s, p, i, j + 2) || (firstMatch && solve(s, p, i + 1, j));
        } else {
            ans = firstMatch && solve(s, p, i + 1, j + 1);
        }

        return memo[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        memo.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(s, p, 0, 0);
    }
};