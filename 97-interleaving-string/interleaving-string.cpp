class Solution {
public:
    int f(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        if(i == s1.size() && j == s2.size()) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int k = i +j;
        bool ans = false;
        if(i < s1.size() &&s1[i]==s3[k]) ans |= f(i+1, j, s1, s2, s3, dp);
        if(j < s2.size() && s2[j] == s3[k]) ans |= f(i, j+1, s1, s2, s3, dp);
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int z = s3.size();
        if(n + m != z) return false;
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return f(0, 0, s1, s2, s3, dp);
    }
};