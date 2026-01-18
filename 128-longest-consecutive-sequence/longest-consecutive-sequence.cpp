class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int maxi = INT_MIN;
        int ans = 1;
        sort(nums.begin(), nums.end());
        // 0 0 1 2 3 4 5 6 7 8 
        int current = 1;
        for(int i = 0; i < n - 1; i++){
            if(nums[i+1] - nums[i] ==1){
                current++;
                ans = max(ans, current);
            }
            if(nums[i+1] - nums[i] > 1){
                current = 1;
                ans = max(ans, current);
            }
        }
        return ans;
    }
};