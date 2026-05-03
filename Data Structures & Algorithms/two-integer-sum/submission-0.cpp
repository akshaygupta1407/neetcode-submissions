class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mpp;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            int sec = target - nums[i];
            if(mpp.find(sec) != mpp.end()) {
                return {mpp[sec], i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};