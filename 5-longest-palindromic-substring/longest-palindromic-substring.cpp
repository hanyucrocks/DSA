class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        if(n==0) return "";
        int start = 0, maxLen = 1;
        for(int i = 0; i < n; i++) dp[i][i] = 1;
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1]=true;
                start = i;
                maxLen = 2;
            }
        }
        for(int i = 3; i <= n; i++){
            for(int j = 0; j <= n - i; j++){
                int k = j + i - 1;
                if(s[j] == s[k] && dp[j+1][k-1]){
                    dp[j][k] = true;
                    start = j; maxLen = i;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};