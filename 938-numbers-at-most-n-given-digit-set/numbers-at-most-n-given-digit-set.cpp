class Solution {
public:
    int dp[10001][2];
    int f(int pos, int tight, vector<string> &digits, string &num){
        if(dp[pos][tight] != -1) return dp[pos][tight];
        // tight == 1, only digits <= current digit of n
        // tight == 0, pick any digit
        if(pos == num.length()) return 1; // base case
        int ans = 0;
        for(string &d : digits){
            char c = d[0];
            if(tight == 1 and c > num[pos]) continue;
            int newtight = (tight == 1 and c == num[pos]) ? 1 : 0;
            ans += f(pos+1, newtight, digits, num);
        }
        return dp[pos][tight] = ans;

    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int s = digits.size();
        string num = to_string(n);
        memset(dp, -1, sizeof(dp));
        int len = num.length();
        int total = 0;
        int curr = 1;
        for(int i = 1; i < len; i++){
            curr *= s;
            total += curr;
        }
        return total + f(0, 1, digits, num);
    }
};