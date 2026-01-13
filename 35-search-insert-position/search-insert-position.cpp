class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        // what target ughj
        int low = 0, high = n - 1;
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                return mid;
                break;
            }
            else if(nums[mid] > target){
                // ans = mid;
                high = mid-1;
            }
            else{
                // ans = mid;
                low = mid+1;
            }
        }
        return low;
    }
};