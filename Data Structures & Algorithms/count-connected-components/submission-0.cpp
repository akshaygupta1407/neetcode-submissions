class Solution {
public:
    vector<int>parent, rank;
    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        int px = find(u);
        int py = find(v);
        if(px == py) return;
        if(rank[px] < rank[py]) {
            parent[px] = py;
        } else if(rank[py] < rank[px]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++) parent[i] = i;
        for(auto x : edges) {
            int u = x[0];
            int v = x[1];
            unite(u, v);
        }
        int count = 0;

        for(int i=0; i<n; i++) {
            if(find(i) == i) count++;
        }

        return count;
    }
};
