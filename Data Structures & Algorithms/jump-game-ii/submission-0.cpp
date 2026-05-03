class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return 0;
        if(nums[0]==0)  return -1;
        int mxreach = nums[0], steps = nums[0],jump = 1;
        for(int i=1;i<n;i++)
        {
            if(i==n-1)  return jump;
            mxreach = max(mxreach,i+nums[i]);
            steps--;
            if(steps==0)
            {
                jump++;
                if(i>=mxreach)  return -1;
                steps = mxreach - i;
            }
        }
        return -1;
    }
};