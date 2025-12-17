class Solution {
public:
    int f(int idx, int buy, vector<int>&prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(idx == n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        // buy can be 0 or 1
        int profit = -1e9;
        if(buy){
            profit = max(-prices[idx] + f(idx+1, 0, prices, dp), f(idx+1, 1, prices, dp));
        }
        else // yaha pe sell hoga
        {
            profit = max(prices[idx] + f(idx+1, 1, prices, dp), f(idx+1, 0, prices, dp));
        }
        return dp[idx][buy] = profit;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, 1, prices, dp);
    }
};