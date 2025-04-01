class Solution {
public:
    int func(vector<int> &nums, int mid){
       int th = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            th += ceil((double)nums[i]/(double)mid);
        }
        return th;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1;
        int high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid = (low + high)/2;
            int tt = func(nums, mid);
            if( tt <= threshold) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};