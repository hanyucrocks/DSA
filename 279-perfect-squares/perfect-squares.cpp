class Solution {
public:
    int numSquares(int n) {
        vector<int> coins;
        for(int i = 1; i <= n; i++){
            int sqr = i * i;
            if(sqr <= n){
                coins.push_back(sqr);
            }
            else break;
        }
        // for 13 coins has 1 4 9, as soon as it goes into i == 4, it breaks
        int k = coins.size();
        vector<vector<int>> dp(k, vector<int> (n +1, 0));
        for(int T = 0; T <= n; T++){
            if(T % coins[0] == 0) dp[0][T] = T / coins[0];
            else dp[0][T] = INT_MAX; 
        }
        for(int i = 1; i < k; i++){
            for(int sum = 0; sum <= n; sum++){
                int nottake = dp[i-1][sum];
                int take = INT_MAX;
                if(coins[i] <= sum){
                    take = 1 + dp[i][sum-coins[i]];
                }
                dp[i][sum] = min(take, nottake);
            }
        }
        return dp[k-1][n] >= 1e9 ? -1 : dp[k-1][n];
    }
};