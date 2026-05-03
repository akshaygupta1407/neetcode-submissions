class Solution {
public:
    // bool dfs(int node, unordered_map<int, list<int>>&h, vector<bool>&visited, int parent) {
    //     visited[node] = true;

    //     for(auto neigh : h[node]) {
    //         if(neigh == parent) continue;
    //         if(visited[neigh]) return true;
    //         if(dfs(neigh, h, visited, node));
    //     }
    //     return false;
    // }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        unordered_map<int, list<int>>h;
        for(auto x : edges) {
            h[x[0]].push_back(x[1]);
            h[x[1]].push_back(x[0]);
        }
        vector<bool>visited(n, false);
        queue<pair<int,int>>q;
        q.push({0, -1});
        visited[0] = true;

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            for(auto neigh : h[node.first]) {
                if(!visited[neigh]) {
                    visited[neigh] = true;
                    q.push({neigh, node.first});
                } else if(neigh != node.second) {
                    return false;
                }
            }
        }

        // bool isCycle = dfs(0, h, visited, -1);
        // if(isCycle) return false;

        for(auto x : visited) {
            if(!x) return false;
        }
        return true;
    }
};
