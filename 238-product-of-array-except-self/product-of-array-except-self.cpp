class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // prefix - 24 12 4 1, sufffix - 1 1 2 6
        // max 24 12 8 6
        vector<int> ans(n);
        ans[0] = 1;
        for(int i = 1; i < n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        int rightprod = 1;
        for(int i = n - 1; i >=0 ; i--){
            ans[i] *= rightprod;
            rightprod *= nums[i];
        }
        return ans;
    }
};