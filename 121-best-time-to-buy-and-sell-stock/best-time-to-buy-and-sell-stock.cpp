class Solution {
public:
    int maxProfit(vector<int>& prices) {
     // you will try to buy it when it has minimum
     // minPrice 
     int n = prices.size();
        vector<int> dp(n);
        int mini = prices[0];
        int profit = 0;
        for(int i = 1; i < n; i++){
            mini = min(mini, prices[i]);
            dp[i] = max(dp[i-1], prices[i] - mini);
        }
        return dp[n-1];
    }
};