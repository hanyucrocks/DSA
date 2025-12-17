class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        // 0 to k then k se n
        int sum = 0, maxi = INT_MIN;
        for(int i = 0; i <n; i++){
            sum += nums[i];
            if(nums[i] == 0) sum = 0;
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};