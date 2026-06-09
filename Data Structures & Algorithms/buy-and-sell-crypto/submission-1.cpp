class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int mx = 0;
        int buy = prices[0];
        for(int i=1; i<n; i++) {
            if(prices[i] < buy) {
                buy = prices[i];
            } else {
                mx = max(mx, prices[i] - buy);
            }
        }
        return mx;
    }
};