class Solution {
public:
    // long long f(int ind, int state, int k, vector<int> &prices, vector<vector<vector<long long>>> &dp){
    //     int n = prices.size();
    //     if(ind == n){
    //         if(state == 0) return 0;
    //         return -1e18;
    //     }
    //     if(k ==0 and state != 0) return -1e18;
    //     if(dp[ind][state][k] !=-1) return dp[ind][state][k];
    //     // now 3 states, flat, long and short
    //     long long profit = 0;
    //     if(state == 0){
    //         profit = max({f(ind+1, 0, k, prices, dp), -prices[ind]+ f(ind+1, 1, k, prices, dp), +prices[ind] + f(ind+1, 2, k, prices, dp)});
    //     }
    //     else if(state == 1){
    //         profit = max(f(ind+1, 1, k, prices, dp), prices[ind] + f(ind+1, 0, k-1,prices, dp));
    //     }
    //     else{
    //         profit = max(f(ind+1, 2, k, prices, dp), -prices[ind] + f(ind+1, 0, k-1, prices, dp));
    //     }
    //     return dp[ind][state][k] = profit;
    // }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        const long long neg = -1e18;
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>> (3, vector<long long> (k+1, 0)));
        for(int t=0; t<=k; t++){
            dp[n][0][t] = 0;
            dp[n][1][t] = neg;
            dp[n][2][t] = neg;
        }
        for(int i = n -1; i>=0; i--){
            for(int t=1; t <= k; t++){
                // state 0, hold flat
                dp[i][0][t] = max({dp[i+1][0][t], -prices[i] + dp[i+1][1][t], +prices[i] + dp[i+1][2][t]});
                dp[i][1][t] = max(dp[i+1][1][t], prices[i] + dp[i+1][0][t-1]);
                dp[i][2][t] = max(dp[i+1][2][t], -prices[i] + dp[i+1][0][t-1]);
            }
        }
        return dp[0][0][k];
    }
};