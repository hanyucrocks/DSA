class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, right = 0, n = nums.size();
        int sum = 0, maxsum =0;
        while(right < n){
            if(seen.count(nums[right]) == 0){
                seen.insert(nums[right]);
                sum += nums[right];
                maxsum = max(maxsum, sum);
                right++;
            }
            else{
            seen.erase(nums[left]);
            sum -= nums[left];
            left++;
            }
        }
        return maxsum;
    }
};