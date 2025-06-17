class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // hamesha choose the smallest number and change its polarity
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(nums[i] < 0 && k > 0){
                nums[i] = -nums[i];
                k--;
            }
        }
        // if k is still odd, we need to flip the smallest number
        if(k % 2 == 1){
            int mini = *min_element(nums.begin(), nums.end());
            for(int i = 0; i < n; i++){
                if(nums[i] == mini){
                    nums[i] = -nums[i];
                    break;
                }
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};