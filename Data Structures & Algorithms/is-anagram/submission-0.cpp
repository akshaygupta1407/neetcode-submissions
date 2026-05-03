class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int>mpp;
        for(auto x : s) {
            mpp[x]++;
        }
        for(auto x : t) {
            if(mpp[x] == 0) return false;
            mpp[x]--;
        }
        return true;
    }
};
