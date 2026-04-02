class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 10;

        int aval = 9;
        int cur = 9;
        for(int i = 2; i <= n; i++){
            cur = cur * aval;
            dp[i] = cur;
            aval--;
        }
        int ans = 0;
        for(int i = 0; i <= n; i++) ans += dp[i];
        return ans - 1; 
    }
};