class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    if(j < 0) return i + 1;
    if(i < 0) return j + 1;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){
        return dp[i][j] = f(i-1, j-1, s1, s2, dp);
    } else {
        int ins = 1 + f(i, j-1, s1, s2, dp);     // insert
        int del = 1 + f(i-1, j, s1, s2, dp);     // delete
        int rep = 1 + f(i-1, j-1, s1, s2, dp);   // replace
        return dp[i][j] = min({ins, del, rep});
    }
}

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;
        // base cases done
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int ins = 1+dp[i][j-1];
                    int del = 1+dp[i-1][j];
                    int rep = 1+dp[i-1][j-1];
                    dp[i][j] = min({ins, del, rep});
                }
            }
        }
        return dp[n][m];
    }
};