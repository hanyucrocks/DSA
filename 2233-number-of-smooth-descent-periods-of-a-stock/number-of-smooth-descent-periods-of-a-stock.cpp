class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        // matlab answer + n toh kar hi dena
        // two pointers sliding window
        // 0 to k then k se n...
        long long len = 1;
        long long ans = 1;
        for(int i = 1; i < n; i++){
            if(prices[i-1] - prices[i] == 1){
                len++;
                ans += len;
            }
            else{
                len = 1;
                ans += len;
            }
        }
        return ans;
    }
};