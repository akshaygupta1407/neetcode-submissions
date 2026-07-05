class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1);
        int n = s.length();
        int l = 0, r = 0;
        int ans = 0;
        for(r = 0; r < n; r++) {
            if(mpp[s[r]] >= l) {
                l = mpp[s[r]] + 1;
            }
            mpp[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};