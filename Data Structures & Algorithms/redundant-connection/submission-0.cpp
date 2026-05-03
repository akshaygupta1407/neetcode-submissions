class Solution {
public:
    vector<int>parent, rank;
    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v) {
        int px = find(u);
        int py = find(v);

        if(px == py) return false;

        if(rank[px] < rank[py]) {
            parent[px] = py;
        } else if(rank[py] < rank[px]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }

        for(auto x : edges) {
            int u = x[0], v = x[1];
            if(!unite(u, v)) return {u, v};
        }
        return {};
    }
};