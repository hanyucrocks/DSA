class Solution {
    int dp[1001][1001];
public:
    int f(int i, int j, vector<vector<int>> &dungeon){
        // bottom right pe raani, top left pe raaja
        int m = dungeon.size();
        int n = dungeon[0].size();
        // if(i < 0 or j < 0) return 0;
        if(i >= m or j >= n) return 1e9;
        if(i == m - 1 and j == n -1) return max(1, 1 - dungeon[i][j]);
        if(dp[i][j] != -1) return dp[i][j];
        int right = f(i+1, j, dungeon);
        int down = f(i, j +1, dungeon);
        int need = min(right, down) - dungeon[i][j];
        return dp[i][j] = max(1, need);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // rreturn f + 1
        memset(dp, -1, sizeof(dp));
        return f(0, 0, dungeon);
    }
};