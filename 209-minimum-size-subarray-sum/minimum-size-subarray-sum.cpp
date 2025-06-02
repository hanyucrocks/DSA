class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int sum = 0;
        int minLen = INT_MAX;
        int n = nums.size();
        while(r < n){
            sum += nums[r];
            while(sum >= target){
                minLen = min(minLen, r - l +1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};