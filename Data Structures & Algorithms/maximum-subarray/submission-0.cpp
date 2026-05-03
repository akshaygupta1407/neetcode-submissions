class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN, ans = 0;
        for(auto x : nums) {
            ans += x;
            mx = max(mx, ans);
            if(ans < 0) ans = 0;
        }
        return mx;
    }
};