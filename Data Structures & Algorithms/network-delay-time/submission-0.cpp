class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, list<pair<int, int>>>h;
        for(auto x : times) {
            h[x[0]].push_back({x[1], x[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<>> pq;
        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            for(auto &[neig, wt] : h[node]) {
                if((time + wt) < dist[neig]) {
                    dist[neig] = time + wt;
                    pq.push({dist[neig], neig});
                }
            }
        }

        int ans = 0;
        for(int i=1; i<n+1; i++) {
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};