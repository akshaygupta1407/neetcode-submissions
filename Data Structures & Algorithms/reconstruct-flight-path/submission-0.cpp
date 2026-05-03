class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>>h;
    vector<string>ans;
    void euler(string node) {
        while(!h[node].empty()) {
            string next = h[node].top();
            h[node].pop();
            euler(next);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto x : tickets) {
            h[x[0]].push(x[1]);
        }
        euler("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};