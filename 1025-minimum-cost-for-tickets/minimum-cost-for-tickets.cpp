class Solution {
public:
    int f(int i, vector<int> &days, vector<int> &costs, vector<int>&dp){
        if(i == days.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int cost1 = costs[0] + f(i+1, days, costs, dp);
        // 7day
        int j = i;
        while(j < days.size() and days[j] <= days[i] + 6) j++;
            int cost7 = costs[1] + f(j, days, costs, dp);
        // 30days
         j = i;
        while(j < days.size() and days[j] <= days[i] + 29) j++;
        int cost30 = costs[2] + f(j, days, costs, dp);
    return dp[i] = min({cost1, cost7, cost30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // 1 day is 2 rs, 7 day is 7 rs, 30 days is 15 rupees
        // each day is an integer from 1 to 365
        int n = days.size();
        vector<int> dp(n, -1);
        return f(0, days, costs, dp);
    }
};