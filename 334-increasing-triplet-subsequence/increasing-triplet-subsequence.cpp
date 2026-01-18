class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        bool ok = false;
        int smallest = INT_MAX;
        int middle = INT_MAX;
        for(int i = 0; i < n; i++){
            // check small and update
            if(nums[i] <= smallest){
                smallest = nums[i];
            }
            else if(nums[i] <= middle){
                middle=nums[i];
            }
            else{
                ok = true;
                break;
            }
        }
        return ok;

    }
};