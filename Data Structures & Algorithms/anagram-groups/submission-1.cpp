class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>>mpp;
        for(auto s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = "";
            for(int i=0; i<26; i++) {
                key.push_back(count[i] + 'a');
                key += "#";
            }
            mpp[key].push_back(s);
        }
        for(auto x : mpp) {
            res.push_back(x.second);
        }
        return res;
    }
};