class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;
        unordered_map<int,int>mpp;
        for(auto x : hand) {
            mpp[x]++;
        }
        vector<int>nums;
        for(auto x : mpp) {
            nums.push_back(x.first);
        }
        sort(nums.begin(), nums.end());

        for(int x : nums) {
            int count = mpp[x];
            for(int i=0; i<groupSize; i++) {
                int card = x + i;
                if(mpp[card] < count) return false;
                mpp[card] -= count;
            } 
        }

        return true;
    }
};