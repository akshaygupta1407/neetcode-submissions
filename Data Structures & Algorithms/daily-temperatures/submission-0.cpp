class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>res(n,0);
        stack<pair<int,int>>st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && st.top().first < temperatures[i]) {
                auto tp = st.top();
                st.pop();
                res[tp.second] = i - tp.second;
            }
            st.push({temperatures[i], i});
        }
        return res;
    }
};