class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 1;
        q.push({1, {0, 0}});

        int direction[8][2] = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1},
            {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
        };

        while (!q.empty()) {
            auto it = q.front(); q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == m - 1) return dis;

            for (int i = 0; i < 8; i++) {
                int newr = r + direction[i][0];
                int newc = c + direction[i][1];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m && 
                    grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]) {
                    
                    dist[newr][newc] = dis + 1;
                    q.push({dis + 1, {newr, newc}});
                }
            }
        }

        return -1;
    }
};
