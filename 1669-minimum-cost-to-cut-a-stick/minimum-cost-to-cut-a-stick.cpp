class Solution {
public:
    // 1 3 4 5
    // 0 1 3 4 5 7
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i > j) return 0;
        int mini = INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int ind = i; ind <= j; ind++){
            int cost = cuts[j+1] - cuts[i-1] + f(i, ind-1, cuts, dp) + f(ind+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        // hamesha ans woudl start from 7
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int> (c, -1));
        return f(1, c-2, cuts, dp);
    }
};