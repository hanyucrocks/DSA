class Solution {
public:
    int numOfWays(int n) {
        long long aba =6;
        long long abc = 6;
        const int mod = 1e9+7;
        for(int i = 2; i <= n; i++){
            long long new_aba = (2*abc + 3*aba) % mod;
            long long new_abc = (2*abc + 2*aba) % mod;
            abc = new_abc;
            aba = new_aba;
        }
        return (abc + aba ) % mod;
    }
};