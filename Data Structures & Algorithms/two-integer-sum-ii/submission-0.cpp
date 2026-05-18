class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n-1;
        while(s < e) {
            if(nums[s] + nums[e] == target) return {s+1, e+1};
            else if (nums[s] + nums[e] > target) e--;
            else s++;
        }
        return {s+1, e+1};
    }
};