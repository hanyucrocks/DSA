class Solution {
public:
    void dfs(vector<vector<int>> &image, vector<vector<int>> &ans, int newColor, int iniColor, int delCol[], int delRow[], int row, int col){
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor){
                dfs(image, ans, newColor, iniColor, delCol, delRow, nrow, ncol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(image, ans, color, iniColor, delCol, delRow, sr, sc);
        return ans;
    }
};