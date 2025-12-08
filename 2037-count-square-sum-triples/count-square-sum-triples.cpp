class Solution {
public:
    int countTriples(int n) {
        // sqrt
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                long long sum = 1LL*i*i + 1LL*j*j;
                int c = (int)sqrt(sum);
                if(1LL*c*c ==sum and c <= n) ans++;
            }
        }
        return ans;
    }
};