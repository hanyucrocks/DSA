class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int cur = 0;
        for(int i = 0; i < k; i++){
            cur += nums[i];
        }
        ans = cur;
        for(int i = k; i < n; i++){
            cur += nums[i] - nums[i-k];
            ans = max(ans, cur);
        }
        return (double)ans/k;
    }
};