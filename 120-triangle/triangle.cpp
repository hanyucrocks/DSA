class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // m = 1;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int j = 0; j < n; j++) dp[n-1][j] = triangle[n-1][j];
        for(int i = n - 2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int d = dp[i+1][j] + triangle[i][j];
                int dia = dp[i+1][j+1] + triangle[i][j];
                dp[i][j] = min(d, dia);
            }
        }
        return dp[0][0];
    }
};