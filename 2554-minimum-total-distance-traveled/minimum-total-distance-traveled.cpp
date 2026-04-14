class Solution {
    long long dp[1001][1001];

public:
    long long f(int i, int j, vector<int> &robot, vector<vector<int>> &factory){
        if(i == robot.size()) return 0; // all robots are fixed, end wala robot
        if(j == factory.size()) return 1e18; // no factories leftr;
        if(dp[i][j] != -1) return dp[i][j];
        // option1 skip
        long long ans = 1e18;
        ans = f(i, j + 1, robot, factory);
        long long cost = 0;
        int pos = factory[j][0];
        int lim = factory[j][1];
        for(int k = 1; k <= lim and i + k - 1 < robot.size(); k++){
            cost += abs(robot[i+k-1] - pos);
            ans = min(ans, cost + f(i + k, j + 1, robot, factory));
        }
        return dp[i][j] = ans;

    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // pos, limit, pos is the position and jth factory can repear at most limitj robots.
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end()); // sort both
        memset(dp, -1, sizeof(dp));
        return f(0, 0, robot, factory);
    }
};