class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, list<string>> mpp;
        for(auto x : strs) {
            string sorted = x;
            sort(sorted.begin(), sorted.end());
            mpp[sorted].push_back(x);
        }

        vector<vector<string>> res;
        for(auto x : mpp) {
            vector<string>curr;
            for(auto y : x.second) curr.push_back(y);
            res.push_back(curr);
        }

        return res;
    }
};
