class Solution {

int lcs(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        // bottom up - O to n - 1
        for(int j = 0; j <= m; j++) dp[0][j] = 0;
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    return dp[n][m];
}
public:
    int minDistance(string word1, string word2) {
      // what can i not touch
      // abcd and anc, 2 steps for making both ac
      return word1.size() + word2.size() - 2 * lcs(word1, word2);
    }
};