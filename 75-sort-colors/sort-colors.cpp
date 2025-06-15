class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        // int cnt0 = 0, cnt1=0, cnt2=0;
        // for(int i = 0; i < n; i++){
        //     if(nums[i]==0) cnt0++;
        //     else if(nums[i]==1) cnt1++;
        //     else cnt2++;
        // }
        // // int ind = 0;
        // // now, just loop and overwrite
        // for(int i = 0; i < cnt0; i++) nums[i] = 0;
        // for(int i = cnt0; i < cnt0 + cnt1; i++) nums[i] = 1;
        // for(int i = cnt0 + cnt1; i < cnt0 +cnt1 + cnt2; i++) nums[i] = 2;

        // DNF Dutch National Flag
        int low = 0, mid = 0, high = n - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1) mid++;
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};