class Solution {
public:
    int f(int i, string &s, vector<int> &dp){
        if(i==s.size())  return 1;
        if(s[i] == '0') return 0;
        if(dp[i]!=-1) return dp[i];
        int ways = f(i+1, s, dp);
        if(i+1<s.size()){
            int two_digit = (s[i] - '0') * 10 + (s[i+1] - '0');
            if(two_digit >= 10 && two_digit <= 26){
                ways += f(i+2, s, dp);
            }
        }
        return dp[i] = ways;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dp);
    }
};