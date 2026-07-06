class Solution {
public:
    bool matches(vector<int> &hash1, vector<int>&hash2) {
        return hash1 == hash2;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        if(s1 == s2) return true;
        vector<int>hash1(26,0),hash2(26,0);
        for(int i=0; i<s1.length(); i++) {
            hash1[s1[i] - 'a']++;
            hash2[s2[i] - 'a']++;
        }
        for(int i=0; i<s2.length() - s1.length(); i++) {
            if(matches(hash1, hash2)) return true;
            hash2[s2[i+s1.length()] - 'a']++;
            hash2[s2[i] - 'a']--;
        }
        return matches(hash1, hash2);

    }
};