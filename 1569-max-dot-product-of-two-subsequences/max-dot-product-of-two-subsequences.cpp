class Solution {
public:
    int f(int ind1, int ind2, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp){
        int n = nums1.size();
        int m = nums2.size();
        if(ind1 == n or ind2 == m) return -1e9;
        if(dp[ind1][ind2] != -1e9) return dp[ind1][ind2];
        /// for each ind1 and ind2
        int product = nums1[ind1] * nums2[ind2];
        int take = max(product, product + f(ind1+1, ind2+1, nums1, nums2, dp));
        // if this can find better....
        // skipping
        int skip1 = f(ind1+1, ind2, nums1, nums2, dp);
        int skip2 = f(ind1, ind2+1, nums1, nums2, dp);
        return dp[ind1][ind2] = max({take, skip1, skip2});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1e9));
        /*
        same length ka hona chahiye, the subsequemce
        
        */
        return f(0, 0, nums1, nums2, dp);
    }
};