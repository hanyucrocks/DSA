class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minPrice = nums[0];
        int maxDiff = -1;
        for(int i = 1; i < n; i++){
            if(nums[i] > minPrice){
                maxDiff = max(maxDiff, nums[i] - minPrice);
            }
            else minPrice = nums[i];
        }
        return maxDiff;
    }
};