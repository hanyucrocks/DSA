class Solution {
public:
    int f(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i < 0 or j < 0) return 0;
        dp[0][0] = 1;
        if(dp[i][j]!=-1) return dp[i][j];
        //m-1, n-1 se 0 0 aana hai, toh ulta
        int up = f(i-1, j, m, n, dp);
        int left = f(i, j-1, m, n, dp);
        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return f(m-1, n-1, m, n, dp);
    }
};