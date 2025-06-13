class Solution {
public:
    int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for(int k = i; k <= j; k++){
            int steps = arr[i-1] * arr[k] * arr[j+1] + f(i, k-1, arr, dp) + f(k+1, j, arr, dp);
            maxi = max(maxi, steps);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));
        for(int i = n; i >= 1; i--){
            for(int j = 1; j <= n; j++){
                if(i > j) continue;
                int maxi = INT_MIN;
        for(int k = i; k <= j; k++){
            int steps = nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j];
            maxi = max(maxi, steps);
        }
        dp[i][j] = maxi;
            }
        }
        // return f(1, n, arr, dp);

    return dp[1][n];
    }
};