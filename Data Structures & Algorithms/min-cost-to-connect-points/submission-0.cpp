class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, list<pair<int, int>>> adj;
        int n = points.size();
        for(int i=0; i<n; i++) {
            auto u = points[i];
            for(int j=i+1; j<n; j++) {
                auto v = points[j];
                int wt = abs(u[0] - v[0]) + abs(u[1] - v[1]);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        int ans = 0;
        vector<int>visited(n, false);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, 0, -1});
        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            int wt = tp[0], node = tp[1];
            if(visited[node]) continue;
            visited[node] = true;
            ans+=wt;
            for(auto neigh : adj[node]) {
                if(!visited[neigh.first]) {
                    pq.push({neigh.second, neigh.first});
                }
            }
        }
        return ans;
    }
};