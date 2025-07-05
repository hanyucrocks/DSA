class Solution {
public:
    int f(int ind, vector<int> &nums, vector<int> &dp){
        if(ind == 0) return nums[0];
        if(ind == 1) return max(nums[0], nums[1]);
        if(ind < 0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick = nums[ind] + f(ind-2, nums, dp);
        int notpick = f(ind-1, nums, dp);
        return dp[ind] = max(pick, notpick);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal + 1, 0);
        for(int x : nums) points[x] += x;
        vector<int> dp(maxVal+1, -1);
        return f(maxVal, points, dp);

    }
};