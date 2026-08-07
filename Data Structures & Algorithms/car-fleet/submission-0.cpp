class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++) {
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end());
        stack<double>st;

        for(int i=0; i<n; i++) {
            while(!st.empty() && st.top() <= (target - v[i].first)/(v[i].second*1.0)) {
                st.pop();
            }
            st.push((target - v[i].first)/(v[i].second*1.0));
        }

        return st.size();
    }
};