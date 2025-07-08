class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // intuitionn linear search
        int ans = 0;
        for(int i = 1; i < n; i++){
            if((i == 0 || nums[i] > nums[i-1]) and (i == n - 1 || nums[i] > nums[i+1]) )ans = i;
        }
        return ans;
    }
};