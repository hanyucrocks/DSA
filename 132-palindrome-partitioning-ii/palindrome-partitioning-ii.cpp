class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, int n, string &s, vector<int> &dp){
        if(i == n) return -1; // -1 because we add 1 later for the current cut
        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX;
        for(int j = i; j < n; j++){
            if(isPalindrome(i, j, s)){
                int cost = 1 + f(j + 1, n, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        // vector<int> dp(n, -1);
        vector<int> dp(n+1, 0);
        // return f(0, n, s, dp);
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--){
            int mini = INT_MAX;
        for(int j = i; j < n; j++){
            if(isPalindrome(i, j, s)){
                int cost = 1 + dp[j+1];
                mini = min(mini, cost);
            }
        }
        dp[i] = mini;
        }
        return dp[0] - 1;
    }
};
