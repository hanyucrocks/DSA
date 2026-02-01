class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        ans += nums[0];
        sort(nums.begin() + 1, nums.end());
        ans += nums[1] + nums[2];
        return ans;
    }
};