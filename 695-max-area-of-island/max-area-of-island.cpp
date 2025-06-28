class Solution {
public:
    int dfs(int row, int col, vector<vector<int>> &grid){
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, -1, 0, +1};
        int n = grid.size();
        int m = grid[0].size();
        int area= 1;
        if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0) return 0;
        grid[row][col] = 0;
        for(int i = 0; i < 4; i++){
            area += dfs(row + delRow[i], col + delCol[i], grid);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxarea = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    maxarea = max(maxarea, dfs(i, j, grid));
                }
            }
        }
        return maxarea;
    }
};