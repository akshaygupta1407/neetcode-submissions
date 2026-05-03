class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l=0, r=n-1;
        while(l < r) {
            if(!isalpha(s[l]) && !isdigit(s[l])) {
                l++;
                continue;
            }
            if(!isalpha(s[r]) && !isdigit(s[r])) {
                r--;
                continue;
            }
            char ch1 = tolower(s[l]), ch2 = tolower(s[r]);
            if(ch1!=ch2) return false;
            l++;
            r--;
        }

        return true;
    }
};