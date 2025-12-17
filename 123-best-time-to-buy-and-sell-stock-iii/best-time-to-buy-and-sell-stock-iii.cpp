class Solution {
public:
    int f(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if(ind == n) return 0;
        if(cap == 0) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        // listen, ind is n, buy is 0 and 1, cap is 2 tak. cap -1 tab hoga jab B and S
        //now
        int profit = -1e9;
        if(buy) profit = max(-prices[ind] + f(ind+1, 0, cap, prices, dp), f(ind+1, 1, cap, prices, dp));
        else profit = max(prices[ind] + f(ind+1, 1, cap - 1, prices, dp), f(ind+1, 0, cap, prices, dp));
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // at most 2 transactions.... zyada se zyada do
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};