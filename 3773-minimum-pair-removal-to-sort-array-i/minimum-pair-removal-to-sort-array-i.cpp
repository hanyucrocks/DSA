class Solution {
public:
    bool isSorted(vector<int> &nums){
        int n = nums.size();
        for(int i=1; i < n; i++){
            if(nums[i] < nums[i-1]){
                return false;
            }
        }
        return true;
    }
    int findminPair(vector<int> &nums){
        int n = nums.size();
        int ops = 0;
        int minSum = INT_MAX;
        int minIdx = -1;
        for(int i =0; i < n - 1; i++){
            if(nums[i] + nums[i+1] < minSum){
                minSum = nums[i]+nums[i+1];
                minIdx = i;
            }
        }
        nums[minIdx] = nums[minIdx] + nums[minIdx + 1];
        nums.erase(nums.begin() +minIdx+1);
        return ops;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        while(!isSorted(nums)){
            // find the pair
            // merge it
            //ops++;
            findminPair(nums);
            ops++;
        }
        return ops;
    }
};