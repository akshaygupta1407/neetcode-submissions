class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==0) {
                    q.push({i, j});
                }
            }
        }

        vector<int>dir = {1, 0, -1, 0, 1};

        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                auto tp = q.front();
                q.pop();
                for(int k=0; k<4; k++) {
                    int r = tp.first + dir[k];
                    int c = tp.second + dir[k+1];
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==INT_MAX) {
                        grid[r][c] = grid[tp.first][tp.second] + 1;
                        q.push({r,c});
                    }
                }
            }
        }
    }
};
