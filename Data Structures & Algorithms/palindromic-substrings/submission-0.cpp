class Solution {
public:
    int count = 0;
    void checkPalindrome(string &s, int l, int r, int n) {
        while(l>=0 && r<n) {
            if(s[l]!=s[r]) return;
            l--;
            r++;
            count++;
        }
        return;
    }
    int countSubstrings(string s) {
        int n = s.length();
        for(int i=0; i<n; i++) {
            checkPalindrome(s, i, i, n);
            checkPalindrome(s, i, i+1, n);
        }
        return count;
    }
};