class Solution {
public:
    int mod = 1e9+7;
    vector<long long> dp;
    long long f(int n){
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;
        if(dp[n]!=-1) return dp[n];
        long long ans = (2LL * f(n-1) % mod + f(n-3) % mod) % mod;
        return dp[n] = ans;
    }
    int numTilings(int n) {
        dp.assign(n+1, -1);
        return f(n) % mod;

    }
};