class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        int n = nums.size();
        for(int x : nums) {
            mpp[x]++;
        }
        vector<vector<int>>bucket(n+1);
        vector<int>res;
        for(auto x : mpp) {
            bucket[x.second].push_back(x.first);
        }
        for(int i=n; i>=0; i--) {
            if(bucket[i].size()==0) continue;
            for(int x : bucket[i]) {
                res.push_back(x);
                if(res.size() == k) return res;
            }
        }
        return res;
    }
};