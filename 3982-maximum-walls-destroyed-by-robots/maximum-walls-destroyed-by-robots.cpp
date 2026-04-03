class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        int n = robots.size();
        int m = walls.size();
        // yehi 4 mahine me teri life change hone wali hai
        // robots 4, distnance 3 tak uda sakta hai
        // agar wo left fire karta hai toh walls[i] == pair ka left and pair ka
        // right would be the robot ka value
        sort(walls.begin(), walls.end());
        // clipped by nearest robots
        vector<pair<int, int>> range;
        vector<pair<int, int>> cnt;
        vector<int> L(n), R(n);
        // robots + distance pair
        for (int i = 0; i < n; i++)
            range.push_back({robots[i], distance[i]});
        sort(range.begin(), range.end());
        for (int i = 0; i < n; i++) {
            int pos = range[i].first;
            int dist = range[i].second;
            int leftbound = pos - dist;
            if (i > 0)
                leftbound = max(leftbound, range[i - 1].first + 1);
            int rightbound = pos + dist;
            if (i < n - 1)
                rightbound = min(rightbound, range[i + 1].first - 1);
            L[i] = leftbound;
            R[i] = rightbound;
            int leftwalls = 0, rightwalls = 0;
            if (leftbound <= pos)
                leftwalls = upper_bound(walls.begin(), walls.end(), pos) -
                            lower_bound(walls.begin(), walls.end(), leftbound);
            if (rightbound >= pos)
                rightwalls =
                    upper_bound(walls.begin(), walls.end(), rightbound) -
                    lower_bound(walls.begin(), walls.end(), pos);
            cnt.push_back({leftwalls, rightwalls});
        }
        vector<int> overLap(n, 0);
        for (int i = 1; i < n; i++) {
            if(L[i] <= range[i].first and R[i - 1] >= range[i-1].first + 1){
            int overLapL = max(range[i - 1].first + 1, L[i]);
            int overLapR = min(R[i - 1], range[i].first);
            if (overLapL <= overLapR)
                overLap[i] = upper_bound(walls.begin(), walls.end(), overLapR) -
                             lower_bound(walls.begin(), walls.end(), overLapL);
            }
        }
        // Here DP
        vector<vector<int>> dp(n, vector<int>(2, 0));
        // dp[n][2];
        dp[0][0] = cnt[0].first;  // left
        dp[0][1] = cnt[0].second; // right
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0] + cnt[i].first,
                           dp[i - 1][1] + cnt[i].first - overLap[i]);
            dp[i][1] =
                max(dp[i - 1][0] + cnt[i].second, dp[i - 1][1] + cnt[i].second);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};