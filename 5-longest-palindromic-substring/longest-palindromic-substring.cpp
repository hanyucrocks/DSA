class Solution {
public:
    bool solve(int l, int r, string &s, vector<vector<int>> &dp){
        if(l >= r) return 1;
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l] == s[r]) return dp[l][r] = solve(l+1, r-1, s, dp);
        return dp[l][r] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int maxlen = 0;
        int start = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(i, j, s, dp) && (j-i+1 > maxlen)){
                    maxlen = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};