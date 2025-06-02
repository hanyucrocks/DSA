class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        // Min-heap: {effort, {row, col}}
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>>
        pq;

        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [diff, pos] = pq.top();
            pq.pop();
            int row = pos.first;
            int col = pos.second;

            if (row == n - 1 && col == m - 1) return diff;

            for (auto [dx, dy] : directions) {
                int nr = row + dx;
                int nc = col + dy;

                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int newEffort = max(diff, abs(heights[row][col] - heights[nr][nc]));

                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return 0;  
    }
};
