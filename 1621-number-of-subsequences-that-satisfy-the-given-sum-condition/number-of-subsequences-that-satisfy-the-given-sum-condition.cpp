class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 +7;
        int n = nums.size();
        vector<int> pow2(n, 1);
        for(int i = 1; i < n; i++) pow2[i] = pow2[i] = (pow2[i-1]*2) % MOD; 
        sort(nums.begin(), nums.end());
        int low = 0, high = n - 1;
        int count = 0;
        while(low <= high){
            if(nums[low] + nums[high] <= target){
                count = (count + pow2[high-low]) % MOD;
                low++;
            }
            else high--;

        }
        return count;
    }
};