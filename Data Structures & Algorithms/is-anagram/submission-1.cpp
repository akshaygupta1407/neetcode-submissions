class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int>arr(26, 0);
        for(auto x : s) arr[x - 'a']++;
        for(auto x : t) {
            if(arr[x - 'a']==0) return false;
            arr[x - 'a']--;
        }
        return true;
    }
};