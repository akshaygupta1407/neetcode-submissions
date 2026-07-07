class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>mpp(256, 0);
        int ans = INT_MAX;
        int i = 0, j = 0, count = 0, start = 0;
        for(auto x : t) {
            if(mpp[x] == 0) count++;
            mpp[x]++;
        }

        while(j < s.length()) {
            mpp[s[j]]--;
            if(mpp[s[j]] == 0) count--;
            while(count == 0) {
                if(ans > j - i + 1) {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                
                mpp[s[i]]++;
                if(mpp[s[i]] == 1) count++;
                i++;
            }
            j++;
        }
        if(ans == INT_MAX) return "";
        return s.substr(start, ans);
    }
};