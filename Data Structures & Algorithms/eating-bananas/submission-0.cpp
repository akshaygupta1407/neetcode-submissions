class Solution {
public: 
    bool isValid(int k, vector<int>& piles, int h) {
        long long hrs = 0;

        for(int i=0; i<piles.size(); i++) {
            hrs += (long long)(piles[i]/k) + (long long)(piles[i] % k != 0);
        }

        return hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, r = accumulate(piles.begin(), piles.end(), 0LL);
        int ans = r;

        while(l <= r) {
            long long mid = (l + r) / 2;
            if(isValid(mid, piles, h)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};