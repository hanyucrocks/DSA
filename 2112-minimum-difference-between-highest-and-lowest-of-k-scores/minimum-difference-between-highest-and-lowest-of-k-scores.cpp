class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // k
        int mini = INT_MAX;
        for(int i= 0; i < n - k + 1; i++){
            int diff = nums[i+k-1] - nums[i];
            mini = min(mini, diff);
        }
        return mini;
    }
};