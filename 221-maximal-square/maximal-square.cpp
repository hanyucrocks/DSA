class Solution {
public:
    int m, n;
    vector<vector<char>> mat;
    int f(int i, int j, vector<vector<int>> &dp){
        if(i >= m or j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(mat[i][j] == '0') return dp[i][j] = 0;
        int down = f(i+1, j, dp);
        int right = f(i, j+1, dp);
        int diag = f(i+1, j+1, dp);
        return dp[i][j] = 1 + min({down, right, diag});

    }
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        mat = matrix;
        // ughhhhhhhh fyuck this
        // bottom up approach recurision
        int maxside =0;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                maxside = max(maxside, f(i, j, dp));
            }
        }
        return maxside * maxside;
    }
};