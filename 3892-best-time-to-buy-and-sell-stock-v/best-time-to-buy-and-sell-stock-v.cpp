class Solution {
public:
    long long f(int ind, int state, int k, vector<int> &prices, vector<vector<vector<long long>>> &dp){
        int n = prices.size();
        if(ind == n){
            if(state == 0) return 0;
            return -1e18;
        }
        if(k ==0 and state != 0) return -1e18;
        if(dp[ind][state][k] !=-1) return dp[ind][state][k];
        // now 3 states, flat, long and short
        long long profit = 0;
        if(state == 0){
            profit = max({f(ind+1, 0, k, prices, dp), -prices[ind]+ f(ind+1, 1, k, prices, dp), +prices[ind] + f(ind+1, 2, k, prices, dp)});
        }
        else if(state == 1){
            profit = max(f(ind+1, 1, k, prices, dp), prices[ind] + f(ind+1, 0, k-1,prices, dp));
        }
        else{
            profit = max(f(ind+1, 2, k, prices, dp), -prices[ind] + f(ind+1, 0, k-1, prices, dp));
        }
        return dp[ind][state][k] = profit;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (3, vector<long long> (k+1, -1)));
        return f(0, 0, k, prices, dp);
    }
};