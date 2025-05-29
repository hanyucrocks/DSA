class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> arr(maxi + 1, 0);
        for(int i = 0; i < n; i++){
            arr[nums[i]]++;
        }
        for(int i = 1; i <= maxi; i++){
            arr[i] += arr[i-1];
        }
        vector<int> output(n);
        for(int i = n - 1; i >= 0; i--){
            output[arr[nums[i]] - 1] = nums[i];
            arr[nums[i]]--;
        }
        nums = output;
    }
};