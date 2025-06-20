class Solution {
    int m, n;
    vector<int> dx ={-1, 0, +1, 0};
    vector<int> dy ={0, -1, 0, +1};
public:
    bool isValid(int i, int j){
        return i>= 0 && j >= 0 && i < m && j < n;
    }
    int dfs(int i, int j, int left, pair<int, int> dest, vector<vector<int>> &grid){
        // base case
        if(left == -1 and pair<int, int> (i, j) == dest) return 1;
        grid[i][j] = -1;
        int ans = 0;
        for(int k = 0; k < 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];

            // add up all possibilities to answer
            if(isValid(x, y) and grid[x][y]!=-1) ans += dfs(x, y, left - 1, dest, grid);
            // backtrack
        }
            grid[i][j] = 0;
            return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        pair<int, int> src, dest;
        int empty = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) empty++;
                if(grid[i][j] == 1) src = {i, j};
                if(grid[i][j] == 2) dest = {i, j};
            }
        }
        return dfs(src.first, src.second, empty, dest, grid);
    }
};