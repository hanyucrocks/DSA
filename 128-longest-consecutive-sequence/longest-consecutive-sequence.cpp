class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        int longest = 1;
        int cnt = 0;
        int lastsmall = INT_MIN;
        for(int i = 0; i< n; i++){
            if(nums[i]-1==lastsmall){
                cnt++;
                lastsmall = nums[i];
            }
            else if(nums[i] != lastsmall){
                cnt = 1;
                lastsmall = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};