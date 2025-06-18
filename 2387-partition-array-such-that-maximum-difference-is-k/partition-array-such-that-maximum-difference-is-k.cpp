class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 1;
        int start = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[start] > k){
                count++;
                start=i;
            }
        }
        return count;
    }
};