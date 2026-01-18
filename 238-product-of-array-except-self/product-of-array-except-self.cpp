class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // prefix - 24 12 4 1, sufffix - 1 1 2 6
        // max 24 12 8 6
        vector<int> pref(n), suff(n);
        pref[0] = 1;
        suff[n-1] = 1;
        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1] * nums[i-1];
        }
        // pref 1 1 2 6
        for(int i = n - 2; i>=0; i--){
            suff[i] = suff[i+1] * nums[i+1];
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = pref[i] * suff[i];
        }
        return ans;
    }
};