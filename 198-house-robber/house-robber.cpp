class Solution {
public:
    int f(int ind, vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        // take or not take
        int take = nums[ind] + f(ind+2, nums, dp);
        int nottake = f(ind+1, nums, dp);
        return dp[ind] = max(take, nottake);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, -1);
        return f(0, nums, dp);
    }
};