class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
        // vector<vector<bool> vis(m, vector<bool> (n, false));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j}); // all the rotten oranges are pushed now.
                }
            }
        }
        int mins = 0;
        while(!q.empty()){
            int sz = q.size();
            bool rotted = false;
            while(sz--){
                auto [x, y] = q.front();
                q.pop();
                for(auto &d : dirs){
                    int nr = x + d[0];
                    int nc = y + d[1];
                    if(nr >= 0 and nr < m and nc >= 0 and nc < n and grid[nr][nc] == 1){
                        grid[nr][nc] = 2; // rot this piece./
                        q.push({nr, nc});
                        rotted = true;
                        // vis[nr][nc] = 1;
                    }
                }
            }
            if(rotted) mins++;
        }
        // final check here. if the rotten never happens.
        for(int i = 0; i < m; i++){
            for(int j  = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return mins;
    }
};