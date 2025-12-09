class Solution {
public:
    int mod = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<long long, long long> freqprev, freqnext;
        for(int x : nums){
            freqnext[x]++;
        }
        for(int j = 0; j < n; j++){
            long long cur = nums[j];
            freqnext[cur]--; // next cannot be used now
            long long target = cur * 2;
            long long left = 0, right =0;
            if(freqprev.count(target)) left = freqprev[target];
            if(freqnext.count(target)) right = freqnext[target];
            ans += (left % mod) * (right % mod) % mod;
            freqprev[cur]++;
        }
        return (int)(ans % mod);
    }
};