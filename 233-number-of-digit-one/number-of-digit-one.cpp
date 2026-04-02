class Solution {
public:
    int countDigitOne(int n) {
        // all postive int less than or equal to n
        // count all the numbers that has one in it,.
        if(n == 0) return 0;
        // the formula is no of digits x 10 ^ no of digits minus 1
        // how
        // digit dp[pos][tit][state][started]
        long long factor = 1;
        int ans = 0;
        while(factor <= n){
            int higher = n / (factor * 10); // 1
            int curr = (n / factor) % 10; // 3
            int lower = n % factor; // 13
            if(curr == 0) ans += higher * factor;
            else if(curr == 1) ans += higher * factor + (lower + 1);
            else ans += (higher + 1) * factor;
            factor *= 10;
        }
        return ans;
    }
};