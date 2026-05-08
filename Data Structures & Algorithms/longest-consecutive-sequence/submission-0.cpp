class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set;
        for(auto x : nums)
        {
            set.insert(x);
        }
        int mx = 0;
        for(auto x : nums)
        {
            if(!set.count(x-1))
            {
                int l = 1;
                int curr = x;
                while(set.count(curr+1))
                {
                    curr++;
                    l++;
                }
                mx = max(mx,l);
            }
        }
        return mx;
    }
};