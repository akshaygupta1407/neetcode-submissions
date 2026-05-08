class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(auto x : strs) {
            s += x;
            s += ".";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string>res;
        string str = "";
        for(auto x : s) {
            if(x=='.') {
                res.push_back(str);
                str = "";
            } else {
                str += x;
            }
        }
        return res;
    }
};
