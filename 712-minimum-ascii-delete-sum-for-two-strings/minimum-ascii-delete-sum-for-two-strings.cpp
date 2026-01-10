class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        int n = s1.size();
        int m = s2.size();
        if(i == n){
            int sum = 0;
            for(int k = j; k < m; k++){
                sum += s2[k];
            }
            return sum;
        }
        if(j == m){
            int sum = 0;
            for(int k = i; k < n; k++){
                sum += s1[k];
            }
            return sum;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = f(i+1,  j+1, s1, s2, dp);
        else{
            return dp[i][j] = min(s1[i] + f(i+1, j, s1, s2, dp), s2[j] + f(i, j+1, s1, s2, dp));
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return f(0, 0, s1, s2, dp);
    }
};