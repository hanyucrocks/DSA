class Solution {
public:
    vector<vector<int>> dirs = {{+1, 0}, {-1, 0},  {0, +1},  {0, -1},
                                {1, 1},  {-1, -1}, {+1, -1}, {-1, +1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 or grid[n - 1][n - 1] == 1)
            return -1;
        // src is 0, 0, dest is n - 1, n - 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        // thats the intro
        int steps = 1;
        grid[0][0] = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();
                if (r == n - 1 and c == n - 1)
                    return steps;
                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if(nr >= 0 and nr < n and nc >= 0 and nc < n and grid[nr][nc] == 0){
                        q.push({nr, nc});
                        grid[nr][nc] = 1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};