class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long base = 0;
        for(int i = 0;i<n;i++){
            base += 1LL*prices[i]*strategy[i];
        }
        vector<long long> g0(n), g1(n);
        for(int i = 0; i < n; i++){
            g0[i] = -1LL*strategy[i]*prices[i];
            g1[i] = 1LL*prices[i] - 1LL*strategy[i]*prices[i];
        }
        long long left =0, right = 0;
        for(int i = 0; i < k/2; i++) left += g0[i];
        for(int i = k / 2; i < k; i++) right += g1[i];
        long long bestgain = left+right;
        for(int i = 0; i + k<n;i++){
            left += g0[i+k/2] - g0[i];
            right += g1[i+k] - g1[i+k/2];
            bestgain = max(bestgain, left+right);
        }
        return base + max(0LL, bestgain);
    }
}; 