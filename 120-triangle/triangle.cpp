class Solution {
public:
    int f(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp){
     int n = a.size();
     if(i==n-1) return a[n-1][j];
     if(dp[i][j]!=-1) return dp[i][j];
     int down = f(i+1, j, a, dp);
     int right = f(i+1, j+1, a, dp);
     return dp[i][j] = a[i][j] + min(down, right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return f(0, 0, triangle, dp);
    }
};