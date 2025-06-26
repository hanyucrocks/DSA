class Solution {
public:
    //
    int f(int row, int col, int m, int n, vector<vector<int>> &a, vector<vector<int>> &dp){
        if(dp[row][col]!=-1) return dp[row][col];
        int sum =1;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] ={0, -1, 0, +1};
        for(int i = 0; i < 4; i++){
            int newrow = row + delRow[i];
            int newcol = col + delCol[i];
            if(newrow >= 0 && newrow < m && newcol >= 0 && newcol < n && a[newrow][newcol] > a[row][col]){
                sum = max(sum, 1 + f(newrow, newcol, m, n, a, dp));
            }
        } 
        return dp[row][col] = sum;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, f(i, j, m, n, matrix, dp));
            }
        }
        return ans;
    }
};