class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int>mpp;
        for(auto x : nums) {
            mpp[x]++;
            if(mpp[x] > 1) return true;
        }
        return false;
    }
};