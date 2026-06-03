class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 3) return res;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int s = i+1, e = n-1;
            while(s < e) {
                if(nums[i] + nums[s] + nums[e] < 0) {
                    s++;
                } else if(nums[i] + nums[s] + nums[e] > 0) {
                    e--;
                } else {
                    res.push_back(vector<int>{nums[i],nums[s],nums[e]});
                    while(s+1<e && nums[s]==nums[s+1]) s++;
                    while(s<e-1 && nums[e]==nums[e-1]) e--;
                    s++;
                    e--;
                }
            }
        }

        return res;
    }
};