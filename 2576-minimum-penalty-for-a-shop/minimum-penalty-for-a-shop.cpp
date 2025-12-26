class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        string s = customers;
        /*
        ye kya hora hai bc
        Y -> ith hour me koi aaya hai
        N no customers
        jth hour me band hua j -> 0 to n - 1
        if N when shop open, penalty++
        if Y when shop closed, penalty++
        close it at the nearest N, if No N's then close hi mat karo.
        NNYNN
        122
        */
        int mini = INT_MAX;
        int ans = 0;
        vector<int> prefix(n+1, 0), suffix(n+1, 0);
        // prefix[0] = (s[0] == 'N');
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + (s[i] == 'N');
        }
        // suffix[n-1] = (s[n-1] == 'Y');
        for(int i = n - 1; i >= 0; i--){
            suffix[i] = suffix[i+1] + (s[i] == 'Y');
        }
        for(int i = 0; i <= n; i++){
            int penalty = prefix[i] + suffix[i];
            if(penalty <mini){
                mini = penalty;
                ans = i;
            }
        }
        return ans;
    }
};