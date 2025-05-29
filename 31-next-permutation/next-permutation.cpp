class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());  lmao bruh do this
        int n = nums.size();
        // whenever nums[i] < nums[i+1] thats our break point
        /* find > 1, but the smallest one so that you stay close
        try to place remaining in sorted order

        
         */
        int ind = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1) {reverse(nums.begin(), nums.end()); return;}
        for(int i = n - 1; i >= ind; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1, nums.end());
    }
};