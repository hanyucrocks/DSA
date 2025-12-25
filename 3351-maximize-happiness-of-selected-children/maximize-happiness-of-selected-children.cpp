class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        /*
        happiness value of all the children that have no been selected
        sabse largest wala number uthao
        and baaki saara ko minus1 karo
        */
        long long ans = 0;
        sort(happiness.rbegin(), happiness.rend());
        for(int i = 0; i < k and i < n; i++){
            long long cur = happiness[i] - i;
            if(cur > 0) ans += cur;
        }
        return ans;
    }
};