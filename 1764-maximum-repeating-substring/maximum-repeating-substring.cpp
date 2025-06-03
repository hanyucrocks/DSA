class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        vector<int> dp(n, 0);
        int len = word.size();
        int maxCount = 0;
        for(int i = len - 1; i < n; i++){
            if(sequence.substr(i-len+1, len) == word){
                if(i - len >= 0){
                dp[i] = dp[i-len] + 1;
                }
                else dp[i] = 1;
            }
            else dp[i] = 0;
            maxCount = max(maxCount, dp[i]);
        }
        return maxCount;
    }
};