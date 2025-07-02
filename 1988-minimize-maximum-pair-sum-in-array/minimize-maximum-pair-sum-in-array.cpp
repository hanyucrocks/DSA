class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i= 0, j = n- 1;
        int maxsum = INT_MIN;
        while(i <= j){
            int sum = nums[i] + nums[j];
            i++;
            j--;
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};