class Solution {
int f(int i, vector<int> &a, vector<int> &dp){
    if(i == 0) return a[i];
    if(i < 0) return 0;
    if(dp[i]!=-1) return dp[i];
    int pick = a[i] + f(i-2, a, dp);
    int notpick = f(i -1, a, dp);
    return dp[i] = max(pick, notpick);
}
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+1, -1);
        return f(n-1, nums, dp);
    }
};