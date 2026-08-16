class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, e = n - 1;
        while(l <= e) {
            int mid = l + (e - l) / 2;
            if(nums[mid] == target) return mid;
            if(nums[l] <= nums[mid]) {
                if(nums[l] <= target && target <= nums[mid]) {
                    e = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if(nums[mid] <= target && target <= nums[e]) {
                    l = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};