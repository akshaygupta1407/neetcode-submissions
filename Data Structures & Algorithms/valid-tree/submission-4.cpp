class Solution {
public:
    vector<int>parent, rank;

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
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
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        rank.resize(n,0);
        parent.resize(n);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
        for(auto x : edges) {
            int u = x[0];
            int v = x[1];
            if(!unite(u,v)) return false;
        }
        return true;
    }
};
