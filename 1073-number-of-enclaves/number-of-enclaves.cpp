class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                    if(grid[i][j] == 1){
                        q.push({i, j}); vis[i][j] = 1;
                    }
                }
            }
        }
            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                int delRow [] = {-1, 0, +1, 0};
                int delCol [] = {0, +1, 0, -1};
                for(int i = 0; i < 4; i++){
                    int nr = row + delRow[i];
                    int nc = col + delCol[i];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && grid[nr][nc] == 1){
                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
            int cnt = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j] == 1 && vis[i][j] == 0) cnt++;
                }
            }
        return cnt;
    }
};