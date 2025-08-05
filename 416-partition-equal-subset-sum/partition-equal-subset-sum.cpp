class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        // target == sum / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return 0;
        int k = sum/2;
        vector<vector<bool>> dp(n, vector<bool> (k+1, 0));
        // dp[i][sum]
        for(int i = 0; i < n; i++)
            dp[i][0] = 1;
        if(nums[0] <= k)
            dp[0][nums[0]] = 1;
        for(int i = 1; i < n; i++){
            for(int target = 1; target <= k; target++){
                bool nottake = dp[i-1][target];
                bool take = false;
                if(nums[i] <= target) take = dp[i-1][target - nums[i]];
                dp[i][target] = take || nottake;
            }
        }
        return dp[n-1][k];
    }
};