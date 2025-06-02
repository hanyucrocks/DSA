class Solution {
public:
    int f(int ind, int prevind, vector<int> &arr, int n, vector<vector<int>> &dp){
        if (ind == n) return 0;
        if(dp[ind][prevind+1]!=-1) return dp[ind][prevind+1];
        int len = 0 + f(ind+1, prevind, arr, n ,dp);
        // take
        if(prevind == -1 || arr[ind] > arr[prevind]){
            len = max(len, 1 + f(ind+1, ind, arr, n, dp));
        }
        return dp[ind][prevind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));

        return f(0, -1, nums, n, dp);
    }
};