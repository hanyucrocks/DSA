class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};

    // dfs se hi karo..
    bool dfs(int row, int col, int pr, int pc, vector<vector<char>> &grid, vector<vector<int>> &vis){
        vis[row][col] = 1;
        int m = grid.size();
        int n = grid[0].size();
        for(auto &d : dirs){
            int nr = row + d[0];
            int nc = col + d[1];
            // out of bounds
            if(nr < 0 or nc < 0 or nr >= m or nc >= n) continue;
            if(grid[nr][nc]!=grid[row][col]) continue; // must be same
            if(nr == pr and nc == pc) continue;
            if(vis[nr][nc]) return true;
            if(dfs(nr, nc, row, col, grid, vis)) return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // given a 2d aara ayyyyyyyyy
        vector<vector<int>> vis(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j]){
                    if(dfs(i, j, -1, -1, grid, vis))
                    return true;
                }
            }
        }
        return false;
    }
};