class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<int>dir = {-1, 0, 1, 0, -1};

        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            int time = tp[0], x = tp[1], y = tp[2];

            if (x == n-1 && y == n-1) return time;
            if(vis[x][y]) continue;
            vis[x][y] = true;

            for(int i=0; i<4; i++) {
                int nx = x + dir[i];
                int ny = y + dir[i+1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]) {
                    pq.push({max(time, grid[nx][ny]), nx, ny});
                }
            }
        }
        return 0;
    }
};