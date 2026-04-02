class Solution {
public:
    const int capper = -1e9 - 5;
    int f(int i, int j, int k, vector<vector<int>>& coins,
          vector<vector<vector<int>>>& dp) {
        int m = coins.size();
        int n = coins[0].size();
        if (i >= m or j >= n)
            return INT_MIN;
        if (dp[i][j][k] != capper)
            return dp[i][j][k];
        if (i == m - 1 and j == n - 1) {
            if (coins[i][j] >= 0)
                return coins[i][j];
            if (k > 0)
                return 0;
            return coins[i][j];
        }
        int down = f(i + 1, j, k, coins, dp);
        int right = f(i, j + 1, k, coins, dp);
        int best = max(down, right);
        if (coins[i][j] >= 0) {
            if (best == INT_MIN)
                return dp[i][j][k] = INT_MIN;
            return dp[i][j][k] = coins[i][j] + best;
        }
        int take;
        if (best == INT_MIN)
            take = INT_MIN;
        else
            take = coins[i][j] + best;

        if (k > 0) {
            int down2 = f(i + 1, j, k - 1, coins, dp);
            int right2 = f(i, j + 1, k - 1, coins, dp);
            int skip = max(down2, right2);

            return dp[i][j][k] = max(take, skip);
        } else {
            return dp[i][j][k] = take;
        }
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        // ughhhhhhhhhh taps ours
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, capper)));
        return f(0, 0, 2, coins, dp);
    }
};