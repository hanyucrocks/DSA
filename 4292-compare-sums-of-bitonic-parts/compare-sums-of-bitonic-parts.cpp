class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        // left array is 0 to peak, right array is peak to n -1
        int peak = 0;
        for(int i = 0; i < n; i++){
            if((i == 0 or nums[i] >= nums[i - 1]) and (i == n - 1 or nums[i] >= nums[i + 1])){
                peak = i;
                break;
            }
        }
        long long total = 0;
        for(int x : nums) total += x;
        long long left = 0;
        for(int i = 0; i <= peak; i++) left += nums[i];
        long long right = total - left + nums[peak];
        if(left > right) return 0;
        if(left < right) return 1;
        return -1;
    }
};