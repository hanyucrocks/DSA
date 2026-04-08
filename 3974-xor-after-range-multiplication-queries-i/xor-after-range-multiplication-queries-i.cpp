class Solution {
public:
    const int mod = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        // what whaaaat
        for(auto &q : queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            int idx = l;
            while(idx <= r){
                nums[idx] = (1LL * nums[idx] * v) % mod;
                idx += k;
            }
        }
        int res = 0;
        for(int x : nums){
            res ^= x;
        }
        return res;
    }
};