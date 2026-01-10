class Solution {
public:
    int f(int ind, vector<int> &cost, vector<int> &dp){
        // minimum cost nikalna hai not maximum
        int n = cost.size();
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        // int take = cost[ind] + min(f(ind+1, cost, dp), f(ind+2, cost, dp));
        // int nottake = f(ind+1, cost, dp);
        return dp[ind] = cost[ind] + min(f(ind+1, cost, dp), f(ind+2, cost, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(f(0, cost, dp), f(1, cost, dp));
    }
};