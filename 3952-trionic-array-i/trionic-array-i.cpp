class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        // first increasing
        for(int i = 1; i < n - 1; i++){
            for(int j = i + 1; j < n - 1; j++){
                bool ok = true;
                for(int k = 0; k < i; k++){
                    if(nums[k] >= nums[k+1]){
                        ok = false;
                        break;
                    }
                }
                for(int k = i; k < j and ok; k++){
                    if(nums[k] <= nums[k+1]){
                        ok = false;
                        break;
                    }
                }
                for(int k = j; k < n - 1 and ok; k++){
                    if(nums[k] >= nums[k+1]){
                        ok = false;
                        break;
                    }
                }
            if(ok) return true;
            }
        }
        return false;
    }
};