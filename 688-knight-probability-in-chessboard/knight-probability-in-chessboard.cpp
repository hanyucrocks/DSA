class Solution {
public:
    vector<vector<int>> dirs = {
    {-2,-1}, {-2,1},
    {2,-1},  {2,1},
    {-1,-2}, {-1,2},
    {1,-2},  {1,2}
};
    double dp[26][26][101];

    double f(int n, int k, int r, int c){
        if(r < 0 or r >= n or c < 0 or c >= n) return 0;
        if(k==0) return 1;
        if(dp[r][c][k] != -1) return dp[r][c][k];
        double res = 0;
        for(auto dir : dirs){
            int newrow = r + dir[0];
            int newcol = c + dir[1];
            res += f(n, k - 1, newrow, newcol);
        }
        return dp[r][c][k] = res / 8.0;
    }
    double knightProbability(int n, int k, int row, int column) {
        /*
        for every [r, c] the directions are
        all 8 dirs are
        r+2, c+1
        r+1, c+2
        r-1, c+2
        r-2, c+2
        r-2, c-2
        r-1, c-1
        r+1, c-2
        r+2, c-1
        
        */
        for(int i = 0; i < 26; i++){
    for(int j = 0; j < 26; j++){
        for(int l = 0; l < 101; l++){
            dp[i][j][l] = -1.0;
        }
    }
}
        return f(n, k, row, column);
    }
};