class Solution {
public:
    int mod = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int mx = *max_element(nums.begin(), nums.end());
        int size = 2*mx+5;
        vector<int> freqnext(size, 0), freqprev(size, 0);
        for(int x : nums){
            freqnext[x]++;
        }
        for(int j = 0; j < n; j++){
            long long cur = nums[j];
            freqnext[cur]--; // next cannot be used now
            long long target = cur * 2;
            if(target < size){
            long long left = 0, right =0;
             left = freqprev[target];
            right = freqnext[target];
            ans += (left % mod) * (right % mod) % mod;
            }
            freqprev[cur]++;
        }
        return (int)(ans % mod);
    }
};