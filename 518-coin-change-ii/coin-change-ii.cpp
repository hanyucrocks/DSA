#define ull unsigned long long

vector<vector<ull>> dp;
class Solution {
public:
    ull change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n+1, vector<ull> (amount+1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int sum = 0; sum <= amount; sum++){
                ull nottake = dp[i-1][sum];
                ull take = 0;
                if(sum >= coins[i-1]){
                    take = dp[i][sum-coins[i-1]];
                }
                dp[i][sum] = (take + nottake);
            }
        }
        return dp[n][amount];
    }
};