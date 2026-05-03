class Solution {
public:
    string extend(string s, int i, int j) {
        while(i>=0 && j<s.length() && s[i]==s[j]) {
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        int l = s.length();
        if(l==1)
            return s;
        string res = "";
        for(int i=0;i<l;i++) {
            string s1 = extend(s, i, i);
            string s2 = extend(s, i, i+1);
            if(res.length() < s1.length()) {
                res = s1;
            }
            if(res.length() < s2.length()) {
                res = s2;
            }
        }
        return res;
    }
};