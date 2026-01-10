class Solution {
public:
    // int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    //     int n = s1.size();
    //     int m = s2.size();
    //     if(i == n){
    //         int sum = 0;
    //         for(int k = j; k < m; k++){
    //             sum += s2[k];
    //         }
    //         return sum;
    //     }
    //     if(j == m){
    //         int sum = 0;
    //         for(int k = i; k < n; k++){
    //             sum += s1[k];
    //         }
    //         return sum;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s1[i] == s2[j]) return dp[i][j] = f(i+1,  j+1, s1, s2, dp);
    //     else{
    //         returndp[i][j] = min(s1[i] + f(i+1, j, s1, s2, dp), s2[j] + f(i, j+1, s1, s2, dp));
    //     }
    // }
    // int ASCII(const string &s){
    //     int sum = 0;
    //     for(char c : s) sum += c;
    //     return sum;
    // }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        dp[n][m] = 0;
        // s1 exhaused so s2 is iin work
        for(int j = m -1; j >= 0; j--){
            dp[n][j] = dp[n][j+1] + (s2[j]);
        }
        // s2 exhaused
        for(int i = n - 1; i >= 0; i--){
            dp[i][m] = dp[i+1][m] + (s1[i]);
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(s1[i] == s2[j]) dp[i][j] = dp[i+1][j+1];
                else{
                    dp[i][j] = min((s1[i]) + dp[i+1][j], (s2[j]) + dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};