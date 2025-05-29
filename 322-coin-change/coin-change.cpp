class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, 1e9));
        // base case is if amt == 0, then take all
       for (int i = 0; i <= amount; i++) {
    if (i % coins[0] == 0) dp[0][i] = i / coins[0];
}

        if(coins[0] <= amount) dp[0][coins[0]] = 1;
        for(int i= 1; i < n; i++){
            for(int sum = 0; sum <= amount; sum++){
                int nottake = dp[i-1][sum];
                int take = INT_MAX;
                if(coins[i] <= sum) take = 1+ dp[i][sum-coins[i]];
                dp[i][sum] = min(take, nottake);
            }
        }
        return dp[n-1][amount] >= 1e9 ? -1 : dp[n-1][amount];
    }
};