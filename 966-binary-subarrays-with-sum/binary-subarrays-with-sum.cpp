class Solution {
public:
    int helper(vector<int>& nums, int goal) {
        int l = 0, r = 0, sum = 0, cnt = 0;
        int n = nums.size();
        while(r < n){
            if(goal < 0) return 0;
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal){
        return helper(nums, goal) - helper(nums, goal - 1);
    }
};