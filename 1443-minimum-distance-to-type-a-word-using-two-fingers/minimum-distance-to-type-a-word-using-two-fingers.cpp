class Solution {
    int dp[300][27][27];
public:

    int dist(int &a, int &b){
        if(a == 26) return 0;
        int r1 = a/6, c1 = a%6;
        int r2 = b/6, c2 = b%6;
        return abs(r1-r2) + abs(c1-c2);
    }
    int f(int k, int f1, int f2, string &word){
        if(k == word.size()) return 0;
        if(dp[k][f1][f2] != -1) return dp[k][f1][f2];
        int curr = word[k] - 'A';
        int use1 = dist(f1, curr) + f(k+1, curr, f2, word);
        int use2 = dist(f2, curr) + f(k+1, f1, curr, word);
        return dp[k][f1][f2] = min(use1, use2);
    }
    int minimumDistance(string word) {
        int n = word.size();
        // then they know..... they know.....
        memset(dp, -1, sizeof(dp));
        return f(0, 26, 26, word);
    }
};