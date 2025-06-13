class Solution {
public:
    bool canform(int x, vector<int> &nums, int p){
        int count = 0;
        int i = 0;
        int n = nums.size();
        while(i < n - 1){
            if(nums[i+1] - nums[i] <= x){
                count++;
                i+=2;
            }
            else i++;
        }

        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.back()-nums.front();
        while(low <= high){
            int mid = low + ((high-low )/ 2);
            if(canform(mid, nums, p)){
                high = mid - 1;
            }
            else low = mid+1;
        }
        return low;
    }
};