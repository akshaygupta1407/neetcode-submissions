class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> mpp;
        for(auto x : flights) {
            mpp[x[0]].push_back({x[1], x[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        vector<int> dist(n+1, INT_MAX);
        pq.push({0, src, 0});

        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int cost = t[0];
            int curr = t[1];
            int stop = t[2];
            if(curr == dst) return cost;
            if(dist[curr] < stop) continue;
            dist[curr] = stop;

            if(stop > k) continue;

            for(auto next : mpp[curr] )
                    pq.push( { cost+next.second, next.first, stop+1 });

        }
        return -1;
    }
};