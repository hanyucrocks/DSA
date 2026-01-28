class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if(k >0 and grid[0][0] >= grid[m-1][n-1]) return 0;
        vector<array<int, 3>> cells;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cells.push_back({grid[i][j], i, j});
            }
        }
        sort(cells.begin(), cells.end(),
        [](auto &a, auto &b){
            return a[0] < b[0];
        });
        vector<vector<vector<int>>> dist(m, vector<vector<int>> (n, vector<int> (k+1, 1e9)));
        dist[0][0][0] = 0;
        vector<int> ptr(k+1,0);
        priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> pq;
        pq.push({0, 0, 0, 0});
        int dirs[2][2] = {{1, 0}, {0, 1}};
        while(!pq.empty()){
            auto [cost, i, j, t] = pq.top();
            pq.pop();
            if(cost > dist[i][j][t]) continue;
            if(i ==m-1 and j == n-1) return cost;
            for(auto &d : dirs){
                int ni = i + d[0];
                int nj = j + d[1];
                if(ni >= 0 and ni < m and nj >= 0 and nj < n){
                    int newCost = cost + grid[ni][nj];
                    if(newCost < dist[ni][nj][t]){
                        dist[ni][nj][t] = newCost;
                        pq.push({newCost, ni, nj, t});
                    }
                }
            }
            if(t < k){
                int V=grid[i][j];
                while(ptr[t] < (int)cells.size() and cells[ptr[t]][0] <= V){
                    int x = cells[ptr[t]][1];
                    int y = cells[ptr[t]][2];
                    if(cost < dist[x][y][t+1]){
                        dist[x][y][t+1] = cost;
                        pq.push({cost, x, y, t+1});
                    }
                    ptr[t]++;
                }
            }
        }
        int ans = 1e9;
        for(int t = 0; t <= k; t++){
            ans = min(ans, dist[m-1][n-1][t]);
        }
        return ans;
    }
};